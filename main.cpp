// implement main that combimes the two files into one

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

int main()
{
    string circuitFile;
    cout << "Enter the name of the base circuit file: ";
    cin >> circuitFile;

    string vectorFile = circuitFile + "_v.txt";

    Circuit circuit(circuitFile);
    circuit.parseCircuitFile(circuitFile);
    circuit.parseVectorFile(vectorFile);
    circuit.simulate();
    circuit.printResults();

    return 0;
}