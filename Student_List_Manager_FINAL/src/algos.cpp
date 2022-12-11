#include <iostream>
#include <string>
#include <cctype> // tolower()
#include <vector>
#include "algos.hpp"

using std::string;
using std::cout;
using std::tolower;
using std::isupper;
using std::cerr;
using std::vector;

void desc_insertion_sort(vector<string>& ids, vector<string>& names, const int& mode) { // modes: 1 == name, 2 == id
    for (int i = 0; i < names.size(); i++) {
        // storing current element whose left side is checked for its correct position .
        string tempN = names[i];
        string tempI = ids[i];
        int j = i;

        if (mode == 1) {
            // check whether the adjacent element in left side is greater or less than the current element.
            while (j > 0 && tempN < names[j - 1]) {
                // moving the left side element to one position forward.
                names[j] = names[j - 1];
                ids[j] = ids[j - 1];
                j = j - 1;
            }
        } else if (mode == 2) {
            // check whether the adjacent element in left side is greater or less than the current element.
            while (j > 0 && tempI < ids[j - 1]) {
                // moving the left side element to one position forward.
                names[j] = names[j - 1];
                ids[j] = ids[j - 1];
                j = j - 1;
            }
        }
        // moving current element to its  correct position.
        names[j] = tempN;
        ids[j] = tempI;
    }
}

void asc_insertion_sort(vector<string>& ids, vector<string>& names, const int& mode) { // modes: 1 == name, 2 == id
    for (int i = 0; i < names.size(); i++) {
        // storing current element whose left side is checked for its correct position .
        string tempN = names[i];
        string tempI = ids[i];
        int j = i;

        if (mode == 1) {
            // check whether the adjacent element in left side is greater or less than the current element.
            while (j > 0 && tempN > names[j - 1]) {
                // moving the left side element to one position forward.
                names[j] = names[j - 1];
                ids[j] = ids[j - 1];
                j = j - 1;
            }
        } else if (mode == 2) {
            // check whether the adjacent element in left side is greater or less than the current element.
            while (j > 0 && tempI > ids[j - 1]) {
                // moving the left side element to one position forward.
                names[j] = names[j - 1];
                ids[j] = ids[j - 1];
                j = j - 1;
            }
        }
        // moving current element to its  correct position.
        names[j] = tempN;
        ids[j] = tempI;
    }
}

int bsearch(vector<string> vec, string& element, const char* searchFor) { // the 'searchFor' is for specifying which to find, id or name
    string temp = element; // store element here to preserve alphabet case state
    // element to lowercase
    for (int i = 0; element[i]; i++) {
        if(isupper(element[i]))
            element[i] = tolower(element[i]);
    }
    // vector to lowercase
    for (int i = 0; i < vec.size(); i++) {
        for (auto& tmp : vec[i]) // converts each chars of each element to lowercase
            if (isupper(tmp)) // convert only if the letter is uppercase
                tmp = tolower(tmp);
    }

    int l, u, m;
    bool isFound = false;
    l = 0;
    u = vec.size() - 1;
    while (l <= u) {
        m = (l + u) / 2;
        if (vec[m] == element) {
            cout << searchFor << temp << "\n";
            isFound = true;
            return m; // returns index so that I can find the pair info ;)
            break;
        }
        else if (vec[m] < element)
            l = m + 1;
        else
            u = m - 1;
    }
    if (isFound == false)
        cerr << "\nERROR: Student not found!\n";
    return -1;
}
