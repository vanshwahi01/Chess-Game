#ifndef _COMPUTER_H
#define _COMPUTER_H
#include "player.h"
using namespace std;

class Computer : public Player {
        int level = 1;
        int totalPieces = 0;
        
        public:
                Computer();
                int getLevel();
                void setLevel(int lev);
                Piece randomPiece(const Board &b); //returns a random piece
                void incTotalPieces();
                //get a random index
                //the piece at that random index will be the piece that is chosen to be played

}

#endif