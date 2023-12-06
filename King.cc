#include <vector>
#include "King.h"

using namespace std;

King::King(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

bool King::isChecked(Board& b) {
    for(auto p : b.getPieces()) { // Iterate through all the pieces on the board
        for(auto i : p->possibleMoves(b, *p, p->getCoords())) { // Iterate through the possible moves of i
            if(i == this->getCoords()) { // checking if king is in checked position
                    return true;
            }
        }
    }
    return false;
}

bool King::willBeChecked(Board& b, const Coordinate& c) {
    for(auto p : b.getPieces()) { // Iterate through all the pieces on the board
        for(auto i : p->possibleMoves(b, *p, p->getCoords())) { // Iterate through the possible moves of i
            if(i == c) { // checking if king is in checked position
                    return true;
            }
        }
    }
    return false;
}

vector<Coordinate> King::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);
    Coordinate temp{0,0};

    temp.x = c.x - 1;
    temp.y = c.y + 1;
    if((c.x - 1 > -1 && c.y + 1 < 8 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Left forward diagnol
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.x = c.x;
    if((c.y + 1 < 8 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Straight ahead
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.x = c.x + 1;
    temp.y = c.y + 1;
    if((c.x + 1 < 8 && c.y + 1 < 8 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Right forward diagnol
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.x = c.x + 1;
    temp.y = c.y;
    if((c.x + 1 < 8 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Right horizontal
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.x = c.x + 1;
    temp.y = c.y - 1;
    if((c.x + 1 < 8 && c.y - 1 > -1 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Right backwards diagnol
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.x = c.x;
    if((c.y - 1 > -1 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Vertical backwards
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.x = c.x - 1;
    if((c.x - 1 > -1 && c.y - 1 > -1 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Left backwards diagnol
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }

    temp.y = c.y;
    if((c.x - 1 > -1 && b.isOccupied(temp) && b.getPiece(temp)->getColour() != p.getColour()) || !b.isOccupied(temp)) { // Left horizontal
        if(!willBeChecked(b, temp)) { // Check if the king will be checked at the new location
            pMoves.push_back(temp);
        }
    }
    
    temp.x = c.x + 1;
    Coordinate temp2{c.x + 2, c.y}, temp3{c.x + 3, c.y};

    if(c.x + 2 < 8 && !b.isOccupied(temp) && !b.isOccupied(temp2) && p.getNumMoves() == 0) { // Check for castling
        for(auto i: b.getPieces()) { // Looking for the correct king
            if(i->getType() == "Rook" && i->getColour() == p.getColour()) { // Find the correct King
                if(i->getNumMoves() == 0 && i->getCoords() == temp3) { // Check if it has moved yet
                    pMoves.push_back({temp2});
                }
                break;
            }
        }
    }

    return pMoves;
}