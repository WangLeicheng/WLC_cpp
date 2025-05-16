#include "people.h"

#include <cstring>      // For std::strlen
#include <iomanip>      // For the std::quoted

People::~People() 
{
    delete[] m_Nickname;
}

People::People(const std::string& name, const char* nickname)
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

People::People(const std::string& name, const char * nickname, int age)
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
People::People(const People& other)
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
People& People::operator=(const People& other)
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
People::People(People&& other) noexcept
    : m_Name(std::move(other.m_Name)),
    m_Age(std::move(other.m_Age)),
    m_Nickname(other.m_Nickname) 
{
    other.m_Nickname = nullptr;  // take ownership
}

// ✅ Move assignment
People& People::operator=(People&& other) noexcept {
    if (this != &other) {
        m_Name = std::move(other.m_Name);
        m_Age = std::move(other.m_Age);

        delete[] m_Nickname;
        m_Nickname = other.m_Nickname;
        other.m_Nickname = nullptr;
    }
    return *this;
}

std::string People::getName() const
{
    return m_Name;
}

int People::getAge() const 
{
    return m_Age;
}

std::string People::getNickname() const 
{
    return m_Nickname;
}
