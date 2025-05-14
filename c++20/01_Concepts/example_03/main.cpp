#include <iostream>

// Custom concept to check if a type is not a reference
template <typename T>
concept NotReference = !std::is_reference_v<T>;

template<NotReference T>
requires NotReference<T>
T getValue(T&& a) 
{
    return std::forward<T>(a);
}


int main() {
    int x = 10;
    int& a = x;
    a = 20;
    // std::cout << getValue(x) << "\n";  // OK: int
    std::cout << getValue(a) << "\n";  // Compile-time error: reference type
    return 0;
}

