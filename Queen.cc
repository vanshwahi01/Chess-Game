#include <vector>
#include <string>
#include "Queen.h"

using namespace std;

Queen::Queen(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

vector<Coordinate> Queen::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);

    for(int i = p.getCoords().x + 1, j = p.getCoords().y + 1; (i < 7) && (j < 7); i++, j++) { // Right forward diagnol
        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({i, j});
            break;
        }

        if(!b.isOccupied({i, j})) pMoves.push_back({i, j}); // If space is empty, add it to vector
    }

    for(int i = p.getCoords().x + 1, j = p.getCoords().y - 1; i < 7 && j > -1; i++, j--) { // Right backwards diagnol
        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({i, j});
            break;
        }

        if(!b.isOccupied({i, j})) pMoves.push_back({i, j}); // If space is empty, add it to vector
    }

    for(int i = p.getCoords().x - 1, j = p.getCoords().y + 1; i > -1 && j < 7; i--, j++) { // Left forward diagnol
        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({i, j});
            break;
        }

        if(!b.isOccupied({i, j})) pMoves.push_back({i, j}); // If space is empty, add it to vector
    }

    for(int i = p.getCoords().x - 1, j = p.getCoords().y - 1; i > -1 && j > -1; i--, j--) { // Left backwards diagnol
        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() == p.getColour()) break; // Stop checking the diagonal once there is a piece that is your colour

        if(b.isOccupied({i, j}) && b.getPiece({i, j})->getColour() != p.getColour()) {
            // If the piece blocking the path is the opposite colour, add it to the vector and break
            pMoves.push_back({i, j});
            break;
        }

        if(!b.isOccupied({i, j})) pMoves.push_back({i, j}); // If space is empty, add it to vector
    }

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
    return pMoves;
}