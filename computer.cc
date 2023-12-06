#include "computer.h"
#include <cstdlib>

using namespace std;

Computer::Computer(Colour colour) : Player{colour} {}

int Computer::getLevel(){
        return level;
}

void Computer::setLevel(int lev){
    level = lev;
}

Piece* Computer::randomPiece(Board b, Colour curPlayer){//will this give me an error saying totalPieces is not declared in this scope? It technically comes with it because it's a player... but idk
        // srand((unsigned int)time(NULL));
        // int randomIndex = rand() % totalPieces;//gives us a random index from 0 to whatever the total number of pieces is;
        // return randomIndex;

        vector<Piece*> temp = b.getPieces();
        int totalPieces = temp.size(); //total pieces
        srand((unsigned int)time(NULL));
        int randomIndex = rand() % totalPieces;//gives us a random index from 0 to whatever the total number of pieces is;
        
        while(true){
                if(temp[randomIndex]->getColour() == curPlayer) break; // Keeps getting a random index
                randomIndex = rand() % totalPieces;
        }
            
        //get random index from possible moves
        vector<Coordinate> pMoves = temp[randomIndex]->possibleMoves(b, temp[randomIndex], temp[randomIndex]->getCoords());
        int numPossMoves = temp[randomIndex]->pMoves.size();
        int possMovesIndex = rand() % numPossMoves;
        
        b->move(temp[randomIndex]->getCoords() , pMoves[possMovesIndex]);
}
