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
using namespace std;

class Gate;

class Wire
{
public:
    Wire(string name = "",int index = 0);
    void setValue(int value);
    void setName(string name);
    void setDrives(vector<Gate *> drives);
    void setIndex(int index);
    void setHistory(vector<string> history);
    char getValue() const;
    string getName() const;
    vector<Gate *> getDrives() const;
    int getIndex() const;
    vector<string> getHistory() const;
    void printHistory() const;

private:
    char value;
    string name;
    vector<Gate *> drives;
    int index;
    vector<string> history;
};