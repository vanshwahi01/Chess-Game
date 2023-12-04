#include <vector>
#include "Piece.h"

using namespace std;

Rook::Rook(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

vector<Coordinate> Rook::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {
    vector<Coordinates> pMoves[0];
    
    for(int y = p->getCoords().y + 1; y < 7; y++) { // Forward Straight
        if(b->isOccupied({c->x, y}) && b->getPiece({c->x, y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({c->x, y}) && b->getPiece({c->x, y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({c->x, y});
            break;
        }

        if(!b->isOccupied({c->x, y})) pMoves.push_back({c->x, y}); // If space is empty, add it to vector
    }

    for(int y = p->getCoords().y - 1; y > - 1; y--) { // Backwards straight
        if(b->isOccupied({c->x, y}) && b->getPiece({c->x, y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({c->x, y}) && b->getPiece({c->x, y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({c->x, y});
            break;
        }

        if(!b->isOccupied({c->x, y})) pMoves.push_back({c->x, y}); // If space is empty, add it to vector
    }

    for(int x = p->getCoords().x - 1; x > -1; x--) { // Left straight
        if(b->isOccupied({x, c->y}) && b->getPiece({x, c->y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({x, c->y}) && b->getPiece({x, c->y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, c->y});
            break;
        }

        if(!b->isOccupied({x, c->y})) pMoves.push_back({x, c->y}); // If space is empty, add it to vector
    }

    for(int x = p->getCoords().x + 1; x < 7; x++) { // Right straight
        if(b->isOccupied({x, c->y}) && b->getPiece({x, c->y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({x, c->y}) && b->getPiece({x, c->y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, c->y});
            break;
        }

        if(!b->isOccupied({x, c->y})) pMoves.push_back({x, c->y}); // If space is empty, add it to vector
    }

    if(!b->isOccupied({c->x + 1, y}) && !b->isOccupied({c->x + 2, y}) && p->getNumMoves() == 0) { // Check for castling
        for(auto i: b->getPieces()) { // Looking for the correct king
            if(i->getType == "King" && i->getColour() == p->getColour()) { // Find the correct King
                if(i->getNumMoves() == 0) { // Check if it has moved yet
                    for(auto j : b->pieces) { // Iterate over the rest of the board's pieces
                        for(auto w : j->possibleMoves(b, j, j->getCoords())){ // checking if king is in checked position
                            if(w == i.getCoords()) {               
                                    return pMoves;
                            }
                        }
                    }
                    pMoves.push_back({{c->x + 2, y}});
                }
                break;
            }
        }
    }

    return pMoves;
}