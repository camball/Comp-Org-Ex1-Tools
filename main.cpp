//
//  main.cpp
//  Comp-Org-Ex1-Tools
//
//  Created by Cameron Ball on 10/10/20.
//

#include <iostream>
#include "CompOrgTools.h"

using std::cout;
using std::cin;

void showMenu();

int main() {
    showMenu();
    char input;
    bool flag1 = 1; // this flag controls the loop
    bool flag2 = 1; // this flag controls which programs output the "Program Ended" message
    while (flag1 == 1) {
        cout << "Enter selection: ";
        cin >> input;
        cout << '\n';
        switch (toupper(input)) {
            case 'C': {
                CPU_Time t1; // create new CPU_Time object
                t1.showWorkAndCompute();
                cout << '\n';
                break;
            } case 'F':
                MFLOPSrating(); // void function to compute and show work for determining the MFLOPS rating.
                break;
            case 'Q': {
                flag1 = 0;
                flag2 = 0;
                break;
            } case 'M':{
                showMenu();
                flag2 = 0;
                break;
            } case 'R':
                // rateToPeriod(); // implement when finished
                break;
            case 'P':
                // periodToRate(); // implement when finished
                break;
            default:
                break;
        }
        
        if (flag2 == 1) cout << "\n\t----\t\tProgram Ended\t\t----\n\n";
    }
    cout << "Goodbye!\n";
    
    return 0;
}

void showMenu()
{
    cout << "Compute CPU Time - 'C'\n";
    cout << "Compute MFLOPS Rating - 'F'\n";
    // cout << "Convert Clock Rate to Clock Period - R\n";
    // cout << "Convert Clock Period to Clock Rate - P\n";
    cout << "Show This Menu - 'M'\n";
    cout << "Exit Program - 'Q'\n";
    cout << '\n';
}
