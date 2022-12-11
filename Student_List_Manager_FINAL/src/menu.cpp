#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fileUtils.hpp"
#include "student.hpp"
#include "menu.hpp"
#include "algos.hpp"

using std::ofstream;
using std::cout;
using std::cin;
using std::cerr;
using std::ios;
using std::ifstream;
using std::getline;
using std::ws;
using std::vector;

void menu(){
    while (true) {
        system("cls");
        Student student;

        ofstream foutName(nameDB, ios::app | ios::out);
        ofstream foutID(idDB, ios::app | ios::out);
        ifstream finName(nameDB, ios::in);
        ifstream finID(idDB, ios::in);
    
        vector<string> names;
        vector<string> ids;

        int choice;
        
        cout << "[STUDENT INFO MANAGER]\n\n";
        cout << "[1] Add Student Info\n";
        cout << "[2] View Student List\n";
        cout << "[3] Search\n";
        cout << "[0] Exit\n";
        cout << ">> ";
        cin >> choice;
        cin.clear();
        cin.ignore();

        switch(choice) {
            case 1: // working, no touchy
            {
                system("cls");
                cout << "[Add Student Info]\n\n";
                student.inputInfo(1); // name
                student.inputInfo(2); // id
                // append on file
                foutName << student.getName() << "\n";
                foutID << student.getID() << "\n";
                // transfer file to array for sorting
                FiletoVector(names, nameDB);
                FiletoVector(ids, idDB);

                // descName_insertion_sort(ids, names);
                desc_insertion_sort(ids, names, 1);

                VectortoFile(names, nameDB);
                VectortoFile(ids, idDB);

                cout << "\nStudent Added Successfully!\n";
                system("pause");
                break;
            }
                
            case 2: // oke
            {
                system("cls");
                cout << "[View Student List]\n\n";
                cout << "View Student List by ...\n";
                cout << "[1] Name Descending order\n";
                cout << "[2] Name Ascending order\n";
                cout << "[3] ID Descending order\n";
                cout << "[4] ID Ascending order\n";
                cout << "[5] Keep List Order\n>> "; // don't sort
                cin >> choice;
                cin.clear();
                cin.ignore();

                // [FLOW] file>>list>>sort>>file>>print (except 5, no sort)
                FiletoVector(names, nameDB);
                FiletoVector(ids, idDB);
                if (choice == 1) {
                    // descName_insertion_sort(ids, names);
                    desc_insertion_sort(ids, names, 1);

                    VectortoFile(names, nameDB);
                    VectortoFile(ids, idDB);

                    printFile();
                    } else if (choice == 2) {
                        // ascName_insertion_sort(ids, names);
                        asc_insertion_sort(ids, names, 1);

                        VectortoFile(names, nameDB);
                        VectortoFile(ids, idDB);

                        printFile();
                    } else if (choice == 3) {
                        //descID_insertion_sort(ids, names);
                        desc_insertion_sort(ids, names, 2);

                        VectortoFile(names, nameDB);
                        VectortoFile(ids, idDB);

                        printFile();
                    } else if (choice == 4) {
                        // ascID_insertion_sort(ids, names);
                        asc_insertion_sort(ids, names, 2);

                        VectortoFile(names, nameDB);
                        VectortoFile(ids, idDB);

                        printFile();
                    } else if (choice == 5) {
                        VectortoFile(names, nameDB);
                        VectortoFile(ids, idDB);

                        printFile();
                    } else cerr << "ERROR: Invalid Input!\n";
                system("pause");
                break;
            }
                
            case 3: // wip
            {
                // without these, the comparison on searchAction() won't work
                const char mode1[] = "ID Number";
                const char mode2[] = "Name";

                string findThis, searchFor; // 'findThis' == the element to find, 'searchFor' == id or name
                int index;
                
                system("cls");
                cout << "Search for [1] ID Number or [2] Name:\n>> ";
                cin >> choice;
                cin.clear();
                cin.ignore();
                cout << "\n";
                
                if (choice == 1) { // for id, working
                    FiletoVector(ids, idDB); // fill the vector with contents b4 searching
                    FiletoVector(names, nameDB);

                    // descID_insertion_sort(ids, names); // sort the data first just in case it isn't
                    desc_insertion_sort(ids, names, 2);

                    VectortoFile(names, nameDB);
                    VectortoFile(ids, idDB);

                    cout << "Input ID Number: ";
                    getline(cin, findThis);
                    system("cls");
                    index = bsearch(ids, findThis, "[ID NUMBER]: ");
                    if (index != -1) {
                        cout << "[NAME]:\t" << names[index] << "\n";
                        searchAction(names, ids, index, mode1);
                    }
                } else if (choice == 2) { // for name, works [LIMITATION] Only works if the whole name is entered (Zoey Cordova), not (Zoey or Cordova)
                    FiletoVector(ids, idDB);
                    FiletoVector(names, nameDB);

                    // descName_insertion_sort(ids, names);
                    desc_insertion_sort(ids, names, 1);

                    VectortoFile(names, nameDB);
                    VectortoFile(ids, idDB);

                    cout << "Input Name: ";
                    getline(cin, findThis);
                    system("cls");
                    index = bsearch(names, findThis, "[NAME]:\t");
                    if (index != -1) {
                        cout << "[ID NUMBER]: " << ids[index] << "\n";
                        searchAction(names, ids, index, mode2);
                    }
                        
                }   
                system("pause");
                break;
            }
            case 0: // oke
                cout << "\n[Program Terminated]\n";
                return;
            default: // oke
                cerr << "Invalid Input!\n";
                system("pause");
                break;
        }
    }
}