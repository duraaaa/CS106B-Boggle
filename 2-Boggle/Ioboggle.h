#ifndef IOBOGGLE_H
#define IOBOGGLE_H

#include <string>
#include <fstream>
#include <iostream>
#include "random.h"
#include "filelib.h"
#include "strlib.h"

using namespace std;

class Ioboggle{
private:
    string filePath;
    char dies[16][6];
public:
    Ioboggle(const string _filePath){
        filePath ="res/"+_filePath;
        ifstream fin;
        openFile(fin, filePath);
        int line=0;
        while(!fin.eof() && line<16){
            fin >> dies[line];
            line++;
        }
    }
    ~Ioboggle(){}
    string getString(){
        string str;

        for(int i=0; i<16; ++i){
            int index = randomInteger(0,5);
            str.push_back(dies[i][index]);
        }

        for(int i=0; i<16; ++i){
            int index = randomInteger(i,15);
            char tmp = str[index];
            str[index] = str[i];
            str[i] = tmp;
        }

        return str;
    }
};

#endif // IOBOGGLE_H
