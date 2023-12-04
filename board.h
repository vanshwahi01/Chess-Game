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
    vector<Piece*> p; 
    Piece **board;
    bool playerTurn;
    Textdisplay *td;
    Xwindow *xw;
    
    public:
        // default blank board constructor
        Board();
        Board(vector<Piece*> p, Piece **board, bool playerTurn, Textdisplay *td, Xwindow *xw);
        ~Board();
        bool isOccupied(const Board& b, const Coordinate& c);
        void addPiece(string &type, Colour &colour,  const Coordinate c);
        vector<Coordinate> Board::getPieces(Coordinate c);
        void removePiece(Coordinate c);
        void move(Coordinate c1, Coordinate c2);
        Piece *getPiece(Coordinate c); // returning pointer to piece check it
        void setUpNormalBoard(); // setting up a basic chess board
};

#endif
