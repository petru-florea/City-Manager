
#include "Person.h"

Person::Person() {
    mName = "";
    mAge = 0;
    mSalary = 0;
}

Person::Person(std::string name, uint16_t age, double salary) {
    mName = name;
    mAge = age;
    mSalary = salary;
}

bool Person::operator==(const Person &person) const {
    if ((person.mName == this->mName) && (person.mAge == this->mAge) && (person.mSalary == this->mSalary))
        return true;
    else
        return false;
}

bool Person::operator<(const Person &person) const {
    if (this->mName < person.mName)
        return true;
    else
        return false;
}