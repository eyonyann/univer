#pragma once

#include <iostream>
#include <string>
using namespace std;

struct aeroflot {
	string destination_name;
	string flight_type;
	int flight_num;
	aeroflot* next;
};

int checkInt(int a);

void push();
void pop();
void display();