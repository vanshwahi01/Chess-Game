#ifndef ___KNIGHT___
#define ___KNIGHT___
#include <vector>
#include "Piece.h"


using namespace std;


class Knight: public Piece {
public:
    Knight(Coordinate c, Colour colour, string type);
    ~Knight();
    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif