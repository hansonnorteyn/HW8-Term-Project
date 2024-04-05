#include <iostream>
#include <vector>
#include <string>
#include "gate.h"
using namespace std;


/*
This criterion is linked to a Learning OutcomeWire Attributes in Class Spec (Wire.h)
Expected Attributes (first three are minimal):
* value (int, char, enum)
* name (string, char)
* drives (vector<Gate*>)
* index (int)
* history (string, vector)

This criterion is linked to a Learning OutcomeWire Member Functions in Class Spec (Wire.h)
Expected Functions:
* Wire (parms defaulted)
* Setters for value, history, and drives
* Getters for all attributes
* void printHistory() const; // useful for printing results
*/



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