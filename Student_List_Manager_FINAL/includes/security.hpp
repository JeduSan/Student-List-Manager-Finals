#pragma once

using namespace std;

extern const string keyContainer;

bool login();
void home();
void changeKey();
void decrypt(const string &fileName);
void encrypt(const string &fileName);
