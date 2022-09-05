#include <iostream>
#include <type_traits>

struct X
{
    static void fn();
};

struct Y
{
    static void other_fn();
};

#define scannable_static_member_function(function_name) \
    template<class, class = void> \
    struct has_static_function_##function_name : std::false_type {}; \
    template<class T> \
    struct has_static_function_##function_name<T, std::void_t<decltype(T::##function_name())>> : std::true_type {}; \

scannable_static_member_function(fn);
scannable_static_member_function(other_fn);

int main()
{
    std::cout << "Does `X` have `fn`? " << has_static_function_fn<X>::value << '\n';
    std::cout << "Does `Y` have `fn`? " << has_static_function_fn<Y>::value << '\n';
    std::cout << "Does `X` have `other_fn`? " << has_static_function_other_fn<X>::value << '\n';
    std::cout << "Does `Y` have `other_fn`? " << has_static_function_other_fn<Y>::value << '\n';

    return 0;
}