#include "Board.h"
#include "Piece.h"

using namespace std;


Board::Board() : {} 

Board::Board(vector<Piece*> p, Piece **board, bool playerTurn, Textdisplay *td, Xwindow *xw) : p(p), board(board), playerTurn(playerTurn), td(td), xw(xw) {
    vector<vector<Piece*>> board(8, vector<Piece*>(8, nullptr));
}

Board::~Board() {
    board.clear();
}

bool Board::isOccupied(const Board& b, const Coordinate& c) {
    return b.board[c.x][c.y] != nullptr;
}

void addPiece(const string type, const Coordinate c, const Colour colour, Board &b){
        if(c->x < 0 || c->x > 7 || c->y < 0 || c->y > 7) return; // Validate coordinate
        string name;
        if(type == "K") { //if we're adding a King
            if(b->isOccupied(c)) removePiece(c);
            King temp = new King{c, colour, b, "King"};
        }
        else if(type == "Q"){ // if we're adding a Queen
            if(b->isOccupied(c)) removePiece(c);
            Queen temp = new Queen{c, colour,b, "Queen"};
        }
        else if(type == "B") { // if we're adding a Bishop
            if(b->isOccupied(c)) removePiece(c);
            Bishop temp = new Bishop{c, colour, b, "Bishop"};
        }
        else if(type == "R"){ // if we're adding a Rook
            if(b->isOccupied(c)) removePiece(c);
            Rook temp = new Rook{c, colour,b, "Rook"};
        }
        else if(type == "N") { // if we're adding a Knight
            if(b->isOccupied(c)) removePiece(c);
            Knight temp = new Knight{c, colour, b, "Knight"};
        }
        else if(type == "P"){ // if we're adding a Pawn
            if(b->isOccupied(c)) removePiece(c);
            Pawn temp = new Pawn{c, colour,b, "Pawn"};
        }
        else {
            return; // don't do anything if valid type wasn't given
        }
        //adds piece to the vector of pieces
        p.push_back(&temp); //need to change to setPiece cause pieces vector is private
}

vector<Coordinate> Board::getPieces(Coordinate c) {
    return p;
}

void Board::removePiece(Coordinate c) {
    delete board[c.x][c.y];
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


