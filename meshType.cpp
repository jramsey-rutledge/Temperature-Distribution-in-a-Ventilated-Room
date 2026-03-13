#include "meshType.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <math.h>
using namespace std;


// function definitions
int meshType::readInt( ifstream& infile ) {
    int value;
    string line;
    getline(infile, line);
    stringstream(line) >> value;
    return value;
}

double meshType::readDouble( ifstream& infile ) {
    double value;
    string line;
    getline(infile, line);
    stringstream(line) >> value;
    return value;
}

void meshType::read(){
    ifstream infile;
    infile.open("mesh.inp");

    if (!infile) {
        cout << "Error opening File\n";
        exit(1);
    }

    Nx = readInt(infile);
    Ny = readInt(infile);
    Lx = readDouble(infile);
    Ly = readDouble(infile);
}


void meshType::create(){
    dx = Lx/Nx;
    dy = Ly/Ny;

    xc.assign(Nx+2,0.0);
    for (int i=0; i<Nx+2;i++){
        xc[i] = -0.5*dx + i*dx;
    }

    yc.assign(Ny+2,0.0);
    for (int i=0; i<Ny+2;i++){
        yc[i] = -0.5*dy + i*dy;
    }

    xf.assign(Nx,0.0);
    for (int k=0; k<Nx; ++k){
        xf[k] = k * dx;
    }

    yf.assign(Ny,0.0);
    for (int k=0; k<Ny; ++k){
        yf[k] = k * dy;
    }
}

void meshType::disp(){
    cout << "Lx = " << Lx << endl;
    cout << "Ly = " << Ly << endl;
    cout << "Nx = " << Nx << endl;
    cout << "Ny = " << Ny << endl;
}

void meshType::write(){
    std::ofstream xfile("x.dat");
    for (int i = 0; i < Nx+2; i++){
        xfile << xc[i] << "\n";
    }
    xfile.close();

    std::ofstream yfile("y.dat");
    for (int i = 0; i < Ny+2; i++) {
        yfile << yc[i] << "\n";
    }
    yfile.close();
}
