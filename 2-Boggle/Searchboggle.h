#ifndef SEARCHBOGGLE_H
#define SEARCHBOGGLE_H

#include "lexicon.h"
#include "map.h"
#include "vector.h"
#include "gboggle.h"
#include <string>

using namespace std;

class Searchboggle{
private:
    string cubes;
    Lexicon lexicon;
    Map<string, Vector<int>> userList;
    Map<string, Vector<int>> computerList;

    bool searchForWord(string word, int index, int len, Vector<int> &vec){
        if(word.length()==len) return true;
        if(cubes[index]-word[len]!=0&&cubes[index]-word[len]!='A'-'a'&&cubes[index]-word[len]!='a'-'A') return false;
        else{
            vec.add(index);
            if(index%4!=0&&index/4>0) {
                if(searchForWord(word, index-5, len+1, vec)==true) return true;
            }
            if(index/4>0) {
                if(searchForWord(word, index-4, len+1, vec)==true) return true;
            }
            if(index%4!=3&&index/4>0) {
                if(searchForWord(word, index-3, len+1, vec)==true) return true;
            }
            if(index%4!=0) {
                if(searchForWord(word, index-1, len+1, vec)==true) return true;
            }
            if(index%4!=3) {
                if(searchForWord(word, index+1, len+1, vec)==true) return true;
            }
            if(index%4!=0&&index/4<3) {
                if(searchForWord(word, index+3, len+1, vec)==true) return true;
            }
            if(index/4<3) {
                if(searchForWord(word, index+4, len+1, vec)==true) return true;
            }
            if(index%4!=3&&index/4<3) {
                if(searchForWord(word, index+5, len+1, vec)==true) return true;
            }
            vec.remove(vec.size()-1);
            return false;
        }
    }

    void searchForAll(string &word, Vector<int> &vec, int index){
        if(word.length()==vec.size()) return;
        if(word.length()>=4 && lexicon.contains(word)){
            if(!userList.containsKey(word)&&!computerList.containsKey(word)){
                computerList.put(word, vec);
                recordWordForPlayer(word, COMPUTER);
            }
        }
        if(!lexicon.containsPrefix(word)) return;
        else{
            if(index%4!=0&&index/4>0&&vec[index-5]==0) {
                word.push_back(cubes[index-5]);
                vec[index-5]=1;
                searchForAll(word, vec, index-5);
                vec[index-5]=0;
                word.pop_back();
            }
            if(index/4>0&&vec[index-4]==0) {
                word.push_back(cubes[index-4]);
                vec[index-4]=1;
                searchForAll(word, vec, index-4);
                vec[index-4]=0;
                word.pop_back();
            }
            if(index%4!=3&&index/4>0&&vec[index-3]==0) {
                word.push_back(cubes[index-3]);
                vec[index-3]=1;
                searchForAll(word, vec, index-3);
                vec[index-3]=0;
                word.pop_back();
            }
            if(index%4!=0&&vec[index-1]==0) {
                word.push_back(cubes[index-1]);
                vec[index-1]=1;
                searchForAll(word, vec, index-1);
                vec[index-1]=0;
                word.pop_back();
            }
            if(index%4!=3&&vec[index+1]==0) {
                word.push_back(cubes[index+1]);
                vec[index+1]=1;
                searchForAll(word, vec, index+1);
                vec[index+1]=0;
                word.pop_back();
            }
            if(index%4!=0&&index/4<3&&vec[index+3]==0) {
                word.push_back(cubes[index+3]);
                vec[index+3]=1;
                searchForAll(word, vec, index+3);
                vec[index+3]=0;
                word.pop_back();
            }
            if(index/4<3&&vec[index+4]==0) {
                word.push_back(cubes[index+4]);
                vec[index+4]=1;
                searchForAll(word, vec, index+4);
                vec[index+4]=0;
                word.pop_back();
            }
            if(index%4!=3&&index/4<3&&vec[index+5]==0) {
                word.push_back(cubes[index+5]);
                vec[index+5]=1;
                searchForAll(word, vec, index+5);
                vec[index+5]=0;
                word.pop_back();
            }
        }
    }

public:
    Searchboggle(const string _cubes, const string _filepath):cubes(_cubes), lexicon(_filepath){}
    ~Searchboggle(){}
    bool searchForWord(string word, Vector<int> &vec){
        if(word.length()<4 || userList.containsKey(word)==true) return false;
        if(lexicon.contains(word)==false) return false;
        for(int i=0; i<16; ++i){
            if(searchForWord(word, i, 0, vec)==true){
                userList.put(word, vec);
                return true;
            }
        }
        return false;
    }

    void searchForAll(){
        Vector<int> vec(16, 0);
        string str;
        for(int i=0; i<16; ++i){
            str.push_back(cubes[i]);
            vec[i] = 1;
            searchForAll(str, vec, i);
            vec[i] = 0;
            str.pop_back();
        }
    }
};

#endif // SEARCHBOGGLE_H
