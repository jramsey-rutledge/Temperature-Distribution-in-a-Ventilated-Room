/* MEGN 651: Cooling of a Nuclear Fuel Rod
 *
 * Author: Jenna Ramsey-Rutledge
 * Resources used CPP Companion Textbook, CSCI200 Course Website, Asking ChatGPT how to handle header files that depend on one another, 
 * 
 * In this code, we build a simulation for temperature change in a room with a ceiling fan.
 */

// Libraries
#include "caseType.h"
#include "meshType.h"
#include "matrixType.h"
#include "volScalarField.h"
#include "surfaceScalarField.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath> 
#include <vector>


using namespace std;


// Compute velocity component 
double compU(double x, double y, const meshType& Mesh, const caseType& Case){
    return -(Case.A/(Case.by*Mesh.Ly))*std::sin((2*M_PI*x)/(Case.bx*Mesh.Lx))*std::cos((2*M_PI*y)/(Case.by*Mesh.Ly));
}

double compV(double x, double y, const meshType& Mesh, const caseType& Case){
    return (Case.A/(Case.bx*Mesh.Lx))*std::cos((2*M_PI*x)/(Case.bx*Mesh.Lx))*std::sin((2*M_PI*y)/(Case.by*Mesh.Ly));
}

// Source Function
double f(double x, double y, const meshType& Mesh, const caseType& Case) {
    double u = compU(x, y, Mesh, Case);
    double v = compV(x, y, Mesh, Case);

    return 2 * Case.k * cos(x) * cos(y) - Case.rho * Case.cp * (u * sin(x) * cos(y) + v * cos(x) * sin(y));
}

// Compute fluxes on east/west faces
void computePhix(surfaceScalarField& flux, const meshType& Mesh, const caseType& Case){
    int Nx = Mesh.Nx;
    int Ny = Mesh.Ny;
    for (int i=0; i<=Nx; i++){
        for (int j=0; j<Ny; j++){
            double x = Mesh.xf[i];
            double y = Mesh.yc[j+1];
            flux.phix[i+j*(Nx+1)] = Case.rho*compU(x,y,Mesh,Case);
        }
    }
}

// Compute fluxes on north/south faces
void computePhiy(surfaceScalarField& flux, const meshType& Mesh, const caseType& Case){
    int Nx = Mesh.Nx;
    int Ny = Mesh.Ny;
    for (int i=0; i<Nx; i++){
        for (int j=0; j<=Ny; j++){
            double x = Mesh.xc[i+1];
            double y = Mesh.yf[j];
            flux.phiy[i+j*Nx] = Case.rho*compV(x,y,Mesh,Case); 
        }
    }
}


// Main Function
int main() {

    // Create Case
    caseType Case;
    Case.read();
    Case.disp();

    // Create Mesh
    meshType Mesh; 
    Mesh.read();
    Mesh.disp();
    Mesh.create();
    Mesh.write();

    // Create flux
    surfaceScalarField flux;
    flux.allocate(Mesh);
    computePhix(flux,Mesh,Case);
    computePhiy(flux,Mesh,Case);

    // Create Matrix A and RHS vector
    volScalarField T;  // declare the temp fiels
    T.allocate(Mesh);  // initialize the fiels

    matrixType Matrix;               // declare the matrix problem 
    Matrix.init(Mesh);               // initialize matrix
    Matrix.BuildA(Mesh,Case,flux,T);   // build matrix
    Matrix.BuildRHS(Mesh,Case,T);      // build right hand side
    Matrix.solve(T);                 // solve using Eigen

    T.Save(); // save T field to file
return 0;
}