#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

int GetPoint(string word){
    if(word.length()<=3) return 0;
    else{
        return word.length()-3;
    }
}

#endif // UTILS_H
