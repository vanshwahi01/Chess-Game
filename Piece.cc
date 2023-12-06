#include <vector>
#include <string>
#include "Piece.h"
#include "board.h"

using namespace std;

Piece::Piece(Coordinate c, Colour colour2, string type) : coords{c}, colour{colour2}, type{type}, numMoves{0} {}

Piece::~Piece() {}

int Piece::getNumMoves() {
    return numMoves;
}

Colour Piece::getColour() {
    return colour;
}

Coordinate Piece::getCoords() {
    return coords;
}

string Piece::getType() {
    return type;
}

bool Piece::isLegal(const Coordinate& c, Board& b) {
    Coordinate whiteK, blackK;
    for(auto p: b->getPieces()) {
        if(p->getType() == "King" && p->getColour() == Colour::White) {
            whiteK = p->getCoords(); // Keep track of white king's coords
        }
        if(p->getType() == "King" && p->getColour() == Colour::Black) {
            blackK = p->getCoords(); // Keep track of white king's coords
        }
    }

    Coordinate temp = this->getCoords();
    for(auto p: possibleMoves(b, *this, temp)) { // Checks to see if c is a legal move
        if(p == c && (p != whiteK || p != blackK)) return true; // Make sure to double check this line
        // Line above should look for a matching coordinate in the given vector and make sure it isn't equal to
        // position of either king
    }
    return false;
}

void Piece::setCoords(const Coordinate& c) {
    coords = c;
}