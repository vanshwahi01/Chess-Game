#include <string>
#include "player.h"

using namespace std;

Player::Player(Colour colour) : colour{colour} {}

int Player::getScore() {
        return score;
}

// was int before
Colour Player::getColour() {
        return colour;
}

void Player::incScore() {
        score++;
}

void Player::draw(){
    score += 0.5;
}

int Player::getTotalPieces() {
        return totalPieces;
}