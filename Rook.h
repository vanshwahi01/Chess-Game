#ifndef ___ROOK___
#define ___ROOK___
#include <vector>
#include "piece.h"


using namespace std;


class Rook: public Piece {
public:
    Rook(Coordinate c, Colour colour, Board b, string type);

    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif