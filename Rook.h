#ifndef ___ROOK___
#define ___ROOK___
#include <vector>
#include "Piece.h"


using namespace std;


class Rook: public Piece {
public:
    Rook(Coordinate c, Colour colour, string type);

    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif