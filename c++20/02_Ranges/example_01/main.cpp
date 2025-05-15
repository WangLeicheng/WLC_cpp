#include <iostream>
#include <vector>
#include <ranges>
#include <chrono>
#include <string>

int main() {
    std::vector<int> numbers(1'000'000);
    for (int i = 0; i < numbers.size(); ++i) numbers[i] = i;

    // Range-based approach
    auto t1 = std::chrono::high_resolution_clock::now();
    auto even_squared = numbers 
                      | std::views::filter([](int n) { return n % 2 == 0; }) 
                      | std::views::transform([](int n) { return n * n; });
    // Force evaluation (materialize into vector)
    std::vector<int> result1(even_squared.begin(), even_squared.end());
    auto t2 = std::chrono::high_resolution_clock::now();

    // Traditional loop
    auto t3 = std::chrono::high_resolution_clock::now();
    std::vector<int> result2;
    // result2.reserve(numbers.size() / 2);
    for (auto& x : numbers) {
        if (x % 2 == 0) { 
            result2.push_back(x * x);
        }
    }
    auto t4 = std::chrono::high_resolution_clock::now();

    auto range_time = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    auto loop_time = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();

    std::cout << "Range-based: " << range_time << " μs\n";
    std::cout << "Traditional loop: " << loop_time << " μs\n";
}
