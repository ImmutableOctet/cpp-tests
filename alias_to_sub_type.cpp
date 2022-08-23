#include <iostream>

struct X
{
    using T = int;
};

template <typename XType>
struct Y
{
    using T = typename XType::T;

    T value;
};

int main()
{
    Y<X> thing;

    thing.value = 42;

    std::cout << thing.value << std::endl;
}