#include "student.h"
#include "teacher.h"

#include <iostream>
#include <iomanip>      // For the std::quoted
#include <vector>
#include <string>

int main()
{
    Student s1("wlc", nullptr, 18);
    Student s2("zxm", nullptr, 18);
    Student s3("ssh", nullptr, 18);
    Teacher t1("wlc", nullptr, 28);

    std::vector<Student> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    for (const Student& x: v) {
        std::cout << x << std::endl;
    }
    std::cout << t1 << std::endl;

    if (s1 > s2) {
        std::cout << "wlc is elder than zxm" << std::endl;
    }

    return 0;
}





