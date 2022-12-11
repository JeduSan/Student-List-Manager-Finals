#include <iostream>
#include <string>
#include "student.hpp"
#include "fileUtils.hpp"

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::ws;
using std::cerr;

void Student::inputInfo(int infoType){ // Info types: Name (1), ID no. (2)
    string info;
    string *tmp;

    if (infoType == 1){
        info = "Name";
        tmp = &this->name;
    } 
    else if (infoType == 2){
        info = "ID number";
        tmp = &this->id;
    }
    else {
        cerr << "Invalid Info Type!\n";
        return;
    }    
    
    cout << "\nInput " << info << ": ";
    getline(cin >> ws, *tmp); // will insert the data to name or id
}
