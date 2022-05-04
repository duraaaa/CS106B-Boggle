#ifndef USERBOGGLE_H
#define USERBOGGLE_H

#include "Searchboggle.h"
#include "Utils.h"
#include "gboggle.h"

class Userboggle{
private:
    int score;
public:
    Userboggle(){score=0;}
    ~Userboggle(){}
    void UserTurn(Searchboggle &searchboggle){
        cout << "Ok, take all the time you want and find all the words you can!" << endl;
        cout << "Signal that you're finished by entering an empty line." << endl;
        cin.get();
        while(true){
            string word;
            Vector<int> vec;
            cout << "Enter a word: ";
            getline(cin, word);
            if(word=="") return;
            if(searchboggle.searchForWord(word, vec)==true){
                score += GetPoint(word);
                recordWordForPlayer(word, HUMAN);
                for(int i=0; i<vec.size(); ++i){
                    highlightCube(vec[i]/4, vec[i]%4, true);
                }
                for(int i=0; i<vec.size(); ++i){
                    highlightCube(vec[i]/4, vec[i]%4, false);
                }
            }
            else{
                cout << "You can't make that word!" << endl;
            }
        }
    }
};

#endif // USERBOGGLE_H
