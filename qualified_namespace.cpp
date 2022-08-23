#include <iostream>

namespace x::y
{
    void z(int value);
}

namespace x::y
{
    void z(int value)
    {
        std::cout << "Value: " << value << '\n';
    }
}

int main()
{
    x::y::z(12345);

    return 0;
}
