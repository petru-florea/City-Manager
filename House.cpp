
#include "House.h"

Building* House::operator+(const Person &person) {
    if (mCoordinator == Person()) {
        this->mCoordinator = person;
    }

    return this;
}

Building* House::operator-() {
    this->mCoordinator = Person();

    return this;
}

void House::add(const Person &person) {
    if (mCitizens.size() < mMaxNumber) {
        mCitizens.push_back(person);
    }
}

void House::remove(const Person &person) {
    for (uint32_t i = 0; i < mCitizens.size(); i++) {
        if ((mCitizens.at(i).mName == person.mName) && (person.mAge >= 18)) {
            mCitizens.erase(mCitizens.begin() + i);

            break;
        }
    }
}