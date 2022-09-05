#include <iostream>

int main()
{
    auto start = 1;
    auto end = 100;

    for (auto i = start; i < (start + end); i++)
    {
        bool word_output = false;

        auto trigger = [&i, &word_output](auto divisor, auto&& message)
        {
            if ((i % divisor) == 0)
            {
                std::cout << message;
                word_output = true;
            }
        };

        trigger(3, "Fizz");
        trigger(5, "Buzz");

        if (!word_output)
        {
            std::cout << i;
        }
        
        std::cout << '\n';
    }

    return 0;
}