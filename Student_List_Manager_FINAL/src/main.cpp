#include <iostream>
#include "fileUtils.hpp"
#include "menu.hpp"

// NOTES:
// - It is important to sort the name and id together even if it's slow
// - [COMMON FLOW IN THE PROGRAM] file >> vector >> action >> file
// - The other notes are scattered here somewhere ;-;

// [COMPILE] g++ src/main.cpp src/menu.cpp src/algos.cpp src/fileUtils.cpp src/student.cpp -I includes -o src/main
// [RUN] ./src/main

int main() {
    createDB(nameDB);
    createDB(idDB);

    menu();

    return 0;
}