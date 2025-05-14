#include <iostream>
#include <concepts>
#include <type_traits>

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template<Arithmetic T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    std::cout << sum(3, 4) << "\n";       // OK: int
    std::cout << sum(3.5, 2.1) << "\n";   // OK: double
    // std::cout << sum("hi", "there");  // Compile-time error
    return 0;
}
