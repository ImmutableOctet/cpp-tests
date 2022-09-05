#include <iostream>
#include <memory>

class Base
{
    public:
        virtual ~Base()
        {
            std::cout << "~Base();\n";
        }

        virtual int get_value() const = 0;
};

class Derived : public Base
{
    public:
        Derived(int value = 42)
            : value(value) {}

        virtual ~Derived()
        {
            std::cout << "~Derived();\n";
        }

        int get_value() const override
        {
            return value;
        }

    protected:
        int value;
};

template <typename T, typename ...Args>
auto make_unique_void(Args&&... args)
{
    return std::unique_ptr<void, void(*)(void*)> // opaque_deleter<T>
    (
        new T(std::forward<Args>(args)...),
        [](void* ptr_no_type)
        {
            auto* ptr = reinterpret_cast<T*>(ptr_no_type);

            std::cout << "Deleting object with value: " << ptr->get_value() << '\n';

            //std::default_delete<T>(ptr)();
            delete ptr;
        }
    );
}

int main()
{
    {
        //auto x = std::make_unique<Derived>(1024);

        auto y = make_unique_void<Derived>(100);

        auto* z = reinterpret_cast<Derived*>(y.get());

        std::cout << "Value is: " << z->get_value() << '\n';

        // Can't be done, `void` is not a complete type.
        //auto w = std::unique_ptr<void>(y.release());
    }

    std::cin.get();

    return 0;
}