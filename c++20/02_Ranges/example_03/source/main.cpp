#include "people.h"
#include "student.h"
#include "teacher.h"

#include <iostream>
#include <iomanip>      // For the std::quoted
#include <vector>
#include <memory>
#include <string>

int main()
{
    Student s1("wlc", nullptr, 18);
    Student s2("zxm", nullptr, 18);
    Student s3("ssh", nullptr, 18);
    Teacher t1("wlc", nullptr, 28);

    std::vector<std::shared_ptr<People>> v;

    v.push_back(std::make_shared<Student>(s1));
    v.push_back(std::make_shared<Student>(s2));
    v.push_back(std::make_shared<Student>(s3));
    v.push_back(std::make_shared<Teacher>(t1));

    for (const auto& x: v) {
        std::cout << *x << std::endl;
    }

    if (s1 > s2) {
        std::cout << "wlc is elder than zxm" << std::endl;
    }

    return 0;
}





