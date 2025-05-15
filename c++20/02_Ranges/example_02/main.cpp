#include <iostream>
#include <vector>
#include <ranges>

template<typename T>
void print_v(const std::vector<T> &v)
{
    for (const auto x : v) {
        std::cout << "[" << x << "]-->";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto v_result = v | std::views::filter([](int n) {
            return n % 3 == 0;
    });

    print_v<int>(v);

    for (const auto x : v_result) {
        std::cout << "[" << x << "]";
    }
    std::cout << std::endl;
}

