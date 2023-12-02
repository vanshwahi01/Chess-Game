#include <vector>


using namespace std;

class Board {
    int x;
Public:
    Board();
};

class Coordinates {
public:
    int x;
    int y;
    
    Coordinates();
    Coordinates(int x, int y);
};

enum Colour {Black, White};

class Piece {
    Coordinates coords;
    Colour colour;
    int numMoves;
    Board curBoard;

public:
    Piece(Coordinates c, Colour colour, Board b);

    virtual vector<Coordinates> possibleMoves(const Board& b, const Piece& p, const Coordinates& c); // Returns a vector of availble moves

    virtual void move(const Coordinates& c, const Board& b); // Moves the current piece and throws an exception if the move is illegal

    void getNumMoves(); // Returns numMoves

    void getColour(); // Returns colour

    void getCoords(); // Returns coords

    bool isLegal(const Coordinates& c); // Checks if a move is legal
    
    virtual ~Piece() = 0;
};