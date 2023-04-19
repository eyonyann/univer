#pragma once

#include <iostream>
using namespace std;

struct aeroflot {
	string destination_name;
	string flight_type;
	int flight_num;
	aeroflot* next;
};

void enqueue(string name, string type, int num);
void dequeue();
void display();
int checkInt(int a);
string containsonlyletters(string str);