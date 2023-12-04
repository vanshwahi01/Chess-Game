#include <vector>
#include "Piece.h"


using namespace std;


class Bishop: public Piece {
public:
    Bishop(Coordinate c, Colour colour, Board b);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves
};