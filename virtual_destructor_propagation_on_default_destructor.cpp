#include <iostream>
#include <memory>

struct Other
{
    Other(int value) : value(value) {}
    ~Other()
    {
        std::cout << "Destructing `Other`. My value is: " << value << '\n';
    }

    int value = 1024;
};

struct Base
{
    virtual
    ~Base()
    {
        std::cout << "Hello from `Base`.\n";
    }
};

struct Derived : public Base
{
    Other other;
    
    Derived(int value)
        : other(value)
    {}
};

struct SecondDerived : public Derived
{
    SecondDerived(int value) : Derived(value) {}
};

int main()
{
    std::unique_ptr<Base> obj = std::make_unique<SecondDerived>(12345);

    return 0;
}
