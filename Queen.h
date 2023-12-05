#ifndef ___QUEEN___
#define ___QUEEN___
#include <vector>
#include "piece.h"


using namespace std;


class Queen: public Piece {
public:
    Queen(Coordinate c, Colour colour, Board b, string type);

    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif