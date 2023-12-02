#include <vector>
#include "Coordinate.h"

using namespace std;

class Board {
    int x;
Public:
    Board();
};

class Coordinate {
public:
    int x;
    int y;
    
    Coordinate();
    Coordinate(int x, int y);
};

enum Colour {Black, White};

class Piece {
    Coordinate coords;
    Colour colour;
    int numMoves;
    Board curBoard;

public:
    Piece(Coordinate c, Colour colour, Board b);

    virtual vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c); // Returns a vector of availble moves

    virtual void move(const Coordinate& c, const Board& b); // Moves the current piece and throws an exception if the move is illegal

    void getNumMoves(); // Returns numMoves

    void getColour(); // Returns colour

    void getCoords(); // Returns coords

    bool isLegal(const Coordinate& c); // Checks if a move is legal
    
    virtual ~Piece() = 0;
};