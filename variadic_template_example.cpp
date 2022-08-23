#include <iostream>

template <typename First>
inline std::string concat(First&& f)
{
    return f;
}

template <typename First, typename Second, typename ...Remaining>
inline std::string concat(First&& first, Second&& second, Remaining&&... strs)
{
    return first + concat<Second, Remaining...>(std::forward<Second&&>(second), strs...);
}

int main()
{
    std::cout << "Concatenate strings:" << std::endl;
    std::cout << concat("Hello ", "World", " This", " Is ", "A", " Test.") << std::endl;

    return 0;
}