#include <iostream>

struct A
{
    int value = 100;

    void print()
    {
        std::cout << value << '\n';
    }
};

struct X
{
    A& a;

    void mutate()
    {
        a.value = 300;
    }

    void const_mutate() const
    {
        const_cast<X*>(this)->mutate();
    }
};

void f(const X& x)
{
    x.a.value = 200; // ok
    // x.mutate(); // illegal
    //x.const_mutate(); // legal, but bad practice.
}

int main()
{
    A a;

    auto x = X { a };

    f(x);

    x.a.print();

    return 0;
}
