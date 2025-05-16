#include "teacher.h"

#include <cstring>      // For std::strlen
#include <iomanip>      // For the std::quoted


Teacher::Teacher(const std::string& name, const char* nickname)
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

Teacher::Teacher(const std::string& name, const char * nickname, int age)
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
Teacher::Teacher(const Teacher& other)
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
Teacher& Teacher::operator=(const Teacher& other)
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
Teacher::Teacher(Teacher&& other) noexcept
    : m_Name(std::move(other.m_Name)),
    m_Age(std::move(other.m_Age)),
    m_Nickname(other.m_Nickname) 
{
    other.m_Nickname = nullptr;  // take ownership
}

// ✅ Move assignment
Teacher& Teacher::operator=(Teacher&& other) noexcept {
    if (this != &other) {
        m_Name = std::move(other.m_Name);
        m_Age = std::move(other.m_Age);

        delete[] m_Nickname;
        m_Nickname = other.m_Nickname;
        other.m_Nickname = nullptr;
    }
    return *this;
}

std::string Teacher::getName() const
{
    return m_Name;
}

int Teacher::getAge() const 
{
    return m_Age;
}

std::ostream& operator<<(std::ostream& os, const Teacher& s) 
{
    return os << "[TEACHER; name: " << std::quoted(s.getName()) << ";age: " << s.getAge()<< ";]";
}

bool Teacher::operator<(const Teacher& s2)
{
    return m_Age < s2.getAge();
}

bool Teacher::operator>(const Teacher& s2)
{
    return m_Age > s2.getAge();
}

bool Teacher::operator==(const Teacher& s2)
{
    return m_Age == s2.getAge();
}
