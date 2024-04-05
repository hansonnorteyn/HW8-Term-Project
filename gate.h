/*********************************************************
 * Summary: This is the header file for the Gate class
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

class Wire;

class Gate
{
private:
    string type;
    int delay;
    Wire *input1;
    Wire *input2;
    Wire *output;

public:
    Gate(string type, int delay, Wire *input1, Wire *input2, Wire *output);
    int getDelay() const;
    Wire *getInput1() const;
    Wire *getInput2() const;
    Wire *getOutput() const;

    // evaluate should have parameters, and should return a char, the parmeter are name of the input wire, and the value of the input wire
    //  defualted to X and name to ""

    char evaluate(char inputValue1 = 'X', char inputValue2 = 'X') const;
};
