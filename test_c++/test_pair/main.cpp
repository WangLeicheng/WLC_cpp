#include <iostream>


std::pair<bool, int> divide(int a, int b)
{
    if (b == 0) {
        return {false, 0};
    } 
    else {
        return {true, a / b};
    }
}

int main()
{
    int a = 10;
    int b = 5;

    auto [success, result] = divide(a, b);

    if (success) {
        std::cout <<  "result is : " << result << std::endl;
    }
    else {
        std::cout << "Division failed" << std::endl;
    }
}

