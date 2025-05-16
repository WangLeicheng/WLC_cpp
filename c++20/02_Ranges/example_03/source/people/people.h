#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>

class People {
public:
    // Poeple() = delete;
    virtual ~People();

    People(const std::string& name, const char* nickname);
    People(const std::string& name, const char* nickname, int age);

    People(const People& other);
    People& operator=(const People& other);

    People(People&& other) noexcept;
    People& operator=(People&& other) noexcept;

    std::string getName() const;
    int getAge() const;
    std::string getNickname() const;

    bool operator<(const People& other) const;
    bool operator>(const People& other) const;
    bool operator==(const People& other) const;

    // Abstract interface
    virtual std::string getRole() const = 0;
    virtual void printInfo(std::ostream& os) const = 0;

protected:
    std::string m_Name;
    int m_Age;
    char* m_Nickname;
};

// << operator for any People-derived object
inline std::ostream& operator<<(std::ostream& os, const People& p) {
        p.printInfo(os);
        return os;
}


#endif      // PEOPLE_H
