#include "Registrar.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv){
    string fileName = "";
    if (argc > 1){ // typing more than one argument, then use the imput from the command line (file name)
        fileName = argv[1];
    }
    ifstream infile;
    infile.open(fileName.c_str()); // reading file
    while(infile.fail()){ // error checking the file
        cout << "Could not open file. Please try again." << endl;
        cout << "Please enter the path of the file you wish to read from:" << endl;
        cin >> fileName;
        infile.open(fileName.c_str());
        if(infile.is_open()){
            break;
        }
    }
    int w = 0;
    infile >> w;
    Registrar r(w);
    r.simulation(fileName);

    infile.close();

    return 0;
}
