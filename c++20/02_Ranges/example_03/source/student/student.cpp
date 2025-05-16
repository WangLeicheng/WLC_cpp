#include "student.h"

#include <cstring>      // For std::strlen
#include <iomanip>      // For the std::quoted

std::string Student::getRole() const
{
    return "STUDENT";
}

void Student::printInfo(std::ostream& os) const
{
    os << "[" << this->getRole() << "; name: " << std::quoted(m_Name) << "; age: " << m_Age << ";";
    if (m_Nickname) {
        os << " nickname: " << m_Nickname << ";";
    }
    os << "]";
}
