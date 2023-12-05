#ifndef ___BOARD___
#define ___BOARD___

#include <string>
#include <vector>
#include "piece.h"

using namespace std;

class Piece;
class Player;
class Coordinate;
class Textdisplay;
class Xwindow; // if we have time

class Board {
    vector<Piece*> p; 
    vector<vector<Piece*>> board;
    Textdisplay *td;
    //Xwindow *xw;
    
    public:
        // default blank board constructor
        Board(Textdisplay *td);
        ~Board();
        bool isOccupied(const Coordinate& c);
        bool addPiece(string &type, Colour &colour,  const Coordinate c);
        vector<Piece*> getPieces();
        void removePiece(const Coordinate& c);
        bool move(const Coordinate& c1, const Coordinate& c2);
        Piece *getPiece(const Coordinate& c); // returning pointer to piece check it
        void setUpNormalBoard(); // setting up a basic chess board
        friend std::ostream &operator<<(std::ostream &out, const Board& b);
};

#endif
