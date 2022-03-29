
#include "CityHall.h"

Building* CityHall::operator+(const Person &person) {
    if (mCoordinator == Person()) {
        this->mCoordinator = person;
    }

    return this;
}

Building* CityHall::operator-() {
    this->mCoordinator = Person();

    return this;
}

void CityHall::add(const Person &person) {
    this->mCitizens.push_back(person);
}

void CityHall::remove(const Person &person) {
    for (uint32_t i = 0; i < mCitizens.size(); i++) {
        if (mCitizens.at(i).mName == person.mName) {
            mCitizens.erase(mCitizens.begin() + i);

            break;
        }
    }
}