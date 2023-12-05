#ifndef ___ROOK___
#define ___ROOK___
#include <vector>
#include "Piece.h"


using namespace std;


class Rook: public Piece {
public:
    Rook(Coordinate c, Colour colour, Board b);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves
};

#endif
