
#ifndef CITY_MANAGER_HOSPITAL_H
#define CITY_MANAGER_HOSPITAL_H

#include "Building.h"

class Hospital : public Building {
public:
    Hospital(std::string name) : Building(name, "Hospital") {
        mCitizens.clear();
        mEmployees.clear();
    }

    Building* operator + (const Person &person) override;

    Building* operator - (const Person &person) override;

    void add(const Person &person) override;

    void remove(const Person &person) override;
};


#endif //CITY_MANAGER_HOSPITAL_H
