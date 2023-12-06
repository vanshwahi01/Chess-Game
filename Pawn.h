#ifndef ___PAWN___
#define ___PAWN___
#include <vector>
#include "Piece.h"


using namespace std;


class Pawn: public Piece {
public:
    Pawn(Coordinate c, Colour colour, string type);

    //void promote(Board& b, Piece& p);
    ~Pawn();
    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif