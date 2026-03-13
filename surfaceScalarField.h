// header file

// header guards
#ifndef SURFACESCALARFIELD_H
#define SURFACESCALARFIELD_H

// libraries
#include <vector>
#include "meshType.h"

// Define surfaceScalarField structure
struct surfaceScalarField {
    int Nx, Ny;
    std::vector<double> phix; // fluxes on east/west faces
    std::vector<double> phiy; // fluxes on north/south faces

    void allocate(const meshType& Mesh);

    double getw(int i, int j) const ;

    double gete(int i, int j) const ;

    double getn(int i, int j) const ;

    double gets(int i, int j) const ;
};

#endif
