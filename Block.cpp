
#include "Block.h"

Building* Block::operator+(const Person &person) {
    if (mCoordinator == Person()) {
        this->mCoordinator = person;
    }

    return this;
}

Building* Block::operator-() {
    this->mCoordinator = Person();

    return this;
}

void Block::add(const Person &person) {
    if (mCitizens.size() < (mNumberOfFloors * mMaxNumberPerFloor)) {
        mCitizens.push_back(person);
    }
}

void Block::remove(const Person &person) {
    for (uint32_t i = 0; i < mCitizens.size(); i++) {
        if ((mCitizens.at(i).mName == person.mName) && (person.mAge >= 18)) {
            mCitizens.erase(mCitizens.begin() + i);

            break;
        }
    }
}