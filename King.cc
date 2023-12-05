#include <vector>
#include <string>
#include "Piece.h"
#include "King.h"

using namespace std;

King::King(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

bool King::isChecked(const Board& b) {
    for(auto p : b.getPieces()) { // Iterate through all the pieces on the board
        for(auto i : p.possibleMoves(b, p, p.getCoords())) { // Iterate through the possible moves of i 
            if(i == this->getCoords()) { // checking if king is in checked position
                    return true;
            }
        }
    }
    return false;
}

bool King::willBeChecked(const Board& b, const Coordinate& c) {
    for(auto p : b.getPieces()) { // Iterate through all the pieces on the board
        for(auto i : p.possibleMoves(b, p, p.getCoords())) { // Iterate through the possible moves of i 
            if(i == c) { // checking if king is in checked position
                    return true;
            }
        }
    }
    return false;
}

vector<Coordinate> King::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);
    
    if((c.x - 1 > -1 && c.y + 1 < 8 && b.isOccupied({c.x - 1, c.y + 1}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x - 1, c.y + 1})) { // Left forward diagnol
        if(!willBeChecked(b, {c.x - 1, c.y + 1})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x - 1, c.y + 1});
        }
    }

    if((c.y + 1 < 8 && b.isOccupied({c.x, c.y + 1}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x, c.y + 1})) { // Straight ahead
        if(!willBeChecked(b, {c.x, c.y + 1})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x, c.y + 1});
        }
    }

    if((c.x + 1 < 8 && c.y + 1 < 8 && b.isOccupied({c.x + 1, c.y + 1}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x + 1, c.y + 1})) { // Right forward diagnol
        if(!willBeChecked(b, {c.x + 1, c.y + 1})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x + 1, c.y + 1});
        }
    }

    if((c.x + 1 < 8 && b.isOccupied({c.x + 1, c.y}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x + 1, c.y})) { // Right horizontal
        if(!willBeChecked(b, {c.x + 1, c.y})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x + 1, c.y});
        }
    }

    if((c.x + 1 < 8 && c.y - 1 > -1 && b.isOccupied({c.x + 1, c.y - 1}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x + 1, c.y - 1})) { // Right backwards diagnol
        if(!willBeChecked(b, {c.x + 1, c.y - 1})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x + 1, c.y - 1});
        }
    }

    if((c.y - 1 > -1 && b.isOccupied({c.x, c.y - 1}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x, c.y - 1})) { // Vertical backwards
        if(!willBeChecked(b, {c.x, c.y - 1})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x, c.y - 1});
        }
    }

    if((c.x - 1 > -1 && c.y - 1 > -1 && b.isOccupied({c.x - 1, c.y - 1}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x - 1, c.y - 1})) { // Left backwards diagnol
        if(!willBeChecked(b, {c.x - 1, c.y - 1})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x - 1, c.y - 1});
        }
    }

    if((c.x - 1 > -1 && b.isOccupied({c.x - 1, c.y}) && b.getPiece()->getColour() != p.getColour()) || !b.isOccupied({c.x - 1, c.y})) { // Left horizontal
        if(!willBeChecked(b, {c.x - 1, c.y})) { // Check if the king will be checked at the new location
            pMoves.push_back({c.x - 1, c.y});
        }
    }

    if(c.x + 2 < 8 && !b.isOccupied({c.x + 1, y}) && !b.isOccupied({c.x + 2, y}) && p.getNumMoves() == 0) { // Check for castling
        for(auto i: b.getPieces()) { // Looking for the correct king
            if(i->getType == "Rook" && i->getColour() == p.getColour()) { // Find the correct King
                if(i->getNumMoves() == 0 && i->getCoords() == {c.x + 3, c.y}) { // Check if it has moved yet
                    pMoves.push_back({c.x + 2, y});
                }
                break;
            }
        }
    }

    return pMoves;
}
