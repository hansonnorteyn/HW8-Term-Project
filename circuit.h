
/*
Create a class with the following properties:
parse the curicuit file like this one:
CIRCUIT SimpleCircuit
INPUT   A    1
INPUT   B    2
OUTPUT  C    3
AND     2ns  1   2   3

this gates the wires, names, gates and delays 
write corresponding function

parse the file also to gate the time and value an input has an a given time 
VECTOR SimpleCircuit
INPUT A  0  0
INPUT B  0  0
INPUT A  4  1
INPUT B  5  1
*/

// do this for the ciruit class

/*
Parse circuit file to create in-memory data structure of Gates and Wires to simulate
Parse the vector file to initialize the simulation Queue with initial Wire state (i.e., value) changes 
Simulate the circuit using Event-driven control by
Removing the top Event e in the Queue
Determining if e causes a future Wire state change
Create and queue any future Wire state changes as new Events
Apply e’s effects
Print the results of the simulation

*/

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
using namespace std;

class Circuit
{
private:
    string name;
    vector<Wire *> wires;
    vector<Gate *> gates;
    queue<pair<int, Wire *>> simulationQueue;
    

public:
    Circuit(string name);
    void parseCircuitFile(string filename);
    void parseVectorFile(string filename);
    void simulate();
    void printResults();
};

