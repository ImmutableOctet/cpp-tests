#include <iostream>
#include <memory>

struct Base
{
    virtual ~Base() = default;
};

struct Derived : public Base
{
    int value;
    
    Derived(int value)
        : value(value)
    {}

    ~Derived()
    {
        std::cout << "Hello from `Derived`.\n";
    }
};

int main()
{
    std::unique_ptr<Base> obj = std::make_unique<Derived>(12345);

    return 0;
}
