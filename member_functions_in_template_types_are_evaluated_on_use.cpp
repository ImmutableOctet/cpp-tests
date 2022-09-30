#include <iostream>
#include <string>

struct Z
{
    int value;
};

struct Y : public Z
{
    inline int get_as_int() const
    {
        return value;
    }
};

struct X : public Z
{
    template <typename T>
    T get()
    {
        if constexpr (std::is_same_v<T, std::string>)
        {
            return std::to_string(value);
        }
        else
        {
            return static_cast<T>(value);
        }
    }
};

template <typename T>
struct Wrapper
{
    T& obj;

    template <typename U>
    U get() const
    {
        return obj.template get<U>();
    }

    inline int get_as_int() const
    {
        return obj.get_as_int();
    }
};
 
template <typename WrapperType>
void print_as_int(const WrapperType& w)
{
    std::cout << w.get_as_int() << '\n';
}

template <typename WrapperType>
void print_as_string(const WrapperType& w)
{
    std::cout << w.template get<std::string>() << '\n';
}

int main()
{
    X x = {42};
    Wrapper<X> w = {x};

    Y y = {123};
    Wrapper<Y> w2 = {y};

    print_as_string(w);
    //print_as_string(w2); // <-- Fails, since `Y` doesn't have `get`.

    //print_as_int(w); // <-- Fails, since `X` doesn't have `get_as_int`.
    print_as_int(w2);
    
    // If the two lines above are commented out, the template `Wrapper` still works.

    return 0;
}