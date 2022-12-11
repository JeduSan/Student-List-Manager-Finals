#include <iostream>
#include <cstdio> // std::remove
#include <string>
#include <fstream>
#include "security.hpp"

using namespace std;

const string keyContainer = "key.txt";

bool login()
{
    ifstream fin;
    string tmp, key;

    decrypt(keyContainer);

    cout << "\nVault Key : ";
    cin >> key;
    fin.open(keyContainer);
    fin >> tmp;

    if (key == tmp)
    {
        encrypt(keyContainer);
        return true;
    }
    else
    {
        encrypt(keyContainer);
        return false;
    }
}

void home()
{
    system("cls");
    cout << "~ STUDENT LIST MANAGER ~\n\n";
    cout << "[Manage your list efficiently :D]\n\n";
    cout << "[NOTE: Please close another instance of this program (if there's any) before proceeding.]\n";
    system("pause");
}

void changeKey()
{
    string key;
    ofstream fout;

    cout << "~ STUDENT LIST MANAGER ~\n\n";
    // for login
    if (login() == true)
        cout << "\nAccess granted :P\n\n";

    else // exit program when key is wrong
    {
        cerr << "\nIncorrect Password!\n";
        system("pause");
        return;
    }
    system("pause");

    fout.open(keyContainer);

    if (fout.is_open())
    {
        system("cls");
        cout << "~ Password Vault ~\n\n";
        cout << "Input new vault key :\n> ";
        cin >> key;

        fout << key;
        cout << "\nChange Success!\n";
        ;
    }
    else
        cerr << "Can't open file!\n";

    system("pause");
    fout.close();
    encrypt(keyContainer);
}

void decrypt(const string &fileName)
{
    ifstream fin;
    ofstream fout;
    char chars;

    fin.open(fileName);
    fout.open("tmp.txt");

    // file decryption
    if (fin.is_open() && fout.is_open())
    {
        while (fin >> noskipws >> chars) // place content on a temp file
        {
            chars -= 696969; // minus 696969 to every character including spaces
            fout << chars;
        }
        fin.close();
        fout.close();
    }

    fin.open("tmp.txt");
    fout.open(fileName);

    if (fin.is_open() && fout.is_open()) // put back the decrypted content of the temp file on the source file
    {
        while (fin >> noskipws >> chars)
        {
            chars -= 696969;
            fout << chars;
        }
    }
    fin.close();
    fout.close();

    remove("tmp.txt"); // deletes the tmp file
}

void encrypt(const string &fileName)
{
    ifstream fin;
    ofstream fout;
    char chars;

    fin.open(fileName);
    fout.open("tmp.txt");

    // file encryption
    if (fin.is_open() && fout.is_open())
    {
        while (fin >> noskipws >> chars) // place content on a temp file
        {
            chars += 696969; // adds 696969 to every character including spaces
            fout << chars;
        }
        fin.close();
        fout.close();
    }

    fin.open("tmp.txt");
    fout.open(fileName);

    if (fin.is_open() && fout.is_open()) // put back the encrypted content of the temp file on the source file
    {
        while (fin >> noskipws >> chars)
        {
            chars += 696969;
            fout << chars;
        }
    }
    fin.close();
    fout.close();

    remove("tmp.txt"); // deletes the tmp file
}
