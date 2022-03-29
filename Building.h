
#ifndef CITY_MANAGER_BUILDING_H
#define CITY_MANAGER_BUILDING_H


#include <vector>
#include "Person.h"

class Building {
protected:
    std::string mBuildingName;
    std::string mType;
    Person mCoordinator;
    std::vector<Person> mEmployees;
    std::vector<Person> mCitizens;

public:
    Building(std::string name, std::string type) {
        mBuildingName = name;
        mType = type;
    }

    virtual void add(const Person &person) = 0;

    virtual void remove(const Person &person) = 0;

    virtual Building* operator + (const Person &person) = 0;

    virtual Building* operator - () {
        return nullptr;
    }

    virtual Building* operator - (const Person &person) {
        return nullptr;
    }

    std::string getBuildingName() const {
        return mBuildingName;
    }

    std::string getType() const {
        return mType;
    }

    uint16_t getEmployeesSize() const {
        return mEmployees.size();
    }

    uint16_t getCitizensSize() const {
        return mCitizens.size();
    }

    Person getEmployee(uint16_t i) const {
        return mEmployees.at(i);
    }

    Person getCitizen(uint16_t i) const {
        return mCitizens.at(i);
    }

    Person getCoordinator() const {
        return mCoordinator;
    }
};


#endif //CITY_MANAGER_BUILDING_H
