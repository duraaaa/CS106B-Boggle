#ifndef INITIALBOGGLE_H
#define INITIALBOGGLE_H

#include <string>
#include <iostream>
#include "Ioboggle.h"

using namespace std;

class Initialboggle{
private:
    Ioboggle *ioboggle;
public:
    Initialboggle(const string filePath){
        ioboggle = new Ioboggle(filePath);
    }
    ~Initialboggle(){
        delete ioboggle;
    }
    bool isforceTheBoard(){
        char isForce;
        cout << "I'll give you a chance to set up the board to your specification," << endl;
        cout << "which makes it easier to confirm your boggle program is working." << endl;
        cout << "Do you want to force the board configuration?";
        while(true){
            cin >>  isForce;
            if(isForce=='n'||isForce=='N') return false;
            else if(isForce=='y'||isForce=='Y') return true;
            else {
                cout << "Please type a word that starts with 'Y' or 'N'." << endl;
                cout << "Do you want to force the board configuration?" << endl;
            }
        }
        return false;
    }
    string generateTheBoardByUser(){
        cout << "Enter a 16-character string to identify which letters you want on the cubes." << endl;
        cout << "The first 4 letters are the cubes on the top row from left to right," << endl;
        cout << "the next 4 letters are the second row, and so on." << endl;
        cout << "Enter the string: ";

        while(true){
            string strFromUser;
            cin >> strFromUser;
            if(strFromUser.length()!=16) {
                cout << "String must include 16 characters! Try again: ";
            }
            else return strFromUser;
        }

        return "";
    }
    string generateTheBoardAuto(){
        return ioboggle->getString();
    }
};

#endif // INITIALBOGGLE_H
