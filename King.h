#ifndef ___KING___
#define ___KING___
#include <vector>
#include "Piece.h"


using namespace std;


class King: public Piece {
public:
    King(Coordinate c, Colour colour, string type);

    vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c) override; // Returns a vector of availble moves

    bool isChecked(Board& b);
    ~King();
    bool willBeChecked(Board& b, const Coordinate& c);
};

#endif