
#ifndef CITY_MANAGER_HOUSE_H
#define CITY_MANAGER_HOUSE_H

#include "Building.h"

class House : public Building {
private:
    uint16_t mMaxNumber;

public:
    House(std::string name, uint16_t maxNumber) : Building(name, "House") {
        mMaxNumber = maxNumber;
        mCitizens.clear();
        mCoordinator = Person();
    }

    Building* operator + (const Person &person) override;

    Building* operator - () override;

    void add(const Person &person) override;

    void remove(const Person &person) override;
};


#endif //CITY_MANAGER_HOUSE_H
