#include <iostream>
#include <string>
#include <any>

int main()
{
    std::string x = "Hello world";
    std::any a = 10;

    std::cout << std::any_cast<int>(a) << '\n';

    a = x;

    std::cout << std::any_cast<std::string>(a) << '\n';

    x[0] = 'W';

    std::cout << std::any_cast<std::string>(a) << '\n';
    std::cout << x << '\n';

    return 0;
}