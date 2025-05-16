#ifndef STUDENT_H
#define STUDENT_H

#include "people.h"

#include <iostream>
#include <string>

class Student : public People {
public:
    using People::People;       // Inherit constructors
    Student() = delete;

    std::string getRole() const override;
    void printInfo(std::ostream& os) const override;


    bool operator<(const Student& s);
    bool operator>(const Student& s);
    bool operator==(const Student& s);
};


#endif      // STUDENT_H
