
#ifndef CITY_MANAGER_CITYHALL_H
#define CITY_MANAGER_CITYHALL_H

#include "Building.h"

class CityHall : public Building {
public:
    CityHall(std::string name) : Building(name, "CityHall") {
        mCitizens.clear();
        mCoordinator = Person();
    }

    Building* operator + (const Person &person) override;

    Building* operator - () override;

    void add(const Person &person) override;

    void remove(const Person &person) override;
};


#endif //CITY_MANAGER_CITYHALL_H
