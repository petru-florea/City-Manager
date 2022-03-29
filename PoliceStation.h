
#ifndef CITY_MANAGER_POLICESTATION_H
#define CITY_MANAGER_POLICESTATION_H

#include "Building.h"

class PoliceStation : public Building {
public:
    PoliceStation(std::string name) : Building(name, "PoliceStation") {
        mCitizens.clear();
        mEmployees.clear();
    }

    Building* operator + (const Person &person) override;

    Building* operator - (const Person &person) override;

    void add(const Person &person) override;

    void remove(const Person &person) override;
};


#endif //CITY_MANAGER_POLICESTATION_H
