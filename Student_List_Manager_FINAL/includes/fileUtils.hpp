#pragma once
#include <vector>

using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

// Database names
// for directory names to be accessible anywhere
extern const string nameDB;
extern const string idDB;

// Checks if file exits or accessible
bool fileExists (const string& name);

// Function to create the 'database' text file
void createDB(const string &dir);

// Function to print file contents formatted
void printFile();

// Transfer contents of file to a vector
void FiletoVector(vector<string>& vec, const string& filename);

// Transfer contents of vector to a file
void VectortoFile(vector<string>& vec, const string& filename);

// Contains the utilities for case 3 in the menu, which is searching, updating, & deleting info
void searchAction(vector<string>& names, vector<string>& ids, int& index, const char* mode);