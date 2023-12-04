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

vector<Coordinate> Board::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {
    return p.possibleMoves(b, c);
}

bool Board::isOccupied(const Board& b, const Coordinate& c) {
    return b.board[c.x][c.y] != nullptr;
}

void Board::setPiece(string &type, Colour &colour,  const Coordinate c) {
    if (type == "p") {
        board[c.x][c.y] = new Pawn(colour, c);
    } else if (type == "r") {
        board[c.x][c.y] = new Rook(colour, c);
    } else if (type == "n") {
        board[c.x][c.y] = new Knight(colour, c);
    } else if (type == "b") {
        board[c.x][c.y] = new Bishop(colour, c);
    } else if (type == "q") {
        board[c.x][c.y] = new Queen(colour, c);
    } else if (type == "k") {
        board[c.x][c.y] = new King(colour, c);
    }
}

vector<Coordinate> Board::getPiece(Coordinate c) {
    return board[c.x][c.y]->possibleMoves(*this, c);
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



