/*
 * File: Boggle.cpp
 * -----------------------
 * Name: [TODO: enter name here]
 * This file is the starter code for the Boggle Game problem
 * from Assignment #4.
 * [TODO: extend the documentation]
 */

#include <cctype>
#include <fstream>
#include <iostream>
#include "gboggle.h"
#include "grid.h"
#include "gwindow.h"
#include "lexicon.h"
#include "random.h"
#include "simpio.h"
//#include <QMediaPlayer>
#include "console.h"
#include "Initialboggle.h"
#include "Searchboggle.h"
#include "Userboggle.h"
#include "Computerboggle.h"
#include <string>

using namespace std;

const int BOGGLE_WINDOW_WIDTH = 650;
const int BOGGLE_WINDOW_HEIGHT = 350;
const string STANDARD_CUBES_FIlE = "cubes16.txt";
const string BIG_BOGGLE_CUBES_FILE = "cubes25.txt";

/* Function prototypes */

void welcome();
void giveInstructions();
void playBoggle();

/* Main program */

// You need to design specific data structures and functions
// to complete this assignment.

int main() {

    welcome();
    if (getYesOrNo("Do you need instructions? ")) {
       giveInstructions();
    }

   playBoggle();
   return 0;
}

/*
 * Function: welcome
 * Usage: welcome();
 * -----------------
 * Print out a cheery welcome message.
 */

void welcome() {
   cout << "Welcome!  You're about to play an intense game ";
   cout << "of mind-numbing Boggle.  The good news is that ";
   cout << "you might improve your vocabulary a bit.  The ";
   cout << "bad news is that you're probably going to lose ";
   cout << "miserably to this little dictionary-toting hunk ";
   cout << "of silicon.  If only YOU had a gig of RAM..." << endl << endl;
}

/*
 * Function: giveInstructions
 * Usage: giveInstructions();
 * --------------------------
 * Print out the instructions for the user.
 */

void giveInstructions() {
   cout << endl;
   cout << "The boggle board is a grid onto which I ";
   cout << "I will randomly distribute cubes. These ";
   cout << "6-sided cubes have letters rather than ";
   cout << "numbers on the faces, creating a grid of ";
   cout << "letters on which you try to form words. ";
   cout << "You go first, entering all the words you can ";
   cout << "find that are formed by tracing adjoining ";
   cout << "letters. Two letters adjoin if they are next ";
   cout << "to each other horizontally, vertically, or ";
   cout << "diagonally. A letter can only be used once ";
   cout << "in each word. Words must be at least four ";
   cout << "letters long and can be counted only once. ";
   cout << "You score points based on word length: a ";
   cout << "4-letter word is worth 1 point, 5-letters ";
   cout << "earn 2 points, and so on. After your puny ";
   cout << "brain is exhausted, I, the supercomputer, ";
   cout << "will find all the remaining words and double ";
   cout << "or triple your paltry score." << endl << endl;
   cout << "Hit return when you're ready...";
   getLine();
}

void playBoggle() {

    //  [TODO: Fill and extend code here]
    GWindow gw(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);
    gw.setLocation(50,50);
    initGBoggle(gw);

    Initialboggle initialboggle(STANDARD_CUBES_FIlE);

    while (true) {
        string str;
        if(initialboggle.isforceTheBoard()){
            str = initialboggle.generateTheBoardByUser();
        }
        else{
            str = initialboggle.generateTheBoardAuto();
        }
        drawBoard(4,4);
        for(int i=0; i<16; ++i){
            labelCube(i/4, i%4, str[i]);
        }

        Searchboggle searchboggle(str, "res/EnglishWords.txt");
        Userboggle userboggle;
        Computerboggle computerboggle;
        userboggle.UserTurn(searchboggle);
        computerboggle.ComputerTurn(searchboggle);

        if (!getYesOrNo("Would you like to play again? ")) break;
    }

    exitGraphics();
}
