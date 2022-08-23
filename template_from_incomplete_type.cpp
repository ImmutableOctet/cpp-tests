#include <iostream>

class Thing; // Not defined in this translation unit, but declared.

template <typename T>
struct event_type
{
    // We don't use `T` for any members, but we could still use `T` for other purposes. (e.g. constexpr if, T& members/arguments, etc.)
    int value = 10;
};

int main()
{
    event_type<Thing> e;

    std::cout << "e: " << e.value << std::endl;
}