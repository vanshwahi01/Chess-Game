#ifndef ___PAWN___
#define ___PAWN___
#include <vector>
#include "piece.h"


using namespace std;


class Pawn: public Piece {
public:
    Pawn(Coordinate c, Colour colour, Board b);

    void promote(const Board& b, Piece& p);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves
};

#endif
