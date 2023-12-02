#include <vector>
#include "Piece.h"

using namespace std;

Piece::Piece(Coordinate c, Colour colour, Board b) : coords{c}, colour{colour}, curBoard{b}, numMoves{0} {}

vector<Coordinate> Piece::possibleMoves(const Board& b, const Piece& p, const Coordinate& c) {}

void Piece::move(const Coordinate& c, const Board& b) {

}

Piece::~Piece() {}

void Piece::getNumMoves() {
    return numMoves;
}

void Piece::getColour() {
    return colour;
}

void Piece::getCoords() {
    return coords;
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