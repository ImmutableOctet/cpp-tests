#include <iostream>

template <typename T>
void test(T&& value);

int main()
{
    test(100);

    return 0;
}

template <typename T>
void test(T&& value)
{
    std::cout << value << '\n';
}
