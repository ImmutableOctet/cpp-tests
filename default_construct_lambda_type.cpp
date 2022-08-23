#include <iostream>
#include <optional>
#include <algorithm>

int main()
{
    int a = 10;

    auto x = [a]()
    {
        std::cout << a << std::endl;
    };

    std::optional<decltype(x)> y = std::move(x);

    x();
    (*y)();

    std::optional<decltype(x)> z;


    //std::swap(y, z);
    std::optional<decltype(z)> s_temp = y;
    y = std::move(z);

    if (z.has_value())
        (*z)();

    return 0;
}