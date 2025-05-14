#include <iostream>
#include <vector>
#include <string>

// Concept: IsInteger — supports modulus operator
template<typename T>
concept IsInteger = requires(T a, T b) {
    { a % b };
};

// Concept: SupportsIncrement — can be incremented with ++
template<typename T>
concept SupportsIncrement = requires(T a) {
    { ++a } -> std::same_as<T&>;  // Pre-increment must return T&
};

// Concept: HasSize — has a .size() member function
template<typename T>
concept HasSize = requires(T a) {
    { a.size() } -> std::convertible_to<std::size_t>;
};

// Concept: AddableWith — two types can be added together
template<typename T, typename U>
concept AddableWith = requires(T a, U b) {
    { a + b };
};

// Concept: StreamInsertable — can be used with std::cout << x
template<typename T>
concept StreamInsertable = requires(T a) {
    { std::cout << a } -> std::same_as<std::ostream&>;
};

// Function: Only for integers
template<IsInteger T>
T doubleMod(T a, T b) {
    return (a % b) * 2;
}

// Function: Increment and return new value
template<SupportsIncrement T>
T increment(T val) {
    ++val;
    return val;
}

// Function: Print any streamable value
template<StreamInsertable T>
void print(const T& val) {
    std::cout << "Value: " << val << "\n";
}

// Function: Add two addable values
template<typename T, typename U>
requires AddableWith<T, U>
auto add(const T& a, const U& b) {
    return a + b;
}

// Function: Process container with .size() and []
template<HasSize T>
void printContainer(const T& container) {
    std::cout << "Container has " << container.size() << " elements:\n";
    for (std::size_t i = 0; i < container.size(); ++i) {
        print(container[i]);
    }
}

int main() {
    // IsInteger
    std::cout << "Modulus * 2: " << doubleMod(10, 3) << "\n";

    // SupportsIncrement
    int x = 5;
    std::cout << "Incremented: " << increment(x) << "\n";

    // StreamInsertable + print
    std::string name = "Hello, C++20 Concepts!";
    print(name);
    print(42);

    // AddableWith
    auto sum1 = add(10, 20);         // int + int
    auto sum2 = add(3.14, 2);        // double + int
    auto sum3 = add(std::string("Hi "), "there"); // std::string + const char*
    print(sum1);
    print(sum2);
    print(sum3);

    // HasSize + printContainer
    std::vector<std::string> words = {"alpha", "beta", "gamma"};
    printContainer(words);

    return 0;
}

