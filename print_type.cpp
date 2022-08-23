#include <iostream>
#include <typeinfo>

template <typename T>
void print_type(const T& value)
{
    const std::type_info& t_info = typeid(T);

    std::cout << "Type: " << t_info.name() << '\n';
}

int main()
{
    int x = 10;
    int* y = &x;
    const auto* z = y;
    auto w = z;

    std::cout << *w << std::endl;
    print_type(x);
    print_type(y);
    print_type(z);
    print_type(w);

    return 0;
}