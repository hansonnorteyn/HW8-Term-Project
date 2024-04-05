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

// the gates values can be 0, 1, X
// X is used to represent an unknown value
//each should handle 0,1,X


char Gate::evaluate() const
{
    char input1Value = input1->getValue();
    char input2Value = input2->getValue();
    char outputValue = output->getValue();

    if (type == "AND")
    {
        if (input1Value == '0' || input2Value == '0')
        {
            return '0';
        }
        else if (input1Value == '1' && input2Value == '1')
        {
            return '1';
        }
        else if( input1Value == 'X' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '1' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '0' )
        {
            return '0';
        }
        else if( input1Value == '1' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == '0' && input2Value == 'X' )
        {
            return '0';
        }
    }
    else if( type == "OR" )
    {
        if (input1Value == '1' || input2Value == '1')
        {
            return '1';
        }
        else if (input1Value == '0' && input2Value == '0')
        {
            return '0';
        }
        else if( input1Value == 'X' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '1' )
        {
            return '1';
        }
        else if( input1Value == 'X' && input2Value == '0' )
        {
            return 'X';
        }
        else if( input1Value == '1' && input2Value == 'X' )
        {
            return '1';
        }
        else if( input1Value == '0' && input2Value == 'X' )
        {
            return 'X';
        }
    }
    else if( type == "NOT" )
    {
        if( input1Value == '1' )
        {
            return '0';
        }
        else if( input1Value == '0' )
        {
            return '1';
        }
        else if( input1Value == 'X' )
        {
            return 'X';
        }
    }
    else if( type == "NAND" )
    {
        if( input1Value == '0' || input2Value == '0' )
        {
            return '1';
        }
        else if( input1Value == '1' && input2Value == '1' )
        {
            return '0';
        }
        else if( input1Value == 'X' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '1' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '0' )
        {
            return '1';
        }
        else if( input1Value == '1' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == '0' && input2Value == 'X' )
        {
            return '1';
        }
    }
    else if( type == "NOR" )
    {
        if( input1Value == '1' || input2Value == '1' )
        {
            return '0';
        }
        else if( input1Value == '0' && input2Value == '0' )
        {
            return '1';
        }
        else if( input1Value == 'X' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '1' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '0' )
        {
            return '1';
        }
        else if( input1Value == '1' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == '0' && input2Value == 'X' )
        {
            return '1';
        }

    }
    else if( type == "XOR" )
    {
        if( input1Value == '1' && input2Value == '0' )
        {
            return '1';
        }
        else if( input1Value == '0' && input2Value == '1' )
        {
            return '1';
        }
        else if( input1Value == '1' && input2Value == '1' )
        {
            return '0';
        }
        else if( input1Value == '0' && input2Value == '0' )
        {
            return '0';
        }
        else if( input1Value == 'X' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '1' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '0' )
        {
            return 'X';
        }
        else if( input1Value == '1' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == '0' && input2Value == 'X' )
        {
            return 'X';
        }
    }
    else if( type == "XNOR" )
    {
        if( input1Value == '1' && input2Value == '0' )
        {
            return '0';
        }
        else if( input1Value == '0' && input2Value == '1' )
        {
            return '0';
        }
        else if( input1Value == '1' && input2Value == '1' )
        {
            return '1';
        }
        else if( input1Value == '0' && input2Value == '0' )
        {
            return '1';
        }
        else if( input1Value == 'X' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '1' )
        {
            return 'X';
        }
        else if( input1Value == 'X' && input2Value == '0' )
        {
            return 'X';
        }
        else if( input1Value == '1' && input2Value == 'X' )
        {
            return 'X';
        }
        else if( input1Value == '0' && input2Value == 'X' )
        {
            return 'X';
        }

    }
    

    
}

