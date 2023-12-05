#include <vector>
#include "Piece.h"

using namespace std;

Queen::Queen(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

vector<Coordinate> Queen::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {
    vector<Coordinates> pMoves[0];
    
    for(int x = p->getCoords().x + 1, y = p->getCoords().y + 1; x < 7 && y < 7; x++, y++) { // Right forward diagnol
        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b->isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    for(int x = p->getCoords().x + 1, y = p->getCoords().y - 1; x < 7 && y > -1; x++, y--) { // Right backwards diagnol
        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b->isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    for(int x = p->getCoords().x - 1, y = p->getCoords().y + 1; x > -1 && y < 7; x--, y++) { // Left forward diagnol
        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b->isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    for(int x = p->getCoords().x - 1, y = p->getCoords().y - 1; x > -1 && y > -1; x--, y--) { // Left backwards diagnol
        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() == p->getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b->isOccupied({x, y}) && b->getPiece({x, y}).getColour() != p->getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b->isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

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

    return pMoves;
}
