#ifndef ___QUEEN___
#define ___QUEEN___
#include <vector>
#include "Piece.h"


using namespace std;


class Queen: public Piece {
public:
    Queen(Coordinate c, Colour colour, string type);
    ~Queen();
    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif
