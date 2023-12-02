#include <vector>
#include "Piece.h"


using namespace std;


class Pawn: public Piece {
    Coordinates coords;
    Colour colour;
    int numMoves;

public:
    Pawn(Coordinates c, Colour colour);

    void promote(const Board& b, Piece* )
};