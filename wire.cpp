/*********************************************************
 * Summary: This files contains the implementation of the wire class
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
#include "wire.h"
using namespace std;

Wire::Wire(int value, string name, vector<Gate *> drives, int index, vector<string> history)
{
    this->value = value;
    this->name = name;
    this->drives = drives;
    this->index = index;
    this->history = history;
};

void Wire::setValue(int value)
{
    this->value = value;
}

void Wire::setName(string name)
{
    this->name = name;
}

void Wire::setDrives(vector<Gate *> drives)
{
    this->drives = drives;
}

void Wire::setIndex(int index)
{
    this->index = index;
}

void Wire::setHistory(vector<string> history)
{
    this->history = history;
}

int Wire::getValue() const
{
    return value;
}

string Wire::getName() const
{
    return name;
}

vector<Gate *> Wire::getDrives() const
{
    return drives;
}

int Wire::getIndex() const
{
    return index;
}

vector<string> Wire::getHistory() const
{
    return history;
}

void Wire::printHistory() const
{
    for (string s : history)
    {
        cout << s << endl;
    }
}
