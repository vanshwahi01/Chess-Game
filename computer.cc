#include "computer.h"
#include <cstdlib>

using namespace std;

Computer::Computer(){}

int Computer::getLevel(){
        return level;
}

void incTotalPieces(){
    totalPieces++;
}

void setLevel(int lev){
    level = lev;
}

Piece Computer::randomPiece(){//will this give me an error saying totalPieces is not declared in this scope? It technically comes with it because it's a player... but idk
        srand((unsigned int)time(NULL));
        int randomIndex = rand() % totalPieces;//gives us a random index from 0 to whatever the total number of pieces is;
        return randomIndex;
}
