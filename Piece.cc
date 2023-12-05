#include <vector>
#include "piece.h"

using namespace std;

Piece::Piece(Coordinate c, Colour colour, const Board& b, string type) : coords{c}, colour{colour}, curBoard{b}, type{type} numMoves{0} {}

vector<Coordinate> Piece::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {}

void Piece::move(const Coordinate& c, const Board& b) {

}

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

bool Piece::isLegal(const Coordinate& c) {
    for(auto p: curBoard->getPieces()) {
        if(p->getType() == "King" && p->getColour == Colour::White) {
            Coordinate whiteK = p->getCoords(); // Keep track of white king's coords
        }
        if(p->getType() == "King" && p->getColour == Colour::Black) {
            Coordinate blackK = p->getCoords(); // Keep track of white king's coords
        }
    }

    for(auto p: possibleMoves(curBoard, *this, this->getCoords())) { // Checks to see if c is a legal move
        if(p == c && (p != whiteK || p != blackK)) return true; // Make sure to double check this line
        // Line above should look for a matching coordinate in the given vector and make sure it isn't equal to 
        // position of either king
    }
    return false;
}

void Piece::setCoords(const Coordinate& c) {
    coords = c;
}

Board::Board() : x{0} {}

Coordinate::Coordinate() : x{0}, y{0} {}

Coordinate::Coordinate(int x, int y) : x{x}, y{y} {}

bool Coordinate::operator==(const Coordinate& other) {
    if(this->x == other.x && this->y == other.y) return true;
    return false;
}
