//
//  CompOrgTools.cpp
//  Comp-Org-Ex1-Tools
//
//  Created by Cameron Ball on 10/10/20.
//

#include "CompOrgTools.h"

unsigned GetNumberOfDigits (unsigned i) { return i > 0 ? (int) log10 ((double) i) + 1 : 1; }

uint64_t CPU_Time::compute(uint64_t instCount = 0, int CPI = 0, int clockRate = 0, string unit = "") {
    
    uint64_t denom = toStdUnit(clockRate, unit);
    uint64_t output = 0;
    
    if (denom > 0) output = (instCount * CPI)/denom; // to avoid crash from divide by zero
    
    return output;
}

uint64_t CPU_Time::toStdUnit(int magnitude = 0, string unit = "")
{
    int exponent = 0;
    
    if ( unit == "milli" ) exponent = -3;       // milli
    else if ( unit == "micro" ) exponent = -6;  // micro
    else if ( unit == "nano" ) exponent = -9;   // nano
    else if ( unit == "pico" ) exponent = -12;  // pico
    else if ( unit == "femto" ) exponent = -15; // femto
    else if ( unit == "kilo"  )exponent = 3;    // kilo
    else if ( unit == "mega" ) exponent = 6;    // mega
    else if ( unit == "giga" ) exponent = 9;    // giga
    else if ( unit == "tera" ) exponent = 12;   // tera
    else if ( unit == "peta" ) exponent = 15;   // peta
    else return 0;
    
    return magnitude * pow(10, exponent);
}

void CPU_Time::showWorkAndCompute()
{
    uint64_t userinstCount = 0;
    int userCPI = 0;
    int userclockRate = 0;
    string userunit = "";
    
    cout << "Enter instruction count (>= 0): ";
    bool check = 0;
    while (check == 0) { // making sure instruction count is not negative
        cin >> userinstCount;
        if (userinstCount >= 0)
            check = 1;
        else cout << "Error: Please enter a number equal to or greater than zero: ";
    }
    cout << "Enter cycles per instruction (CPI): ";
    cin >> userCPI;
    cout << "Enter clock rate magnitude (i.e., if \"2 Ghz\" is the clock rate, enter '2'): ";
    cin >> userclockRate;
    cout << "Enter clock rate unit (i.e., if \"2 Ghz\" is the clock rate, enter 'giga')\n\n";
    showUnits();
    cout << " > ";
    cin >> userunit;
    cout << std::endl;
    
    uint64_t finalValue = this->compute(userinstCount, userCPI, userclockRate, userunit); // final output computation
    
    if (finalValue == 0) {
        cout << "ERROR: Bad calculation. Likely a divide by zero error. Check your input values.";
    } else {
        string dashes = "--";
        int digits = GetNumberOfDigits(userinstCount) + 4 + GetNumberOfDigits(userCPI);
        
        for (int i = 0; i < digits; i++)
            dashes += "-";

        cout << "             Instruction Count * CPI         " << userinstCount << " * " << userCPI << "       " << userinstCount << " * " << userCPI << '\n';
        cout << "CPU Time =  -------------------------   =   " << dashes << "  =  " << dashes << " = " << finalValue << " seconds\n";
        cout << "                    Clock Rate                " << "\t" << userclockRate << ' ' << userunit << "[unit]\t\t" << toStdUnit(userclockRate, userunit);
    }
    cout << std::endl;
}

void CPU_Time::showUnits()
{
    cout << "Options: \n";
    cout << "\tmilli\n"; // milli
    cout << "\tmicro\n"; // micro
    cout << "\tnano\n";  // nano
    cout << "\tpico\n";  // pico
    cout << "\tfemto\n"; // femto
    cout << "\tkilo\n";  // kilo
    cout << "\tmega\n";  // mega
    cout << "\tgiga\n";  // giga
    cout << "\ttera\n";  // tera
    cout << "\tpeta\n";  // peta
    cout << '\n';
}

void MFLOPSrating(){
    uint64_t instCount = 0;
    int secs = 0;
    float percentage = 0;
    
    double output = 0;

    cout << "Enter how many instructions are executed (e.g., 100000000): ";
    cin >> instCount;

    cout << "Enter how long it takes to execute those instructions in seconds (e.g., 5): ";
    cin >> secs;

    cout << "Enter the percentage of instructions executed that do NOT perform floating-point operations (i.e., 70).\nIf all instructions are fp-ops, enter 100: ";
    cin >> percentage;
    
    int num = roundf(100-percentage) / 10; // this function deals with error, which is why it is programmed this way.
    int flops = (instCount * num) / 10;
    
    uint64_t denom = secs * pow(10, 6);
    
    cout << std::fixed << std::setprecision(0);
    
    if ( !(denom > 0) ) {
        cout << "Divide by zero error.\n";
        // abort statement goes here
    } else {
        output = flops/denom;
    
        string dashes = "--";
        int digits = GetNumberOfDigits(flops);
        
        for (int i = 0; i < digits; i++)
            dashes += "-";
        
        cout << "         Floating Point Operations\n";
        cout << "MFLOPS = -------------------------\n";
        cout << "           Execution Time * 10^6  \n\n";
        
        if (percentage < 100) // if percentage is 100, this calculation doesn't need to be shown
            cout << "Floating Point Operations = " << instCount << " * " << percentage << "% = " << flops << "\n\n";
        
        cout << "          " << flops << "       " << flops << '\n';
        cout << "MFLOPS = " << dashes << "  =  " << dashes << "  =  " << output << '\n';
        cout << "          " << secs << " * 10^6       " << denom << '\n';
    }
}

void rateToPeriod()
{
    float rate = 0;
    float period = 0;
    string rateUnit;
    string periodUnit;
    
    cout << "Enter Clock Rate: ";
    cin >> rate;
    
    cout << "Enter Clock Rate Unit: \n\n";
    showRates();
    cout << " > ";
    cin >> rateUnit;
    
    cout << "Enter Clock Period Unit: \n\n";
    showPeriods();
    cout << " > ";
    cin >> periodUnit;
    
    string dashes = "--";
    int digits = GetNumberOfDigits(rate);
    
    for (int i = 0; i < digits; i++)
        dashes += "-";
    
    float r = toStdUnit(rate, rateUnit);
    
    // gave up here. Tired of programming this when there's one already available online lol. Gave up during converting back and forth between the units entered.
    period = 1/(r/findExponent(rateUnit));
    
    cout << std::fixed << std::setprecision(5); // don't output in scientific notation. output to five decimal places. 
    
    cout << period;
    
    /*
    cout << "                     1           1" << '\n';
    cout << "Clock Period = ------------ = " << dashes << '\n';
    cout << "                Clock Rate    " << << '\n';
     */
}

void periodToRate()
{
    
}

void showRates()
{
    cout << "Options: \n";
    cout << "\tkilo\n";  // kilo
    cout << "\tmega\n";  // mega
    cout << "\tgiga\n";  // giga
    cout << "\ttera\n";  // tera
    cout << "\tpeta\n";  // peta
    cout << '\n';
}

void showPeriods()
{
    cout << "Options: \n";
    cout << "\tmilli\n"; // milli
    cout << "\tmicro\n"; // micro
    cout << "\tnano\n";  // nano
    cout << "\tpico\n";  // pico
    cout << "\tfemto\n"; // femto
    cout << '\n';
}

double toStdUnit(float magnitude = 0, string unit = "")
{
    float exponent = 0;
    
    if ( unit == "milli" ) exponent = -3;       // milli
    else if ( unit == "micro" ) exponent = -6;  // micro
    else if ( unit == "nano" ) exponent = -9;   // nano
    else if ( unit == "pico" ) exponent = -12;  // pico
    else if ( unit == "femto" ) exponent = -15; // femto
    else if ( unit == "kilo"  )exponent = 3;    // kilo
    else if ( unit == "mega" ) exponent = 6;    // mega
    else if ( unit == "giga" ) exponent = 9;    // giga
    else if ( unit == "tera" ) exponent = 12;   // tera
    else if ( unit == "peta" ) exponent = 15;   // peta
    else return 0;
    
    return magnitude * pow(10, exponent);
}

int findExponent(string unit = "")
{
    float exponent = 0;
    
    if ( unit == "milli" ) exponent = -3;       // milli
    else if ( unit == "micro" ) exponent = -6;  // micro
    else if ( unit == "nano" ) exponent = -9;   // nano
    else if ( unit == "pico" ) exponent = -12;  // pico
    else if ( unit == "femto" ) exponent = -15; // femto
    else if ( unit == "kilo"  )exponent = 3;    // kilo
    else if ( unit == "mega" ) exponent = 6;    // mega
    else if ( unit == "giga" ) exponent = 9;    // giga
    else if ( unit == "tera" ) exponent = 12;   // tera
    else if ( unit == "peta" ) exponent = 15;   // peta
    else return 0;
    
    return exponent;
}

