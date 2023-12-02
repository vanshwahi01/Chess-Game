#include <vector>
#include "Piece.h"

using namespace std;

Pawn::Pawn(Coordinate c, Colour colour, Board b) : Piece{c, colour, b} {}

void Pawn::promote(const Board& b, Piece& p) {

}

vector<Coordinate> Pawn::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {
    vector<Coordinates> pMoves[0];
    if(!b->getPiece({c->x, c->y + 1})->isOccupied()) { // Check if the pawn can move forward
        pMoves.push_back({c->x, c->y + 1});
    }
    if(b->getPiece({c->x - 1, c->y + 1})->isOccupied()) { // Check if left diagnol is occupied
        if(b->getPiece({c->x - 1, c->y + 1})->colour != p->colour) { // Check if it is opposing team's piece
            pMoves.push_back({c->x - 1, c->y + 1});
        }
    }

    if(b->getPiece({c->x + 1, c->y + 1})->isOccupied()) { // Check if right diagnol is occupied
        if(b->getPiece({c->x + 1, c->y + 1})->colour != p->colour) { // Check if it is opposing team's piece
            pMoves.push_back({c->x + 1, c->y + 1});
        }
    }
    // Add checks for enPassant and double move at beginning
    return pMoves;
}
 
// To check if king is checked, call possibleMoves() on every opposing piece and iterate through given vectors to see if king's coordinates are in given vector