
#ifndef CITY_MANAGER_PERSON_H
#define CITY_MANAGER_PERSON_H

#include <string>

class Person {
public:
    std::string mName;
    uint16_t mAge;
    double mSalary;

    Person();

    Person(std::string name, uint16_t age, double salary);

    bool operator == (const Person &person) const;

    bool operator < (const Person &person) const;
};


#endif //CITY_MANAGER_PERSON_H
