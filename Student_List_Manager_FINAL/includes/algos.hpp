#pragma once

using std::string;
using std::vector;

// Descending insertion sort
void desc_insertion_sort(vector<string>& ids, vector<string>& names, const int& mode);

// Ascending insertion sort
void asc_insertion_sort(vector<string>& ids, vector<string>& names, const int& mode);

// Binary search
int bsearch(vector<string> vec, string& element, const char* searchFor);
