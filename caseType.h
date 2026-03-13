// header file
// header guards
#ifndef CASETYPE_H
#define CASETYPE_H

#include <fstream>

// structure definitons
struct caseType {
    double rho, cp, k, h;  // material properties
    double Td, Text;      // boundary temperatures
    double A, bx, by;   // velocity field parameters
    int src;            // source-term flag
    double xh, yh, R, Q; // heater parameters

//function prototypes
/**
 * @brief helper function that reads a file and saves a line without
 * the description as an integer
 * 
 * @param infile file being read
 */
int readInt( std::ifstream& infile);

/**
 * @brief helper function that reads a file and saves a line without
 * the description as a double
 * 
 * @param infile file being read
 */
double readDouble( std::ifstream& infile);

/**
 * @brief function to read inputs from a file
 * 
 * @param Case
 */
void read();


/**
 * @brief function to display all case inputs to the 
 * terminal in a readable format
 * c
 * @param Case 
 */
void disp();

};


#endif