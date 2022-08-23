#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

using key_t = std::string;
using value_t = int;
using cache_t = std::unordered_map<key_t, std::weak_ptr<int>>;

std::shared_ptr<int> get_instance(cache_t& cache, const key_t& key, const value_t& value)
{
    auto it = cache.find(key);

    if (it != cache.end())
    {
        return it->second.lock();
    }

    auto instance = std::make_shared<value_t>(value);

    cache[key] = instance;

    return instance;
}

int main()
{
    cache_t cache;

    //auto shared1 = get_instance(cache, "Test", 42);

    {
        auto shared2 = get_instance(cache, "Test", 42);

        std::cout << *shared2 << '\n';

        std::cout << "Expired: " << cache["Test"].expired() << '\n';
    }

    //std::cout << *shared1 << '\n';
    std::cout << "Expired: " << cache["Test"].expired() << '\n';

    std::cin.get();

    return 0;
}
