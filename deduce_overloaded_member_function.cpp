#include <iostream>
#include <type_traits>
#include <functional>
#include <string>

struct X
{
    void msg(int value)
    {
        std::cout << "Int value is: " << value << '\n';
    }

    void msg(std::string value)
    {
        std::cout << "String value is: " << value << '\n';
    }

    template <typename T, typename msg_type=typename std::decay<T>::type>
    auto get_fn(const T&& value)
    {
        return static_cast<void (X::*)(msg_type)>(&X::msg);
    }
};

int main()
{
    using namespace std::string_literals;

    X obj;
    
    auto int_fn = obj.get_fn(10);
    auto str_fn = obj.get_fn("String"s);

    std::invoke(int_fn, &obj, 100);
    std::invoke(str_fn, &obj, "Hello world.");

    return 0;
}
