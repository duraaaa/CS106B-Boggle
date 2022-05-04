#ifndef COMPUTERBOGGLE_H
#define COMPUTERBOGGLE_H

#include "Searchboggle.h"

class Computerboggle{
private:
public:
    Computerboggle(){}
    ~Computerboggle(){}
    void ComputerTurn(Searchboggle &searchboggle){
        searchboggle.searchForAll();
    }
};

#endif // COMPUTERBOGGLE_H
