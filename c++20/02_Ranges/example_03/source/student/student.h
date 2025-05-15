#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
public:
    Student() = delete;
    ~Student() = default;

    Student(const std::string& name, const char* nickname);
    Student(const std::string& name, const char* nickname, int age);

    Student(const Student& other);
    Student& operator=(const Student& other);

    Student(Student&& other) noexcept;
    Student& operator=(Student&& other) noexcept;

    std::string getName() const;
    int getAge() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    bool operator<(const Student& s);
    bool operator>(const Student& s);
    bool operator==(const Student& s);


private:
    std::string m_Name;
    int m_Age;
    char* m_Nickname;
};


#endif      // STUDENT_H
