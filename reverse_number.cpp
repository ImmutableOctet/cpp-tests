#include <iostream>

auto reverse_number(auto n)
{
    auto result = 0;
    
    while (n != 0)
    {
        auto remainder = (n % 10);
        result = (result * 10) + remainder;
        n /= 10;
    }
    
    return result;
}

int main()
{
    int x = 123456;

    std::cout << reverse_number(x) << '\n'; // 654321

    return 0;
}
