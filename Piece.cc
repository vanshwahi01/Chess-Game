#include <vector>
#include "Piece.h"

using namespace std;

Piece::Piece(Coordinates c, Colour colour, Board b) : coords{c}, colour{colour}, curBoard{b}, numMoves{0} {}

vector<Coordinates> Piece::possibleMoves(const Board& b, const Piece& p, const Coordinates& c) {}

void Piece::move(const Coordinates& c, const Board& b) {

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

bool Piece::isLegal(const Coordinates& c) {
    for(auto p: possibleMoves(curBoard, *this, this->getCoords())) { // Checks to see if c is a legal move
        if(p == c) return true;
    }
    return false;
}

Board::Board() : x{0} {}

Coordinates::Coordinates() : x{0}, y{0} {}

Coordinates::Coordinates(int x, int y) : x{x}, y{y} {}

bool Coordinates::operator==(const Coordinates& other) {
    if(this->x == other.x && this->y == other.y) return true;
    return false;
}