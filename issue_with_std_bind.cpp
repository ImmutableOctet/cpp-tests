#include <iostream>
#include <functional>

void f(int& x, int& y, int& z)
{
    std::cout << x << ", " << y << ", " << z << '\n';

    x++;
    y++;
    z++;
}

static int x, y, z;

std::function<void()> sub_routine()
{
    //int x, y, z;

    x = 10;
    y = 20;
    z = 30;

    return std::bind(f, x, y, z);
}

int main()
{
    auto f_call = sub_routine();

    f_call(); // Outputs 10, 20, 30 as expected.

    f(x, y, z); // Outputs 10, 20, 30 since the bind call in `sub_routine` implicitly copied in the previous scenario, making this the first to use the globals.
    f(x, y, z); // Outputs 11, 21, 31 since the call to `f_call` didn't modify the global x,y,z, but the manual call to `f` did.
}
