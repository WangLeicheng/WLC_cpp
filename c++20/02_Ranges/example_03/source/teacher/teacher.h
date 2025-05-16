#ifndef TEACHER_H
#define TEACHER_H

#include "people.h"

#include <iostream>
#include <string>

class Teacher : public People { 
public:
    using People::People;       // Inherit constructors
                                
    Teacher() = delete;

    std::string getRole() const override;
    void printInfo(std::ostream& os) const override;
};

#endif      // STUDENT_H
