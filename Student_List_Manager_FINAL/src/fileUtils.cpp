#include <iostream>
#include <fstream>
#include <string>
#include "fileUtils.hpp"

using std::string;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::getline;
using std::cout;
using std::cin;
using std::ws;
using std::vector;
using std::ios;

const string nameDB = "names.txt";
const string idDB = "ids.txt";

bool fileExists (const string& name) { 
    ifstream file(name.c_str());
    return file.good();
}

void createDB(const string &dir) {
    if (fileExists(dir))
        return;
    else
        ofstream fout(dir);
}

void printFile() {
    ifstream finName(nameDB);
    ifstream finID(idDB);
    if (!finName.is_open() && !finID.is_open()) {
        cerr << "ERROR: Can't open file!\n";
        return;
    }
    string tmpN, tmpID;
    int i = 0;

    cout << "[No.]\t[ID NUMBER]\t\t[NAME]\n";
    cout << "_________________________________________________\n";
    while(getline(finName >> ws, tmpN) && getline(finID >> ws, tmpID)) {
        cout << i+1 << "\t";
        cout << tmpID << "\t\t";
        cout << tmpN << "\n\n";
        i++;
    }

    finID.close();
    finName.close();
}

void FiletoVector(vector<string>& vec, const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "ERROR: Can't open file!\n";
        return;
    }
    string tmp;

    while (getline(fin >> ws, tmp)) {
        vec.push_back(tmp);
    }
}

void VectortoFile(vector<string>& vec, const string& filename) {
    ofstream fout(filename); // will overwrite the file
    if (!fout.is_open()) {
        cerr << "ERROR: Can't open file!\n";
        return;
    }
    for (int i = 0; i < vec.size(); i++) 
        fout << vec[i] << "\n";
        
    fout.close();
}

void searchAction(vector<string>& names, vector<string>& ids, int& index, const char* mode) { // modes: id, name
    string id = "ID Number";
    string nm = "Name";
    string info;
    int choice;
    
    cout << "\nChoose an action:\n";
    cout << "[1] Update Info\n"; 
    cout << "[2] Delete Student\n";
    cout << "[0] Exit\n>> ";
    cin >> choice;
    cin.clear();
    cin.ignore();

    system("cls");
    if (choice == 1) { // update info, id/name
        cout << "\nWhich to update? [1] ID Number or [2] Name:\n>> ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "\nInput new ID Number:\n>> ";
            getline(cin >> ws, info);
            ids.at(index) = info;
            VectortoFile(ids, idDB);
        } else if (choice == 2) {
            cout << "\nInput new Name:\n>> ";
            getline(cin >> ws, info);
            names.at(index) = info;
            VectortoFile(names, nameDB);
        }
    } else if (choice == 2) { // delete student, working
        ids.erase(ids.begin()+index);
        names.erase(names.begin()+index);
        VectortoFile(ids, idDB);
        VectortoFile(names, nameDB);
    } else if (choice == 0)
        return;
    cout << "\n~ Success!\n";
}