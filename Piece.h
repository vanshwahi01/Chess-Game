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

public:
    Piece(Coordinates c, Colour colour);

    virtual vector<Coordinates> possibleMoves(const Board& b, const Piece& p, const Coordinates& c); // Returns a vector of availble moves

    virtual void move(const Coordinates& c); // Moves the current piece and throws an exception if the move is illegal

    virtual ~Piece() = 0;
};