#include <vector>
#include "Piece.h"

using namespace std;

Piece::Piece(Coordinates c, Colour colour) : coords{c}, colour{colour} {}

vector<Coordinates> Piece::possibleMoves(const Board& b, const Piece& p, const Coordinates& c) {}

void Piece::move(const Coordinates& c) {}

Piece::~Piece() {}

Board::Board() : x{0} {}

Coordinates::Coordinates() : x{0}, y{0} {}

Coordinates::Coordinates(int x, int y) : x{x}, y{y} {}