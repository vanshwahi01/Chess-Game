#include <vector>
#include "Piece.h"

using namespace std;

Piece::Piece(Coordinate c, Colour colour, Board b, string type) : coords{c}, colour{colour}, curBoard{b}, type{type} numMoves{0} {}

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
    for(auto p: possibleMoves(curBoard, *this, this->getCoords())) { // Checks to see if c is a legal move
        if(p == c) return true;
    }
    return false;
}

Board::Board() : x{0} {}

Coordinate::Coordinate() : x{0}, y{0} {}

Coordinate::Coordinate(int x, int y) : x{x}, y{y} {}

bool Coordinate::operator==(const Coordinate& other) {
    if(this->x == other.x && this->y == other.y) return true;
    return false;
}