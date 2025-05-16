#include "teacher.h"

#include <cstring>      // For std::strlen
#include <iomanip>      // For the std::quoted

std::string Teacher::getRole() const
{
    return "TEACHER";
}

void Teacher::printInfo(std::ostream& os) const
{
    os << "[" << this->getRole() << "; name: " <<  std::quoted(m_Name) << "; age: " << m_Age << ";";
    if (m_Nickname) {
        os <<  "nickname: " << std::quoted(m_Nickname);
    }

    os << "]";
}

/*
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
*/
