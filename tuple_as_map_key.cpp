//#include <unordered_map>
#include <map>
#include <tuple>
#include <iostream>

int main()
{
    //std::unordered_map<std::tuple<int, int>, float> m;
    std::map<std::tuple<int, int>, float> m;

    m[{1, 2}] = 4.0f;

    std::cout << m[{1, 2}] << '\n';

    return 0;
}
