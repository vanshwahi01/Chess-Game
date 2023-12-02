#ifndef PLAYER_H
#define PLAYER_H
#include pieces.h
#include <vector>
using namespace std;

enum Colour {White = 0, Black = 1};

class Player {
        vector<Pieces*> (16);

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
