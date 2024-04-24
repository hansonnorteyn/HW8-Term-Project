// implement the circuit class

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include "gate.h"
#include "wire.h"
#include "circuit.h"
using namespace std;


Circuit::Circuit(string name)
{
    this->name = name;
}
void Circuit::parseCircuitFile(string filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string type;
        iss >> type;
        if (type == "INPUT")
        {
            string name;
            int index;
            iss >> name >> index;
            Wire *wire = new Wire(name, index);
            wires.push_back(wire);
        }
        else if (type == "OUTPUT")
        {
            string name;
            int index;
            iss >> name >> index;
            Wire *wire = new Wire(name, index);
            wires.push_back(wire);
        }
        else
        {
            int delay, input1Index, input2Index, outputIndex;
            iss >> delay >> input1Index >> input2Index >> outputIndex;
            Gate *gate = new Gate(type, delay, wires[input1Index], wires[input2Index], wires[outputIndex]);
            gates.push_back(gate);
        }
    }
}

void Circuit::parseVectorFile(string filename)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string type;
        iss >> type;
        if (type == "INPUT")
        {
            string name;
            int time;
            char value;
            iss >> name >> time >> value;
            for (Wire *wire : wires)
            {
                if (wire->getName() == name)
                {
                    wire->setValue(value);
                    simulationQueue.push({time, wire});
                }
            }
        }
    }
};



/*
Wire traces:
A:____----

B:_____---

c:xx_____-

  01234567

*/


// print value should look like this

/*
simulate needs to do this 
_ = 0, - = 1, x = X
Wire traces:
A:____----

B:_____---

c:xx_____-

  01234567

*/

void Circuit::simulate()
{
    while (!simulationQueue.empty())
    {
        pair<int, Wire *> event = simulationQueue.front();
        simulationQueue.pop();
        int time = event.first;
        Wire *wire = event.second;
        char value = wire->getValue();
        for (Gate *gate : gates)
        {
            if (gate->getInput1() == wire || gate->getInput2() == wire)
            {
                char input1Value = gate->getInput1()->getValue();
                char input2Value = gate->getInput2()->getValue();
                char outputValue = gate->evaluate(input1Value, input2Value);
                if (outputValue != gate->getOutput()->getValue())
                {
                    gate->getOutput()->setValue(outputValue);
                    simulationQueue.push({time + gate->getDelay(), gate->getOutput()});
                }
            }
        }
    }
}



void Circuit::printResults()
{
    map<int, map<string, char>> wireValues;
    for (Wire *wire : wires)
    {
        wireValues[wire->getIndex()][wire->getName()] = wire->getValue();
    }
    for (auto &entry : wireValues)
    {
        int index = entry.first;
        cout << "Wire traces:" << endl;
        for (auto &entry : entry.second)
        {
            string name = entry.first;
            char value = entry.second;
            cout << name << ":";
            for (int i = 0; i < index; i++)
            {
                cout << (i < index - 1 ? (value == 'X' ? 'x' : '_') : (value == 'X' ? 'x' : '-'));
            }
            cout << endl;
        }
    }
}



