#include <iostream>
#include <variant>
#include <string>

int main()
{
    bool mode = true; // false;

    using variant_t = std::variant<int, std::string>;

    //variant_t v = (mode) ? 10 : std::string("Hello world."); // Does not work.
    variant_t v = (mode) ? variant_t(10) : variant_t(std::string("Hello world.")); // Does work.

    std::cout << std::get<int>(v) << '\n';
    //std::cout << std::get<std::string>(v) << '\n';
}