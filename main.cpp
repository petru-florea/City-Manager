#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "Person.h"
#include "Building.h"
#include "CityHall.h"
#include "Hospital.h"
#include "PoliceStation.h"
#include "House.h"
#include "Block.h"

int main() {
    bool find;
    uint16_t maxNumber, numberOfFloors, maxNumberPerFloor, age;
    double salary;
    std::string action, input, buildingName, personName, buildingToAddTo, buildingToRemoveFrom;
    std::vector<Building*> buildings;

    while (std::cin >> action) {
        find = false;
        if (action == "add") {
            std::cin >> input;

            if (input == "CityHall") {
                std::cin >> buildingName;

                for (auto &b : buildings) {
                    if (b->getBuildingName() == buildingName) {
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    buildings.push_back(new CityHall(buildingName));
                }
            }
            else if (input == "Hospital") {
                std::cin >> buildingName;

                for (auto &b : buildings) {
                    if (b->getBuildingName() == buildingName) {
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    buildings.push_back(new Hospital(buildingName));
                }
            }
            else if (input == "PoliceStation") {
                std::cin >> buildingName;

                for (auto &b : buildings) {
                    if (b->getBuildingName() == buildingName) {
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    buildings.push_back(new PoliceStation(buildingName));
                }
            }
            else if (input == "House") {
                std::cin >> buildingName;
                std::cin >> maxNumber;

                for (auto &b : buildings) {
                    if (b->getBuildingName() == buildingName) {
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    buildings.push_back(new House(buildingName, maxNumber));
                }
            }
            else if (input == "Block") {
                std::cin >> buildingName;
                std::cin >> numberOfFloors >> maxNumberPerFloor;

                for (auto &b : buildings) {
                    if (b->getBuildingName() == buildingName) {
                        find = true;
                        break;
                    }
                }

                if (!find) {
                    buildings.push_back(new Block(buildingName, numberOfFloors, maxNumberPerFloor));
                }
            }
            else if (input == "coordinator") {
                std::cin >> personName >> age >> salary >> buildingToAddTo;

                for (auto i = 0; i < buildings.size(); i++) {
                    if (buildings.at(i)->getBuildingName() == buildingToAddTo) {

                        if (buildings.at(i)->getType() == "CityHall") {
                            buildings.at(i) = buildings.at(i)->operator + (Person(personName, age, salary));
                        }
                        else if ((buildings.at(i)->getType() == "House") || (buildings.at(i)->getType() == "Block")) {
                            buildings.at(i) = buildings.at(i)->operator + (Person(personName, age, salary));
                            if (buildings.at(i)->getCoordinator().mName == personName) {
                                buildings.at(i)->add(Person(personName, age, salary));
                            }
                        }
                        else {
                            std::cout << "GTA San Andreas" << std::endl;
                        }

                        break;
                    }
                }
            }
            else if (input == "employee") {
                std::cin >> personName >> age >> salary >> buildingToAddTo;

                for (auto i = 0; i < buildings.size(); i++) {
                    if (buildings.at(i)->getBuildingName() == buildingToAddTo) {
                        buildings.at(i) = buildings.at(i)->operator + (Person(personName, age, salary));

                        break;
                    }
                }
            }
            else if (input == "citizen") {
                std::cin >> personName >> age >> salary >> buildingToAddTo;

                for (auto &building : buildings) {
                    if (building->getBuildingName() == buildingToAddTo) {
                        building->add(Person(personName, age, salary));

                        break;
                    }
                }
            }
            else {
                std::cout << "Grand Theft Auto Vice City" << std::endl;
            }
        }
        else if (action == "remove") {
            std::cin >> input;

            if (input == "coordinator") {
                std::cin >> personName >> buildingToRemoveFrom;

                for (auto i = 0; i < buildings.size(); i++) {
                    if (buildings.at(i)->getBuildingName() == buildingToRemoveFrom) {

                        if (buildings.at(i)->getType() == "CityHall") {
                            buildings.at(i) = buildings.at(i)-> operator - ();
                        }
                        else if ((buildings.at(i)->getType() == "House") || (buildings.at(i)->getType() == "Block")) {
                            buildings.at(i)->remove(buildings.at(i)->getCoordinator());
                            buildings.at(i) = buildings.at(i)-> operator - ();
                        }

                        break;
                    }
                }
            }
            else if (input == "employee") {
                std::cin >> personName >> buildingToRemoveFrom;

                for (auto i = 0; i < buildings.size(); i++) {
                    if (buildings.at(i)->getBuildingName() == buildingToRemoveFrom) {

                        for (auto j = 0; j < buildings.at(i)->getEmployeesSize(); j++) {
                            if (buildings.at(i)->getEmployee(j).mName == personName) {
                                buildings.at(i)->operator - (buildings.at(i)->getEmployee(j));
                            }
                        }

                        break;
                    }
                }
            }
            else if (input == "citizen") {
                std::cin >> personName >> buildingToRemoveFrom;

                for (auto i = 0; i < buildings.size(); i++) {
                    if (buildings.at(i)->getBuildingName() == buildingToRemoveFrom) {

                        for (auto j = 0; j < buildings.at(i)->getCitizensSize(); j++) {
                            if (buildings.at(i)->getCitizen(j).mName == personName) {
                                buildings.at(i)->remove(buildings.at(i)->getCitizen(j));
                            }
                        }

                        break;
                    }
                }
            }
            else {
                std::cout << "Metro 2033" << std::endl;
            }
        }
        else {
            std::cout << "Cyberpunk 2077" << std::endl;
        }
    }

    double cityHallNumber = 0, hospitalNumber = 0, policeStationNumber = 0, houseNumber = 0, blockNumber = 0;
    double patiensNumber = 0, doctorsNumber = 0;
    double doctorsSalary = 0, averageDocSalary;
    double copsNumber = 0;
    double copsSalary = 0, averageCopSalary, averageBustedAge, bustedAge = 0, bustedNumber = 0;
    double mayorsNumber = 0, employeesNumber = 0;
    double mayorsSalary = 0, averageMayorSalary, employeesSalary = 0, averageEmployeeSalary;

    for (auto &b : buildings) {
        if (b->getType() == "CityHall") {
            cityHallNumber++;
            if (b->getCoordinator().mAge != 0) {
                mayorsNumber++;
                mayorsSalary += b->getCoordinator().mSalary;
            }
            for (auto i = 0; i < b->getCitizensSize(); i++) {
                employeesSalary += b->getCitizen(i).mSalary;
            }
            employeesNumber += b->getCitizensSize();
        }
        else if (b->getType() == "Hospital") {
            hospitalNumber++;
            patiensNumber += b->getCitizensSize();
            for (auto i = 0; i < b->getEmployeesSize(); i++) {
                doctorsSalary += b->getEmployee(i).mSalary;
            }
            doctorsNumber += b->getEmployeesSize();
        }
        else if (b->getType() == "PoliceStation") {
            policeStationNumber++;
            for (auto i = 0; i < b->getEmployeesSize(); i++) {
                copsSalary += b->getEmployee(i).mSalary;
            }
            copsNumber += b->getEmployeesSize();
            for (auto i = 0; i < b->getCitizensSize(); i++) {
                bustedAge += b->getCitizen(i).mAge;
            }
            bustedNumber += b->getCitizensSize();
        }
        else if (b->getType() == "House") { houseNumber++; }
        else { blockNumber++; }
    }

    std::cout << "Type: ";
    if ((cityHallNumber >= 3) && (hospitalNumber >= 2) && (policeStationNumber >= 3) && (houseNumber >= 8) && (blockNumber >= 4))
        std::cout << "Capital" << std::endl;
    else if ((cityHallNumber >= 2) && (hospitalNumber >= 1) && (policeStationNumber >= 2) && (houseNumber >= 4) && (blockNumber >= 1))
        std::cout << "Town" << std::endl;
    else
        std::cout << "Village" << std::endl;

    std::cout << "Number of patients in hospitals: " << patiensNumber << std::endl;

    averageDocSalary = doctorsSalary/doctorsNumber;
    if (doctorsNumber == 0)
        std::cout << "Average salary for doctors: " << 0 << std::endl;
    else
        std::cout << "Average salary for doctors: " << averageDocSalary << std::endl;

    averageCopSalary = copsSalary/copsNumber;
    if (copsNumber == 0)
        std::cout << "Average salary for cops: " << 0 << std::endl;
    else
        std::cout << "Average salary for cops: " << averageCopSalary << std::endl;

    averageMayorSalary = mayorsSalary/mayorsNumber;
    if (mayorsNumber == 0)
        std::cout << "Average salary for mayors: " << 0 << std::endl;
    else
        std::cout << "Average salary for mayors: " << averageMayorSalary << std::endl;

    averageEmployeeSalary = employeesSalary/employeesNumber;
    if (employeesSalary == 0)
        std::cout << "Average salary for city hall employees: " << 0 << std::endl;
    else
        std::cout << "Average salary for city hall employees: " << averageEmployeeSalary << std::endl;

    averageBustedAge = bustedAge/bustedNumber;
    if (bustedNumber == 0)
        std::cout << "Average age of busted in police stations: " << 0 << std::endl;
    else
        std::cout << "Average age of busted in police stations: " << averageBustedAge << std::endl;

    for (auto &b : buildings) {
        if (b->getType() == "House")
            std::cout << "Number of people in House " << b->getBuildingName() << ": " << b->getCitizensSize() << std::endl;
        else if (b->getType() == "Block")
            std::cout << "Number of people in Block " << b->getBuildingName() << ": " << b->getCitizensSize() << std::endl;
    }

    std::set<std::string> houseCoordinators;
    std::set<std::string> houseAndBlockAdmin;
    uint32_t houseAndBlockAdminN = 0;

    for (auto &b : buildings) {
        if (b->getType() == "House")
            if (b->getCoordinator().mAge != 0) { houseCoordinators.insert(b->getCoordinator().mName); }
    }

    for (auto &b : buildings) {
        if (b->getType() == "Block") {
            if (houseCoordinators.find(b->getCoordinator().mName) != houseCoordinators.end()) {
                houseAndBlockAdminN++;
                houseAndBlockAdmin.insert(b->getCoordinator().mName);
            }
        }
    }

    if (houseAndBlockAdminN != 0) {
        std::cout << "Administrators of house and block: ";
        for (auto &p : houseAndBlockAdmin)
            std::cout << p << " ";
    }
    else {
        std::cout << "Administrators of house and block: Nobody" << std::endl;
    }

    return 0;
}
