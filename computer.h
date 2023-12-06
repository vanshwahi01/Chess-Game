#ifndef _COMPUTER_H
#define _COMPUTER_H
#include "player.h"
using namespace std;

class Computer : public Player {
        int level = 1;
        
        public:
                Computer(Colour colour);
                int getLevel();
                void setLevel(int lev);
                void randomPiece(Board& b, Colour curPlayer); //returns a random piece
                //get a random index
                //the piece at that random index will be the piece that is chosen to be played

};

#endif
