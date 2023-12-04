#include "Board.h"
#include "Piece.h"

using namespace std;


Board::Board() : {} 

Board::Board(vector<Piece*> p, Piece **board, bool playerTurn, Textdisplay *td, Xwindow *xw) : p(p), board(board), playerTurn(playerTurn), td(td), xw(xw) {
    board = new Piece*[32];
    for (int i = 0; i < 32; i++) {
        board[i] = new Piece[32];
    }
}

Board::~Board() {
    for (int i = 0; i < 32; i++) {
        delete [] board[i];
    }
    delete [] board;
}

bool Board::isOccupied(const Board& b, const Coordinate& c) {
    return b.board[c.x][c.y] != nullptr;
}

void addPiece(const string type, const Coordinate c, const Colour colour, Board &b){
        string name;
        if(type == "K") { //if we're adding a King
                King temp {c, colour, b, "King"};
        }
        else if(type == "Q"){ // if we're adding a Queen
                Queen temp {c, colour,b, "Queen"};
        }
        else if(type == "B") { // if we're adding a Bishop
                Bishop temp {c, colour, b, "Bishop"};
        }
        else if(type == "R"){ // if we're adding a Rook
                Rook temp {c, colour,b, "Rook"};
        }
        else if(type == "N") { // if we're adding a Knight
                Knight temp {c, colour, b, "Knight"};
        }
        else if(type == "P"){ // if we're adding a Pawn
                Pawn temp {c, colour,b, "Pawn"};
        }
        else {
                return; // don't do anything if valid type wasn't given
        }
        //checking if another piece already exists on this coordinate
        for(auto p : b->pieces) {
                //if this new piece is being added on a coordinate that already has a piece, new piece replaces old piece
                if(p->getCoords() == c) {
                        p = temp;
                        //SAHIB GET THE ASSIGNMENT OPERATOR
                        //leave function
                        return;
                }
        }
        //adds piece to the vector of pieces
        b->getPieces().push_back(temp); //need to change to setPiece cause pieces vector is private
}

vector<Coordinate> Board::getPieces(Coordinate c) {
    return p;
}

void Board::removePiece(Coordinate c) {
    delete board[c.x][c.y];
    board[c.x][c.y] = nullptr;
}

void Board::move(Coordinate c1, Coordinate c2) {
    if(Piece::isLegal(c2) && Piece::isLegal(c1)) {
        throw "Illegal move";
    }
    board[c2.x][c2.y] = board[c1.x][c1.y];
    board[c1.x][c1.y] = nullptr;
}

Piece *Board::getPiece(Coordinate c) {
    return board[c.x][c.y];
}

void setUpNormalBoard() {
    ~Board();
    board = new Piece*[32];
    // Black pieces
    board[0] = new Rook(0, Colour::Black, p); 
	board[1] = new Knight(1, Colour::Black, p);
	board[2] = new Bishop(2, colour::Black, p);
	board[3] = new Queen(3, Colour::Black, p);
    board[4] = new King(4, Colour::Black, p);
	board[5] = new Bishop(5, Colour::Black, p);
	board[6] = new Knight(6, Colour::Black, p);
	board[7] = new Rook(7, Colour::Black, p);
    for (int i = 8; i < 16; ++i) {
        board[i] = new Pawn(i, Colour::Black, p); // row of pawns
    }
    for(int i = 16; i < 24; ++i) {
        board[i] = new Pawn(i, Colour::White, p); // row of pawns
    }
    // White pieces
    board[24] = new Rook(24, Colour::White, p);
    board[25] = new Knight(25, Colour::White, p);
    board[26] = new Bishop(26, Colour::White, p);
    board[27] = new Queen(27, Colour::White, p);
    board[28] = new King(28, Colour::White, p);
    board[29] = new Bishop(29, Colour::White, p);
    board[30] = new Knight(30, Colour::White, p);
    board[31] = new Rook(31, Colour::White, p);
}



