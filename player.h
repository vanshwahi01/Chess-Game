#ifndef _PLAYER_H
#define _PLAYER_H
#include "Piece.h"


using namespace std;

//in Sahib's piece.h
//enum Colour {White = 0, Black = 1};

class Player {
        protected:
                Colour colour = Colour::White;
                int score = 0;
        public:
                Player(Colour c);
                int getScore();
                Colour getColour();
                void incScore();
                void draw();
                

};

#endif