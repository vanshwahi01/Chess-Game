#ifndef ___KNIGHT___
#define ___KNIGHT___
#include <vector>
#include "piece.h"


using namespace std;


class Knight: public Piece {
public:
    Knight(Coordinate c, Colour colour, Board b);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves
};

#endif
