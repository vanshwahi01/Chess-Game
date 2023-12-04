#include <vector>
#include "Piece.h"


using namespace std;


class King: public Piece {
public:
    King(Coordinate c, Colour colour, Board b);

    vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c) override; // Returns a vector of availble moves

    bool isChecked(const Board& b);

    bool willBeChecked(const Board& b, const Coordinate& c);
};