#include "coordinate.h"

Coordinate::Coordinate() : x{0}, y{0} {}

Coordinate::Coordinate(int x, int y) : x{x}, y{y} {}

bool Coordinate::operator==(const Coordinate& other) {
    if(this->x == other.x && this->y == other.y) return true;
    return false;
}
