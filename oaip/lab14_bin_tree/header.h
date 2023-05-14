#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    int key;
    string data;
    Node* left;
    Node* right;
};

void saveDataToFile(Node* root, ofstream& outputFile);
int findDepth(Node* root);

Node* createNode(int key, const string& data);
Node* insert(Node* root, int key, const string& data);
Node* search(Node* root, int key);
Node* findMin(Node* root);
Node* remove(Node* root, int key);
void freeMemory(Node* root);
Node* removeBranch(Node* root, int key);
void printTree(Node* root, int level);
int checkInt(int a);