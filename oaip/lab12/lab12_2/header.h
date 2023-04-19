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
string containsonlyletters(string str);
bool isEmpty(aeroflot* head);
void addFlight(aeroflot*& head, string name, string type, int num);
void deleteFlight(aeroflot*& head, string name);
void print_list(aeroflot* head);