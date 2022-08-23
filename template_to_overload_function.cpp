#include <iostream>
#include <string>

template <typename T>
T fn(int value)
{
    return T(value);
}

template <>
std::string fn<std::string>(int value)
{
    return "String: " + std::to_string(value);
}

int main()
{
    //auto value = fn<std::string>(1000);
    auto value = fn<int>(1000);

    std::cout << value << std::endl;
}