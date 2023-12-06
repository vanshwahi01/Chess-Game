#ifndef ___PIECE___
#define ___PIECE___

#include <vector>
#include <string>
#include "coordinate.h"
#include "board.h"

using namespace std;

/*
class Board {
    int x = 0;
    public:
        Board();
};
*/
class Coordinate;
class Board;
enum class Colour;

class Piece {
    Coordinate coords;
    Colour colour;
    int numMoves;
    string type;

public:
    Piece(Coordinate c, Colour colour2, string type);

    virtual vector<Coordinate> possibleMoves(Board& b, Piece& p, Coordinate& c); // Returns a vector of availble moves

    void setCoords(const Coordinate& c);

    int getNumMoves(); // Returns numMoves

    Colour getColour(); // Returns colour

    Coordinate getCoords(); // Returns coords

    string getType();

    bool isLegal(const Coordinate& c, Board& b); // Checks if a move is legal

    virtual ~Piece() = 0;
};

#endif
