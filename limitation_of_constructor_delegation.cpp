#include <iostream>

struct thing
{
    int x;
    int y;

    thing() { x = 24; }
    thing(int value) : thing(), y(value) {} // error: can't construct `y` after calling other constructor.
    //thing(int value) : y(value), thing() {} // error: can't delegate after constructing `y`.
};

int main()
{
    auto t = thing(100);

    std::cout << t.x << ", " << t.y << '\n';

    return 0;
}