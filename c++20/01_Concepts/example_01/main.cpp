#include <iostream>
#include <concepts>

template<std::arithmetic T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    std::cout << sum(3, 4) << "\n";  // OK: int
    std::cout << sum(3.5, 2.1) << "\n"; // OK: double
    return 0;
}

