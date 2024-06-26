#ifndef ___BISHOP___
#define ___BISHOP___
#include <vector>
#include "Piece.h"


using namespace std;


class Bishop: public Piece {
public:
    Bishop(Coordinate c, Colour colour, string type);
    ~Bishop();
    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves
};

#endif
