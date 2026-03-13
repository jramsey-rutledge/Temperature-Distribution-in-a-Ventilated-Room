#include "caseType.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;


// function definitions
int caseType::readInt( ifstream& infile ) {
    int value;
    string line;
    getline(infile, line);
    stringstream(line) >> value;
    return value;
}

double caseType::readDouble( ifstream& infile ) {
    double value;
    string line;
    getline(infile, line);
    stringstream(line) >> value;
    return value;
}

void caseType::read(){
    ifstream infile;
    infile.open("Case.inp");

    if (!infile) {
        cout << "Error opening File\n";
        exit(1);
    }

    rho = readDouble(infile);
    cp = readDouble(infile);
    k = readDouble(infile);
    h = readDouble(infile);
    Td = readDouble(infile);
    Text = readDouble(infile);
    A = readDouble(infile);
    bx = readDouble(infile);
    by = readDouble(infile);
    src = readInt(infile);
    xh = readDouble(infile);
    yh = readDouble(infile);
    R = readDouble(infile);
    Q = readDouble(infile);

}

void caseType::disp() {
    cout << "rho = " << rho << endl;
    cout << "cp = " << cp << endl;
    cout << "k = " << k << endl;
    cout << "h = " << h << endl;
    cout << "Td = " << Td << endl;
    cout << "Text = " << Text << endl;
    cout << "A = " << A << endl;
    cout << "bx = " << bx << endl;
    cout << "by = " << by << endl;
    cout << "src = " << src << endl;
    cout << "xh = " << xh << endl;
    cout << "yh = " << yh << endl;
    cout << "R = " << R << endl;
    cout << "Q = " << Q << endl;
}
