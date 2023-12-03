#ifndef PLAYER_H
#define PLAYER_H
#include "pieces.h"

using namespace std;

//in Sahib's piece.h
//enum Colour {White = 0, Black = 1};

class Player {
        Colour c = Colour::White;
        int score = 0;
        int totalPieces = 0;
        public:
                Player();
                int getScore();
                int getColour();
                void incScore();
                int getTotalPieces();

};

#endif
