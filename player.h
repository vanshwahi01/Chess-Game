#ifndef PLAYER_H
#define PLAYER_H
#include pieces.h
#include <vector>
using namespace std;

class Player {

        King king;
        Queen queen;
        Rook r1, r2;
        Bishop b1, b2;
        Knight k1, k2;
        Pawn p1, p2, p3, p4, p5, p6, p7, p8;
        //alternatively
        //vector<Pawn> p(8);

        int colour = 0; // 0 is black, 1 is white
        int score = 0;
        int totalPieces = 0;
        public:

                Player();
                int getScore();
                int getColour();
                void incScore();
                int getTotalPieces();




};

class Computer : public Player {
        int level = 1;
        vector<Pieces> p(16);

        public:
                Computer(int level);
                int getLevel();
                Pieces randomPiece(); //returns a random piece
                //get a random index
                //the piece at that random index will be the piece that is chosen to be played

}

#endif
