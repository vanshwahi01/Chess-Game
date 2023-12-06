#ifndef ___BISHOP___
#define ___BISHOP___
#include <vector>
#include "Piece.h"


using namespace std;


class Bishop: public Piece {
public:
    Bishop(Coordinate c, Colour colour, string type);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves
};

#endif
