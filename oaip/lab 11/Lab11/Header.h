#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <time.h>
#include <vector>

extern int number_of_flights;

using namespace std;
extern void print(int*, int);
extern void bubbleSort(int*, int);
extern void minSort(int*, int);
extern void insertSort(int*, int);
extern void shellSort(int*, int);
extern void hoorSort(int*, int, int);
extern void bogoSort(int*, int);
extern void seqSearch(int*, int, int);
extern int binarySearch(int*, int, int, int);

extern int main10();

extern void enter();
extern void print_all();
extern int find();


extern int sort();
extern void sort_num();
extern void sort_name();
extern void sort_type();


char containsOnlyLetters(char input[20]);
int check_int(int input);

