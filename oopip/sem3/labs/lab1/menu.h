#pragma once

#include "libs.h"
#include "classes.h"

void CreateMilitaryCar(std::vector<Vehicle*>& vehicles);
void DisplayVehicles(const std::vector<Vehicle*>& vehicles);
void ModifyParameters(std::vector<Vehicle*>& vehicles);
void SearchVehicle(std::vector<Vehicle*>& vehicles);
int GetIntNumber();