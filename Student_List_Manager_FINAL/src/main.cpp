#include <iostream>
#include "fileUtils.hpp"
#include "menu.hpp"
#include "security.hpp"

// NOTES:
// - It is important to sort the name and id together even if it's slow
// - [COMMON FLOW IN THE PROGRAM] file >> vector >> action >> file
// - Default pass is 1234, unless changed
// - The other notes are scattered here somewhere ;-;

// [COMPILE] g++ src/main.cpp src/menu.cpp src/algos.cpp src/fileUtils.cpp src/student.cpp src/security.cpp -I includes -o src/main
// [RUN] ./src/main

int main() {
    createDB(nameDB);
    createDB(idDB);
    createDB(keyContainer);
    // encrypt files after creation, for debug only, comment this after encrypting the file
    // encrypt(idDB);
    // encrypt(nameDB);

    home();
    // for login
    if (login() == true)
        cout << "\nAccess granted :P\n\n";
    else // exit program when key is wrong
    {
        cout << "\n\nAccess denied...\n\n";
        return 1;
    }
    system("pause");

    // decrypt files at runtime of the menu
    decrypt(idDB);
    decrypt(nameDB);

    menu();

    // encrypt files at exit
    encrypt(idDB);
    encrypt(nameDB);

    return 0;
}