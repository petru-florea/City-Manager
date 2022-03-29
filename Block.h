
#ifndef CITY_MANAGER_BLOCK_H
#define CITY_MANAGER_BLOCK_H

#include "Building.h"

class Block : public Building {
private:
    uint16_t mMaxNumberPerFloor;
    uint16_t mNumberOfFloors;

public:
    Block(std::string name, uint16_t numberOfFloors, uint16_t maxNumberPerFloor) : Building(name, "Block") {
        mMaxNumberPerFloor = maxNumberPerFloor;
        mNumberOfFloors = numberOfFloors;
        mCitizens.clear();
        mCoordinator = Person();
        mCitizens.reserve(numberOfFloors * mMaxNumberPerFloor);
    }

    Building* operator + (const Person &person) override;

    Building* operator - () override;

    void add(const Person &person) override;

    void remove(const Person &person) override;
};


#endif //CITY_MANAGER_BLOCK_H
