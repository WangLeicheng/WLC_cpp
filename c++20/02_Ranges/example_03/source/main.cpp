#include "people.h"
#include "student.h"
#include "teacher.h"

#include <iostream>
#include <iomanip>      // For the std::quoted
#include <vector>
#include <memory>
#include <string>
#include <ranges>

int main()
{
    Student s1("wlc", nullptr, 19);
    Student s2("zxm", nullptr, 18);
    Student s3("ssh", nullptr, 18);
    Student s4("x", nullptr, 40);
    Teacher t1("wlc", nullptr, 28);
    Teacher t2("lrx", nullptr, 30);

    std::vector<std::shared_ptr<People>> v;

    v.push_back(std::make_shared<Student>(s1));
    v.push_back(std::make_shared<Student>(s2));
    v.push_back(std::make_shared<Student>(s3));
    v.push_back(std::make_shared<Student>(s4));
    v.push_back(std::make_shared<Teacher>(t1));
    v.push_back(std::make_shared<Teacher>(t2));

    for (const auto& x: v) {
        std::cout << *x << std::endl;
    }

    if (s1 > s2) {
        std::cout << "wlc is elder than zxm" << std::endl;
    }

    if (s4 < t1) {
        std::cout << "stduent is < teacher" <<  std::endl;
    }

    auto v_age_over_20 = v | 
            std::views::filter([](const auto& ptr) {
            return ptr->getAge() > 20;
    });

    std::cout << "************The age over 20: **************************\n";
    for (const auto& x: v_age_over_20) {
        std::cout << *x << std::endl;
    }

    return 0;
}





