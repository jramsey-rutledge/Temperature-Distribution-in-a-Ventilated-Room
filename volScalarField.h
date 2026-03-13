// header file

// header guards
#ifndef VOLSCALARFIELD_H
#define VOLSCALARFIELD_H

// libraries
#include <vector>
#include "meshType.h"

// Define volScalarField structure
struct volScalarField {
    int Nx, Ny;                   // grid resolution
    int Ntot;                     // total number of nodes
    std::vector<double> values;   // scalar field values

    void allocate(const meshType& Mesh);

    double get(int i, int j) const ;

    void set(int i, int j, double val) ;

    // west boundary condition
    void BCw( double y, double t, double& a, double& b, double& g ) const;

    // east boundary condition
    void BCe( double y, double t, double& a, double& b, double& g ) const;

    // north boundary condition
    void BCn( double x, double t, double& a, double& b, double& g ) const;

    // south boundary condition
    void BCs( double x, double t, double& a, double& b, double& g ) const;


    void Save() ;
};

#endif