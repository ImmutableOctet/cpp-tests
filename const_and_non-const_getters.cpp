#include <iostream>
#include <string>

struct X
{
    std::string value;

    const std::string get_value() const { return value; }
    std::string& get_value() { return value; }
};

void print(const std::string& str)
{
    std::cout << str << '\n';
}

int main()
{
    X thing { "Hello" };

    //auto& str = thing.get_value();
    //str += " world";

    thing.get_value() += " world";

    std::cout << thing.value << '\n';
    std::cout << thing.get_value() << '\n';
    print(thing.get_value());

    return 0;
}