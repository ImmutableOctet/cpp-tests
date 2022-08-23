#include <iostream>

union Union;

void f(Union& u);

union Union
{
    int i;
    float f;
};

void f(Union& u)
{
    u.i = 32;
}

int main()
{
    Union x;

    f(x);

    std::cout << x.i << std::endl;

    return 0;
}
