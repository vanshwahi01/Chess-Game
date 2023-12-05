#ifndef ___PIECE___
#define ___PIECE___

#include <vector>
#include "Coordinate.h"
#include "Board.h"

using namespace std;

/*
class Board {
    int x;
public:
    Board();
};
*/

enum Colour {Black, White};

class Piece {
    Coordinate coords;
    Colour colour;
    int numMoves;
    Board curBoard;
    string type;

public:
    Piece(Coordinate c, Colour colour, const Board& b, string type);

    virtual vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c); // Returns a vector of availble moves

    void setCoords(const Coordinate& c);

    int getNumMoves(); // Returns numMoves

    Colour getColour(); // Returns colour

    Coordinate getCoords(); // Returns coords

    string getType(); 

    bool isLegal(const Coordinate& c); // Checks if a move is legal
    
    virtual ~Piece() = 0;
};

#endif
