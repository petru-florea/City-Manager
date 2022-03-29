
#include "PoliceStation.h"

Building* PoliceStation::operator+(const Person &person) {
    this->mEmployees.push_back(person);

    return this;
}

Building* PoliceStation::operator-(const Person &person) {
    for (uint32_t i = 0; i < mEmployees.size(); i++) {
        if (mEmployees.at(i) == person) {
            mEmployees.erase(mEmployees.begin() + i);
            break;
        }
    }

    return this;
}

void PoliceStation::add(const Person &person) {
    this->mCitizens.push_back(person);
}

void PoliceStation::remove(const Person &person) {
    for (uint32_t i = 0; i < mCitizens.size(); i++) {
        if (mCitizens.at(i).mName == person.mName) {
            mCitizens.erase(mCitizens.begin() + i);

            break;
        }
    }
}