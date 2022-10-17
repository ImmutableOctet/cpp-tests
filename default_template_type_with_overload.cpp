#include <iostream>
#include <string>

template <typename T=void>
void reflect()
{
    std::cout << "Reflect\n";
}

template <>
void reflect<void>()
{
    std::cout << "Hello world.\n";
}

int main()
{
    reflect();
    reflect<std::string>();
}