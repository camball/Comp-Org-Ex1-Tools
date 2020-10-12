//
//  CompOrgTools.hpp
//  Comp-Org-Ex1-Tools
//
//  Created by Cameron Ball on 10/10/20.
//

#ifndef CompOrgTools_h
#define CompOrgTools_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::string;


class CPU_Time {
public:
    CPU_Time() : instCount{0}, CPI{0}, clockRate{0}, unit{""} {} // constructor
    
    // public member functions
    uint64_t compute(uint64_t, int, int, string);
    void showWorkAndCompute();
    
private:
    uint64_t instCount = 0;
    int CPI = 0;
    int clockRate = 0;
    string unit = "";
    
    uint64_t toStdUnit(int, string); // aux function. Converts a number like "2 GHz" to 2 * 10^9.
    void showUnits();
};

void MFLOPSrating();
void rateToPeriod(); // not finished
void periodToRate(); // not started

void showRates();
void showPeriods();
double toStdUnit(float, string);
int findExponent(string);

unsigned GetNumberOfDigits (unsigned i); // from https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer - gets num of digits in number

#endif /* CompOrgTools_hpp */
