#include <iostream>
#include <string>

#include <variant>
#include <utility>

// Helper templates (from cppreference):
	
// Helper type for the visitors.
template<class... Ts> struct visit_overloaded_t : Ts... { using Ts::operator()...; };

// Explicit deduction guide. (not needed as of C++20)
template<class... Ts> visit_overloaded_t(Ts...)->visit_overloaded_t<Ts...>;


template<typename variant_t, class... Callbacks>
auto visit_overloaded(variant_t&& variant_obj, Callbacks&&... overloads)
{
    return std::visit(visit_overloaded_t<Callbacks...>(std::forward<Callbacks>(overloads)...), std::forward<variant_t>(variant_obj));
}

int main()
{
    std::variant<int, std::string> value = std::string("Hello world.");

    visit_overloaded
    (
        value,
        
        [](const std::string& str)
        {
            std::cout << "String: " << str << '\n';
        },

        [](int i)
        {
            std::cout << "Int: " << i << '\n';
        }
    );

    return 0;
}