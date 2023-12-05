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
    board = new Piece*[64];
    // Black pieces
    board[0] = new Rook({0,0}, Colour::Black, p); 
	board[1] = new Knight({1,0}, Colour::Black, p);
	board[2] = new Bishop({2,0}, Colour::Black, p);
    board[3] = new King({3,0}, Colour::Black, p);
    board[4] = new Queen({4,0}, Colour::Black, p);
	board[5] = new Bishop({5,0}, Colour::Black, p);
	board[6] = new Knight({6,0}, Colour::Black, p);
	board[7] = new Rook({7,0}, Colour::Black, p);
    int j = 8;
    for (int i = 0; i < 8; ++i) {
        board[j] = new Pawn({i,0}, Colour::Black, p); // row of pawns
        j++;
    }

    for(int i = 16; i < 48; ++i) {
        board[i] = nullptr; // empty spaces
    }
    
    j = 48;
    for(int i = 0; i < 8; ++i) {
        board[j] = new Pawn({i,7}, Colour::White, p); // row of pawns
        j++;
    }

    // White pieces
    board[56] = new Rook({0,7}, Colour::White, p);
    board[57] = new Knight({1,7}, Colour::White, p);
    board[58] = new Bishop({2,7}, Colour::White, p);
    board[59] = new Queen({3,7}, Colour::White, p);
    board[60] = new King({4,7}, Colour::White, p);
    board[61] = new Bishop({5,7}, Colour::White, p);
    board[62] = new Knight({6,7}, Colour::White, p);
    board[63] = new Rook({7,7}, Colour::White, p);
}


