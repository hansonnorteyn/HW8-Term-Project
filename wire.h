/*********************************************************
* Summary: This is the header file for the Wire class
*
* Authors: Daniel Dukundane and Nii Noi 
* Created: Apr 2024
*
* ©Copyright Cedarville University, its Computer Science faculty, and the
* authors. All rights reserved.
********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "gate.h"
using namespace std;

class Gate;

class Wire {
public:
    Wire(int value = 0, string name = "", vector<Gate*> drives = {}, int index = 0, vector<string> history = {});
    void setValue(int value);
    void setName(string name);
    void setDrives(vector<Gate*> drives);
    void setIndex(int index);
    void setHistory(vector<string> history);
    int getValue() const;
    string getName() const;
    vector<Gate*> getDrives() const;
    int getIndex() const;
    vector<string> getHistory() const;
    void printHistory() const;


private:
    int value;
    string name;
    vector<Gate*> drives;
    int index;
    vector<string> history;

};