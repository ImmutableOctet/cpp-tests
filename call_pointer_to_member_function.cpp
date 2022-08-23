#include <iostream>
#include <functional>

struct X
{
    int value;

    void f(int value)
    {
        std::cout << (value * this->value) << '\n';
    }
};

template <typename fn_t, typename T>
void call(fn_t&& fn, T&& t, int value)
{
    //(t->*fn)(value);
    std::invoke(fn, t, value);
}

int main()
{
    X x = { 42 };

    call(&X::f, &x, 100);

    return 0;
}
