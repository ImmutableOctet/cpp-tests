#include <iostream>

enum class EnumValue
{
    A,
    B,
    C
};

template <EnumValue ev>
struct X
{
    EnumValue v = ev;
};

void print(X<EnumValue::A> value)
{
    std::cout << "Type A: " << static_cast<int>(value.v) << std::endl;
}

void print(X<EnumValue::B> value)
{
    std::cout << "Type B: " << static_cast<int>(value.v) << std::endl;
}

void print(X<EnumValue::C> value)
{
    std::cout << "Type C: " << static_cast<int>(value.v) << std::endl;
}

int main()
{
    X<EnumValue::A> a;
    X<EnumValue::B> b;
    X<EnumValue::C> c;
    
    print(a);
    print(b);
    print(c);

    return 0;
}
