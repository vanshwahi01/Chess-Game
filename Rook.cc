#include <vector>
#include "Rook.h"
#include "King.h"

using namespace std;

Rook::Rook(Coordinate c, Colour colour, string type) : Piece{c, colour, type} {}

Rook::~Rook() {}

vector<Coordinate> Rook::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);

    for(int j = p.getCoords().y + 1; j < 7; j++) { // Forward Straight
        if(b.isOccupied({c.x, j}) && b.getPiece({c.x, j})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({c.x, j}) && b.getPiece({c.x, j})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({c.x, j});
            break;
        }

        if(!b.isOccupied({c.x, j})) pMoves.push_back({c.x, j}); // If space is empty, add it to vector
    }

    for(int j = p.getCoords().y - 1; j > - 1; j--) { // Backwards straight
        if(b.isOccupied({c.x, j}) && b.getPiece({c.x, j})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({c.x, j}) && b.getPiece({c.x, j})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({c.x, j});
            break;
        }

        if(!b.isOccupied({c.x, j})) pMoves.push_back({c.x, j}); // If space is empty, add it to vector
    }

    for(int i = p.getCoords().x - 1; i > -1; i--) { // Left straight
        if(b.isOccupied({i, c.y}) && b.getPiece({i, c.y})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({i, c.y}) && b.getPiece({i, c.y})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({i, c.y});
            break;
        }

        if(!b.isOccupied({i, c.y})) pMoves.push_back({i, c.y}); // If space is empty, add it to vector
    }

    for(int i = p.getCoords().x + 1; i < 7; i++) { // Right straight
        if(b.isOccupied({i, c.y}) && b.getPiece({i, c.y})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({i, c.y}) && b.getPiece({i, c.y})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({i, c.y});
            break;
        }

        if(!b.isOccupied({i, c.y})) pMoves.push_back({i, c.y}); // If space is empty, add it to vector
    }
    // changed y to c.y in line 60
    if(c.x - 2 > -1 && !b.isOccupied({c.x - 1, c.y}) && !b.isOccupied({c.x - 2, c.y}) && p.getNumMoves() == 0) { // Check for castling
        for(auto i: b.getPieces()) { // Looking for the correct king
            if(i->getType() == "King" && i->getColour() == p.getColour()) { // Find the correct King
                King* k = static_cast<King*>(i);
                Coordinate temp {c.x - 3, c.y};
                if(k->getNumMoves() == 0 && !k->isChecked(b) && (k->getCoords() == temp)) { // Check if it has moved yet
                    pMoves.push_back({c.x - 2, c.y});
                }
                delete k;
                break; // found king
            }
        }
    }

    return pMoves;
}
