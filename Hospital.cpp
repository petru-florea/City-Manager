
#include "Hospital.h"

Building* Hospital::operator+(const Person &person) {
    this->mEmployees.push_back(person);

    return this;
}

Building* Hospital::operator-(const Person &person) {
    for (uint32_t i = 0; i < mEmployees.size(); i++) {
        if (mEmployees.at(i).mName == person.mName) {
            mEmployees.erase(mEmployees.begin() + i);
            break;
        }
    }

    return this;
}

void Hospital::add(const Person &person) {
    this->mCitizens.push_back(person);
}

void Hospital::remove(const Person &person) {
    for (uint32_t i = 0; i < mCitizens.size(); i++) {
        if (mCitizens.at(i).mName == person.mName) {
            mCitizens.erase(mCitizens.begin() + i);

            break;
        }
    }
}