/*********************************************************
 * Summary: This file contains the implementation of the Gate class
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

Gate::Gate(string type, int delay, Wire *input1, Wire *input2, Wire *output)
{
    this->type = type;
    this->delay = delay;
    this->input1 = input1;
    this->input2 = input2;
    this->output = output;
}

int Gate::getDelay() const
{
    return delay;
}

Wire *Gate::getInput1() const
{
    return input1;
}

Wire *Gate::getInput2() const
{
    return input2;
}

Wire *Gate::getOutput() const
{
    return output;
}

int Gate::evaluate() const
{

    int value = -1;
    if (type == "AND")
    {
        if (input1->getValue() == 1 && input2->getValue() == 1)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }
    else if (type == "OR")
    {
        if (input1->getValue() == 1 || input2->getValue() == 1)
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }
    else if (type == "XOR")
    {
        if (input1->getValue() != input2->getValue())
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }
    else if (type == "NOT")
    {
        if (input1->getValue() == 1)
        {
            value = 0;
        }
        else
        {
            value = 1;
        }
    }
    return value;
}