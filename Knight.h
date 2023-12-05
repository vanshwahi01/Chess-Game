#ifndef ___KNIGHT___
#define ___KNIGHT___
#include <vector>
#include "Piece.h"


using namespace std;


class Knight: public Piece {
public:
    Knight(Coordinate c, Colour colour, Board b, string type);

    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif