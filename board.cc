#include <string>
#include <vector>
#include "Piece.h"
#include "textdisplay.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

using namespace std;

Board::Board(TextDisplay *td) : p{vector<Piece*>(0)}, board{vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr))}, td(td) {}

Board::~Board() {
    p.clear();
    board.clear();
    delete td;
}

bool Board::isOccupied(Coordinate c) {
    return board[c.x][c.y] != nullptr;
}

bool Board::addPiece(const string type, const Coordinate c, const Colour colour, Board &b){
        if(c.x < 0 || c.x > 7 || c.y < 0 || c.y > 7) return false; // Validate coordinate
        Piece* temp = nullptr;
        if(type == "K") { //if we're adding a King
            if(b.isOccupied(c)) removePiece(c);
            temp = new King{c, colour, b, "King"};
            if(colour == Colour::Black) td->notify('k', c.x, c.y);
            else td->notify('K', c.x, c.y);
        }
        else if(type == "Q"){ // if we're adding a Queen
            if(b.isOccupied(c)) removePiece(c);
            temp = new Queen{c, colour,b, "Queen"};
            if(colour == Colour::Black) td->notify('q', c.x, c.y);
            else td->notify('Q', c.x, c.y);
        }
        else if(type == "B") { // if we're adding a Bishop
            if(b.isOccupied(c)) removePiece(c);
            temp = new Bishop{c, colour, b, "Bishop"};
            if(colour == Colour::Black) td->notify('b', c.x, c.y);
            else td->notify('B', c.x, c.y);
        }
        else if(type == "R"){ // if we're adding a Rook
            if(b.isOccupied(c)) removePiece(c);
            temp = new Rook{c, colour,b, "Rook"};
            if(colour == Colour::Black) td->notify('r', c.x, c.y);
            else td->notify('R', c.x, c.y);
        }
        else if(type == "N") { // if we're adding a Knight
            if(b.isOccupied(c)) removePiece(c);
            temp = new Knight{c, colour, b, "Knight"};
            if(colour == Colour::Black) td->notify('n', c.x, c.y);
            else td->notify('N', c.x, c.y);
        }
        else if(type == "P"){  // if we're adding a Pawn
            if(b.isOccupied(c)) removePiece(c);
            temp = new Pawn{c, colour,b, "Pawn"};
            if(colour == Colour::Black) td->notify('p', c.x, c.y);
            else td->notify('P', c.x, c.y);
        }
        else {
            cout << "Please enter valid input." << endl;
            return false; // don't do anything if valid type wasn't given
        }
        p.push_back(temp); // adds piece to the vector of pieces
        board[c.x][c.y] = temp;
        return true;
}

vector<Piece*> Board::getPieces() {
    return p;
}

void Board::removePiece(const Coordinate& c) {
    delete board[c.x][c.y];
    board[c.x][c.y] = nullptr;
    if(c.x % 2 == 0) { // Replace the removed piece with the correct tile
        if(c.y % 2 == 0) td->notify('_', c.x, c.y);
        else td->notify(' ', c.x, c.y);
    } else {
        if(c.y % 2 == 0) td->notify(' ', c.x, c.y);
        else td->notify('_', c.x, c.y);
    }
}

bool Board::move(const Coordinate& c1, const Coordinate& c2) { // c1 is start, c2 is end
    if(c1.x < 0 || c1.x > 7 || c1.y < 0 || c1.y > 7) { // Validate coordinate
        cout << "Coordinate 1 out of board. Please enter valid coordinate." << endl;
        return false;
    }

    if(c2.x < 0 || c2.x > 7 || c2.y < 0 || c2.y > 7) { // Validate coordinate
        cout << "Coordinate 2 out of board. Please enter valid coordinate." << endl;
        return false;
    }

    Piece* temp = getPiece(c1);

    if(temp->isLegal(c2)) {
        temp->setCoords(c2);
        board[c2.x][c2.y] = temp;
        board[c1.x][c1.y] = nullptr;
        if(c1.x % 2 == 0) { // Replace the removed piece with the correct tile
            if(c1.y % 2 == 0) td->notify('_', c1);
            else td->notify(' ', c1);
        } else {
            if(c1.y % 2 == 0) td->notify(' ', c1);
            else td->notify('_', c1);
        }

        if(temp->getType() == "Pawn") {
            if(temp->getColour() == Colour::Black) {
                td->notify('p', c2);
            } else td->notify('P', c2);
        }

        if(temp->getType() == "Rook") {
            if(temp->getColour() == Colour::Black) {
                td->notify('r', c2);
            } else td->notify('R', c2);
        }

        if(temp->getType() == "Knight") {
            if(temp->getColour() == Colour::Black) {
                td->notify('n', c2);
            } else td->notify('K', c2);
        }

        if(temp->getType() == "Bishop") {
            if(temp->getColour() == Colour::Black) {
                td->notify('b', c2);
            } else td->notify('B', c2);
        }

        if(temp->getType() == "King") {
            if(temp->getColour() == Colour::Black) {
                td->notify('k', c2);
            } else td->notify('K', c2);
        }

        if(temp->getType() == "Queen") {
            if(temp->getColour() == Colour::Black) {
                td->notify('q', c2);
            } else td->notify('Q', c2);
        }

        return true;
    }

    cout << "That is not a legal move, please enter a new move." << endl;
    return false;
}

Piece* Board::getPiece(const Coordinate& c) {
    return board[c.x][c.y];
}

void Board::setUpNormalBoard() {
    // Black pieces
    board[0][0] = new Rook({0,0}, Colour::Black, *this, "Rook");
    td->notify('r', {0, 0});
        board[1][0] = new Knight({1,0}, Colour::Black, *this, "Knight");
    td->notify('n', {1, 0});
        board[2][0] = new Bishop({2,0}, Colour::Black, *this, "Bishop");
    td->notify('b', {2, 0});
    board[3][0] = new King({3,0}, Colour::Black, *this, "King");
    td->notify('k', {3, 0});
    board[4][0] = new Queen({4,0}, Colour::Black, *this, "Queen");
    td->notify('q', {4, 0});
        board[5][0] = new Bishop({5,0}, Colour::Black, *this, "Bishop");
    td->notify('b', {5, 0});
        board[6][0] = new Knight({6,0}, Colour::Black, *this, "Knight");
    td->notify('n', {6, 0});
        board[7][0] = new Rook({7,0}, Colour::Black, *this, "Rook");
    td->notify('r', {7, 0});
    for (int i = 0; i < 8; ++i) {
        board[i][1] = new Pawn({i,1}, Colour::Black, *this, "Pawn"); // row of pawns
        td->notify('p', {i, 1});
    }
    for(int j = 0; j < 2; j++) { // Adds two rows of pieces to vector
        for(int i = 0; i < 8; i++) {
            p.push_back(getPiece({i, j}));
        }
    }

    for(int i = 0; i < 8; ++i) {
        board[i][6] = new Pawn({i,6}, Colour::White, *this, "Pawn"); // row of pawns
        td->notify('P', {i, 6});
    }

    // White pieces
    board[0][7] = new Rook({0,7}, Colour::White, *this, "Rook");
    td->notify('R', {0, 7});
    board[1][7] = new Knight({1,7}, Colour::White, *this, "Knight");
    td->notify('N', {1, 7});
    board[2][7] = new Bishop({2,7}, Colour::White, *this, "Bishop");
    td->notify('B', {2, 7});
    board[3][7] = new Queen({3,7}, Colour::White, *this, "Queen");
    td->notify('K', {3, 7});
    board[4][7] = new King({4,7}, Colour::White, *this, "King");
    td->notify('Q', {4, 7});
    board[5][7] = new Bishop({5,7}, Colour::White, *this, "Bishop");
    td->notify('B', {5, 7});
    board[6][7] = new Knight({6,7}, Colour::White, *this, "Knight");
    td->notify('N', {6, 7});
    board[7][7] = new Rook({7,7}, Colour::White, *this, "Rook");
    td->notify('R', {7, 7});

    for(int j = 6; j < 8; j++) { // Adds last two rows of pieces to vector
        for(int i = 0; i < 8; i++) {
            p.push_back(getPiece({i, j}));
        }
    }
}

ostream &operator<<(ostream &out, const Board& b) {
  out << b.td;
  return out;
}
