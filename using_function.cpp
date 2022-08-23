#include <iostream>
#include <format>

using std::format;

int main()
{
    std::cout << format("Hello world: {}", 42) << '\n';

    return 0;
}
