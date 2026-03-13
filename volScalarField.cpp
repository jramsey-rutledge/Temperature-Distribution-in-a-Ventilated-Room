// Libraries
#include "meshType.h"
#include "volScalarField.h"
#include <string>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

// volScalarField member functions defined
void volScalarField::allocate(const meshType& Mesh) {
    Nx = Mesh.Nx;
    Ny = Mesh.Ny;
    Ntot = (Nx+2)*(Ny+2);
    values.assign(Ntot, 0.0);
}

double volScalarField::get(int i, int j) const {
    return values[i+j*(Nx+2)];
}

void volScalarField::set(int i, int j, double val) {
    values[i+j*(Nx+2)] = val;
}

void volScalarField::Save() {
    std::string filename = "T_" + std::to_string(Nx) + ".dat";
    std::ofstream cfile(filename);
    for (int i = 0; i < Ntot; i++) {cfile << values[i] << "\n";}
    cfile.close();
}

// west boundary condition
void volScalarField::BCw( double y, double t, double& a, double& b, double& g) const {
    double h = 0.1;
    double Text = 260.0;
    double k = 0.026;

    if (y >= 3.0 && y <= 4.0)   // window
    {
        a = h;
        b = k;
        g = h * Text;
    }
    else   // insulated wall
    {
        a = 0.0;
        b = 1.0;
        g = 0.0;
    }
    t=t;
}

// east boundary condition
void volScalarField::BCe( double y, double t, double& a, double& b, double& g) const {
    a = 0.0; // coefficient multiplying T
    b = 1.0; // coefficient multiplying dT / dx
    g = 0.0; // prescribed value
    t=t;
    y=y;
}

// north boundary condition
void volScalarField::BCn( double x, double t, double& a, double& b, double& g) const {
    double h = 0.1;
    double Text = 260.0;
    double k = 0.026;

    if (x >= 3.5 && x <= 4.5)   // window
    {
        a = h;
        b = k;
        g = h * Text;
    }
    else   // insulated wall
    {
        a = 0.0;
        b = 1.0;
        g = 0.0;
    }
    t=t;
}

// south boundary condition
void volScalarField::BCs( double x, double t, double& a, double& b, double& g) const {
    double Td = 300.0;

    if (x >= 1.0 && x <= 1.8)   // door
    {
        a = 1.0;
        b = 0.0;
        g = Td;
    }
    else   // insulated wall
    {
        a = 0.0;
        b = 1.0;
        g = 0.0;
    }
    t=t;
}