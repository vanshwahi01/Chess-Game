#ifndef ___BOARD___
#define ___BOARD___

#include <string>
#include <vector>
#include "Piece.h"

using namespace std;

class Piece;
class Player;
class Coordinate;
class Textdisplay;
class Xwindow; // if we have time

class Board {
    vector<Piece*> p(32)
    Piece **board;
    bool playerTurn;
    Textdisplay *td;
    Xwindow *xw;
    
    public:
        // default blank board constructor
        virtual Board();
        virtual Board(vector<Piece*> p, Piece **board, bool playerTurn, Textdisplay *td, Xwindow *xw);
        virtual ~Board();
        virtual vector<Coordinate> possibleMoves(const Board& b, const Piece& p, const Coordinate& c);
        bool isOccupied(const Board& b, const Coordinate& c);
        void setPiece(string &type, Colour &colour,  const Coordinate c);
        vector<Coordinate> Board::getPiece(Coordinate c);
        void removePiece(Coordinate c);
        void movePiece(Piece &p, Coordinate c2);
};

#endif
