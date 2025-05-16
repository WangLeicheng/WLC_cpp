#include <iostream>
#include <vector>
#include <ranges>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto even_view = v | std::views::filter([](int n) { return n % 2 == 0; });

    // Use iterators to construct a vector from the view
    std::vector<int> v_result(even_view.begin(), even_view.end());

    for (int x : v_result) {
        std::cout << x << "-->";
    }
    std::cout << std::endl;

    return 0;
}

