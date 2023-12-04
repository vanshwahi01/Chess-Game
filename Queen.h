#include <vector>
#include "Piece.h"


using namespace std;


class Queen: public Piece {
public:
    Queen(Coordinate c, Colour colour, Board b);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves
};