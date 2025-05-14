#include <iostream>
#include <type_traits>

// Custom concept to check if a type is an integer type
template <typename T>
concept IsInteger = requires(T a, T b) {
    // We check that T can be cast to an integer type
//     { static_cast<int>(a) } -> std::same_as<int>; // Requires that T can be cast to int
    { a % b};
};

template<IsInteger T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(5, 10) << "\n";       // OK: int
    std::cout << add(100L, 50L) << "\n";   // OK: long
    std::cout << add(3.5, 2.1) << "\n"; // Compile-time error: double
    return 0;
}

