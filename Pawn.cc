#include <vector>
#include <string>
#include "Piece.h"
#include "Pawn.h"

using namespace std;

Pawn::Pawn(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

void Pawn::promote(Board& b, Piece& p) { // This is gonna have to be a function in Board or main
    Coordinate temp = p.getCoords(); // Set aside the pawns coordinates

    for(auto i: b.getPieces()) {
        if(i.getCoords() == p.getCoords()) // Look for the pawn
    }
}

vector<Coordinate> Pawn::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);

    if(!b.isOccupied({c.x, c.y + 1})) { // Check if the pawn can move forward
        pMoves.push_back({c.x, c.y + 1});
    }

    if(c.x > 0 && c.y < 7 && b.isOccupied({c.x - 1, c.y + 1})) { // Check if left diagnol is occupied
        if(b.getPiece({c.x - 1, c.y + 1})->colour != p.getColour()) { // Check if it is opposing team's piece
            pMoves.push_back({c.x - 1, c.y + 1});
        }
    }

    if(c.x < board.length - 1 && c.y < 7 && b.isOccupied({c.x + 1, c.y + 1})) { // Check if right diagnol is occupied
        if(b.getPiece({c.x + 1, c.y + 1})->colour != p.getColour()) { // Check if it is opposing team's piece
            pMoves.push_back({c.x + 1, c.y + 1});
        }
    }

    if(numMoves == 0 && !(b.isOccupied({c.x, c.y + 1})) && !(b.isOccupied({c.x, c.y + 2}))) {
        // Check if both space directly in front and two in front of pawn are free and that the pawn hasn't moved
        pMoves.push_back({c.x, c.y + 2}); // Add the space two spaces in front of pawn
    }

    if(b.isOccupied({c.x - 1, c.y}) && b.getPiece({c.x - 1, c.y})->getColour() != p.getColour()) { // Left side en passant check
        // Will enter statement if there is a piece on the left side of the pawn of the opposing colour
        if(b.getPiece({c.x - 1, c.y}).getType() == "Pawn" && b.getPiece({c.x - 1, c.y}).getNumMoves() == 1) {
            // Will enter statement if the piece is a pawn and it has only made one move
            pMoves.push_back({c.x - 1, c.y});
        }
    }

    if(b.isOccupied({c.x + 1, c.y}) && b.getPiece({c.x + 1, c.y})->getColour() != p.getColour()) { // Right side en passant check
        // Will enter statement if there is a piece on the left side of the pawn of the opposing colour
        if(b.getPiece({c.x + 1, c.y}).getType() == "Pawn" && b.getPiece({c.x + 1, c.y}).getNumMoves() == 1) {
            // Will enter statement if the piece is a pawn and it has only made one move
            pMoves.push_back({c.x + 1, c.y});
        }
    }
    return pMoves;
}
