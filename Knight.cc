#include <vector>
#include "Knight.h"

using namespace std;

Knight::Knight(Coordinate c, Colour colour, Board b, string type) : Piece{c, colour, b, type} {}

vector<Coordinate> Knight::possibleMoves(Board& b, Piece& p, Coordinate& c) {
    vector<Coordinate> pMoves(0);

    if(!b.isOccupied({c.x - 2, c.y + 1}) || b.getPiece({c.x - 2, c.y + 1}).getColour() != p.getColour()) { // 1 up 2 left
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x - 2, c.y + 1});
    }

    if(!b.isOccupied({c.x - 1, c.y + 2}) || b.getPiece({c.x - 1, c.y + 2}).getColour() != p.getColour()) { // 2 up 1 left
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x - 1, c.y + 2});
    }

    if(!b.isOccupied({c.x + 1, c.y + 2}) || b.getPiece({c.x + 1, c.y + 2}).getColour() != p.getColour()) { // 2 up 1 right
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x + 1, c.y + 2});
    }

    if(!b.isOccupied({c.x + 2, c.y + 1}) || b.getPiece({c.x + 2, c.y + 1}).getColour() != p.getColour()) { // 1 up 2 right
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x + 2, c.y + 1});
    }

    if(!b.isOccupied({c.x + 2, c.y - 1}) || b.getPiece({c.x + 2, c.y - 1}).getColour() != p.getColour()) { // 1 down 2 right
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x + 2, c.y - 1});
    }

    if(!b.isOccupied({c.x + 1, c.y - 2}) || b.getPiece({c.x + 1, c.y - 2}).getColour() != p.getColour()) { // 2 down 1 right
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x + 1, c.y - 2});
    }

    if(!b.isOccupied({c.x - 1, c.y - 2}) || b.getPiece({c.x - 1, c.y - 2}).getColour() != p.getColour()) { // 2 down 1 left
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x - 1, c.y - 2});
    }

    if(!b.isOccupied({c.x - 2, c.y - 1}) || b.getPiece({c.x - 2, c.y - 1}).getColour() != p.getColour()) { // 1 down 2 left
        // Enters if the space is free or it is occupied by the opposing colour
        pMoves.push_back({c.x - 2, c.y - 1});
    }

    return pMoves;
}