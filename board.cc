#include "Board.h"
#include "Piece.h"

using namespace std;

Board::Board(Textdisplay *td) : p{vector<Piece*>(0)}, board{vector<vector<Piece*>>(8, vector<Piece*>(8, nullptr))}, td(td) {}

Board::~Board() {
    p.clear();
    board.clear();
    delete td;
}

bool Board::isOccupied(const Coordinate& c) {
    return board[c.x][c.y] != nullptr;
}

bool addPiece(const string type, const Coordinate c, const Colour colour, Board &b){
        if(c->x < 0 || c->x > 7 || c->y < 0 || c->y > 7) return; // Validate coordinate
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
            cout << "Please enter valid input." << endl;
            return false; // don't do anything if valid type wasn't given
        }
        p.push_back(&temp); // adds piece to the vector of pieces
        board[c.x][c.y] = &temp;
        td->notify()
        return true;
}

vector<Piece*> Board::getPieces() {
    return p;
}

void Board::removePiece(const Coordinate& c) {
    delete board[c.x][c.y];
    board[c.x][c.y] = nullptr;
}

bool Board::move(const Coordinate& c1, const Coordinate& c2) { // c1 is start, c2 is end
    if(c1->x < 0 || c1->x > 7 || c1->y < 0 || c1->y > 7) { // Validate coordinate
        cout << "Coordinate 1 out of board. Please enter valid coordinate." << endl;
        return false; 
    }

    if(c2->x < 0 || c2->x > 7 || c2->y < 0 || c2->y > 7) { // Validate coordinate
        cout << "Coordinate 2 out of board. Please enter valid coordinate." << endl;
        return false; 
    }

    Piece* temp = getPiece(c1);

    if(temp->isLegal(c2)) {
        temp->setCoords(c2);
        board[c2.x][c2.y] = temp;
        board[c1.x][c1.y] = nullptr;
        return true;
    }

    cout << "That is not a legal move, please enter a new move." << endl;
    return false;
}

Piece* Board::getPiece(const Coordinate& c) {
    return board[c.x][c.y];
}

void setUpNormalBoard() {
    // Black pieces
    board[0][0] = new Rook({0,0}, Colour::Black, *this, "Rook"); 
	board[1][0] = new Knight({1,0}, Colour::Black, *this, "Knight");
	board[2][0] = new Bishop({2,0}, Colour::Black, *this, "Bishop");
    board[3][0] = new King({3,0}, Colour::Black, *this, "King");
    board[4][0] = new Queen({4,0}, Colour::Black, *this, "Queen");
	board[5][0] = new Bishop({5,0}, Colour::Black, *this, "Bishop");
	board[6][0] = new Knight({6,0}, Colour::Black, *this, "Knight");
	board[7][0] = new Rook({7,0}, Colour::Black, *this, "Rook");
    for (int i = 0; i < 8; ++i) {
        board[i][1] = new Pawn({i,1}, Colour::Black, *this, "Pawn"); // row of pawns
    }
    for(int j = 0; j < 2; j++) { // Adds two rows of pieces to vector
        for(int i = 0; i < 8; i++) {
            p.push_back(getPiece({i, j}));
        }
    }
    
    for(int i = 0; i < 8; ++i) {
        board[i][6] = new Pawn({i,6}, Colour::White, *this, "Pawn"); // row of pawns
    }

    // White pieces
    board[0][7] = new Rook({0,7}, Colour::White, *this, "Rook");
    board[1][7] = new Knight({1,7}, Colour::White, *this, "Knight");
    board[2][7] = new Bishop({2,7}, Colour::White, *this, "Bishop");
    board[3][7] = new Queen({3,7}, Colour::White, *this, "Queen");
    board[4][7] = new King({4,7}, Colour::White, *this, "King");
    board[5][7] = new Bishop({5,7}, Colour::White, *this, "Bishop");
    board[6][7] = new Knight({6,7}, Colour::White, *this, "Knight");
    board[7][7] = new Rook({7,7}, Colour::White, *this, "Rook");

    for(int j = 6; j < 8; j++) { // Adds last two rows of pieces to vector
        for(int i = 0; i < 8; i++) {
            p.push_back(getPiece({i, j}));
        }
    }
}


