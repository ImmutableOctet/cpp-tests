#include <iostream>
#include <memory>

struct Base
{
    virtual ~Base() {}
    virtual int get_value() const = 0;
};

struct Derived : public Base
{
    Derived(int value=42)
        : value(value) {}

    int get_value() const override
    {
        return value;
    }

    protected:
        int value;
};

using ptr_t = std::shared_ptr<Base>;

int main()
{
    std::shared_ptr<Base> x;

    {
        std::cout << "Making new instance of `Derived` and pointing to it with `y` [type: `std::shared_ptr<Derived>`].\n";
        auto y = std::make_shared<Derived>(1024);

        std::cout << "Pointing to same object as `y` with `x` [type: `std::shared_ptr<Base>`], incrementing the object's reference count in the process.\n";
        x = y;

        std::cout << "Number of references to object [created as type of `Derived`]: " << y.use_count() << '\n';
    }

    std::cout << "`y` has gone out of scope, but `x` still exists, referencing the same object.\n";

    std::cout << "Retrieving the stored value from `x` by a virtual call to the `Derived` instance [from a `std::shared_ptr<Base>`]: " << x->get_value() << '\n';
    std::cout << "References to object: " << x.use_count() << " left, because `x` still exists, but `y` doesn't.\n";

    std::cout << "Conclusion: Shared pointers to `Derrived` objects will be kept alive by shared pointers that use their `Base` type.\n";

    return 0;
}