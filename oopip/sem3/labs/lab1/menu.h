#pragma once

#include "libs.h"
#include "classes.h"

void createCar(std::vector<Vehicle*>& vehicles);
void createMilitaryCar(std::vector<Vehicle*>& vehicles);
void createPublicCar(std::vector<Vehicle*>& vehicles);
void createPersonalCar(std::vector<Vehicle*>& vehicles);
void createAirplane(std::vector<Vehicle*>& vehicles);
void displayVehicles(const std::vector<Vehicle*>& vehicles);
void modifyParameters(std::vector<Vehicle*>& vehicles);
void searchVehicle(std::vector<Vehicle*>& vehicles);