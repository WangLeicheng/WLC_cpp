#include "student.h"

#include <cstring>      // For std::strlen
#include <iomanip>      // For the std::quoted


Student::Student(const std::string& name, const char* nickname)
    :m_Name(name), m_Age(0)
{
    if (nickname) {
        m_Nickname = new char[std::strlen(nickname) + 1];
        std::strcpy(m_Nickname, nickname);
    }
    else {
        m_Nickname = nullptr;
    }
}

Student::Student(const std::string& name, const char * nickname, int age)
    :m_Name(name), m_Age(age)
{
    if (nickname) {
        m_Nickname = new char[std::strlen(nickname) + 1];
        std::strcpy(m_Nickname, nickname);
    }
    else {
        m_Nickname = nullptr;
    }
}

// ✅ Copy constructor (deep copy)
Student::Student(const Student& other)
    :m_Name(other.m_Name), m_Age(other.m_Age)
{

    if (other.m_Nickname) {
        m_Nickname = new char[std::strlen(other.m_Nickname) + 1];
        std::strcpy(m_Nickname, other.m_Nickname);
    }
    else {
        m_Nickname = nullptr;
    }
}

// ✅ Copy assignment operator (deep copy)
Student& Student::operator=(const Student& other)
{
    if (this != &other) {
        m_Name = other.m_Name;
        m_Age = other.m_Age;

        delete[] m_Nickname;

        if (other.m_Nickname) {
            m_Nickname = new char[std::strlen(other.m_Nickname) + 1];
            std::strcpy(m_Nickname, other.m_Nickname);
        }
        else {
            m_Nickname = nullptr;
        }
    }

    return *this;
}


// ✅ Move constructor
Student::Student(Student&& other) noexcept
    : m_Name(std::move(other.m_Name)),
    m_Age(std::move(other.m_Age)),
    m_Nickname(other.m_Nickname) 
{
    other.m_Nickname = nullptr;  // take ownership
}

// ✅ Move assignment
Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        m_Name = std::move(other.m_Name);
        m_Age = std::move(other.m_Age);

        delete[] m_Nickname;
        m_Nickname = other.m_Nickname;
        other.m_Nickname = nullptr;
    }
    return *this;
}

std::string Student::getName() const
{
    return m_Name;
}

int Student::getAge() const 
{
    return m_Age;
}

std::ostream& operator<<(std::ostream& os, const Student& s) 
{
    return os << "[name: " << std::quoted(s.getName()) << ";age: " << s.getAge()<< ";]";
}

bool Student::operator<(const Student& s2)
{
    return m_Age < s2.getAge();
}

bool Student::operator>(const Student& s2)
{
    return m_Age > s2.getAge();
}

bool Student::operator==(const Student& s2)
{
    return m_Age == s2.getAge();
}
