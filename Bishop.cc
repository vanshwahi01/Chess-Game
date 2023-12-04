#include <vector>
#include "Piece.h"

using namespace std;

Bishop::Bishop(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

vector<Coordinate> Bishop::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {
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

    return pMoves;
}