#include <vector>
#include <string>
#include "Bishop.h"

using namespace std;

Bishop::Bishop(Coordinate c, Colour colour, string type) : Piece{c, colour, type} {}

Bishop::~Bishop() {}

vector<Coordinate> Bishop::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);
    
    for(int x = p.getCoords().x + 1, y = p.getCoords().y + 1; x < 7 && y < 7; x++, y++) { // Right forward diagnol
        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b.isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    for(int x = p.getCoords().x + 1, y = p.getCoords().y - 1; x < 7 && y > -1; x++, y--) { // Right backwards diagnol
        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b.isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    for(int x = p.getCoords().x - 1, y = p.getCoords().y + 1; x > -1 && y < 7; x--, y++) { // Left forward diagnol
        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b.isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    for(int x = p.getCoords().x - 1, y = p.getCoords().y - 1; x > -1 && y > -1; x--, y--) { // Left backwards diagnol
        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({x, y}) && b.getPiece({x, y})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({x, y});
            break;
        }

        if(!b.isOccupied({x, y})) pMoves.push_back({x, y}); // If space is empty, add it to vector
    }

    return pMoves;
}
