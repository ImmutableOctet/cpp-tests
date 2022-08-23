#include <iostream>

int main()
{
    int x = 0;

    for (auto i = 1; i <= 5; i++)
    {
        std::cout << "On " << i << "...\n";

        switch (i)
        {
            default:
                continue; // Immediately goes to next iteration of the loop, does not fall through. (break is unneeded)

                //std::cout << "This is never reached.\n";
            case 2:
                std::cout << "Found 2\n";

                break;
        }

        std::cout << "Adding 1 to `x`.\n";
        x++;
    }

    std::cout << "x: " << x << "\n";
}
