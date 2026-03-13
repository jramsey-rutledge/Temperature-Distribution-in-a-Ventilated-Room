// Libraries
#include "meshType.h"
#include "surfaceScalarField.h"
#include <string>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

// Defining surfaceScalarField member functions
void surfaceScalarField::allocate(const meshType& Mesh){
    Nx = Mesh.Nx;
    Ny = Mesh.Ny;
    phix.assign((Nx+1)*Ny,0.0);
    phiy.assign(Nx*(Ny+1),0.0);
}

double surfaceScalarField::getw(int i, int j) const {
    return phix[i-1 + (j-1)*(Nx+1)];
}

double surfaceScalarField::gete(int i, int j) const {
    return phix[i+(j-1)*(Nx+1)];
}

double surfaceScalarField::getn(int i, int j) const {
    return phiy[(i-1)+j*Nx];
}

double surfaceScalarField::gets(int i, int j) const {
    return phiy[(i-1)+(j-1)*Nx];
}