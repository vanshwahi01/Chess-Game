#include "player.h"

using namespace std;

Player::Player(Colour colour) : colour{colour} {} //waiting to figure out how pieces are declared

int Player::getScore() {
        return score;
}

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
