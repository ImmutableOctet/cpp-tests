#include <iostream>
#include <string>
#include <variant>

template<typename VT, typename T, std::size_t index = 0>
constexpr std::size_t variant_index()
{
    if constexpr (index == std::variant_size_v<VT>)
    {
        return index;
    }
    else if constexpr (std::is_same_v<std::variant_alternative_t<index, VT>, T>)
    {
        return index;
    }
    else
    {
        return variant_index<VT, T, index + 1>();
    }
}

int main()
{
    using VType = std::variant<std::monostate, int, float, std::string>;
    //using VType = std::variant<std::monostate, int, float, std::string, std::string>;

    std::cout << "std::monostate: " << variant_index<VType, std::monostate>() << '\n';
    std::cout << "int: " << variant_index<VType, int>() << '\n';
    std::cout << "float: " << variant_index<VType, float>() << '\n';
    std::cout << "std::string: " << variant_index<VType, std::string>() << '\n';

    return 0;
}