#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>

class Teacher {
public:
    Teacher() = delete;
    ~Teacher() = default;

    Teacher(const std::string& name, const char* nickname);
    Teacher(const std::string& name, const char* nickname, int age);

    Teacher(const Teacher& other);
    Teacher& operator=(const Teacher& other);

    Teacher(Teacher&& other) noexcept;
    Teacher& operator=(Teacher&& other) noexcept;

    std::string getName() const;
    int getAge() const;

    friend std::ostream& operator<<(std::ostream& os, const Teacher& s);
    bool operator<(const Teacher& s);
    bool operator>(const Teacher& s);
    bool operator==(const Teacher& s);


private:
    std::string m_Name;
    int m_Age;
    char* m_Nickname;
};


#endif      // STUDENT_H
