#pragma once

using std::string;

class Student {
private:
    string name;
    string id;

public:
    string getName(){
        return name;
    }
    string getID(){
        return id;
    }

    // Function to get the infos (name, id)
    void inputInfo(int infoType);
};