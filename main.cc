#include "board.h"
#include "player.h"
#include "pieces.h"
#include "coordinate.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


//takes coordinate in the form [letter][number] and returns a coordinate as a 2 digit number
Coordinate getCoordinate(string c){
        Coordinate coord{0,0};
        istringstream iss{c};
        string winner;
        char row;
        iss >> row;

        switch(row) {
                case 'a': coord.x = 0; break;
                case 'b': coord.x = 1; break;
                case 'c': coord.x = 2; break;
                case 'd': coord.x = 3; break;
                case 'e': coord.x = 4; break;
                case 'f': coord.x = 5; break;
                case 'g': coord.x = 6; break;
                case 'h': coord.x = 7; break;
        }

        iss >> coord.y;

        return coord;
}

Coordinate whiteKCoord(Board &b) {
        for(auto p : b->pieces) {
                if(p->getType() == "King" && p->getColour() == Colour::White) {
                        return p->getCoords();
                }
        }
}
Coordinate blackKCoord(Board &b) {
        for(auto p : b->pieces) {
                if(p->getType() == "King" && p->getColour() == Colour::Black) {
                        return p->getCoords();
                }
        }
}

bool whiteKChecked(Board &b, Coordinate &whiteK) {
        if(p->getColour() == Colour::Black){ // looking at black pieces possible moves
                for(auto p : b->pieces) {
                        for(auto i : p->possibleMoves(b, p, p->getCoords())){ // checking if white king is in checked position
                                if(i == whiteK) {               
                                        return true;
                                }
                        }
                }
        }
        return false;
}

bool blackKChecked(Board &b, Coordinate &blackK) {
        if(p->getColour() == Colour::White){ // looking at white pieces possible moves
                for(auto p : b->pieces) {
                        for(auto i : p->possibleMoves(b, p, p->getCoords())){ // checking if black king is in checked position
                                if(i == blackK) {               
                                        return true;
                                }
                        }
                }
        }
        return false;
}

void addPiece(const string type, const Coordinate c, const Colour colour, Board &b){
        string name;
        if(type == "K") { //if we're adding a King   
                King temp {c, colour, *b, "King"};
        }
        else if(type == "Q"){ // if we're adding a Queen
                Queen temp {c, colour, *b, "Queen"};

        }
        else if(type == "B") { // if we're adding a Bishop
                Bishop temp {c, colour, *b, "Bishop"};
        }
        else if(type == "R"){ // if we're adding a Rook
                Rook temp {c, colour, *b, "Rook"};
        }
        else if(type == "N") { // if we're adding a Knight
                Knight temp {c, colour, *b, "Knight"};
        }
        else if(type == "P"){ // if we're adding a Pawn
                Pawn temp {c, colour, *b, "Pawn"};
        }
        else {
                return; // don't do anything if valid type wasn't given
        }
        //checking if another piece already exists on this coordinate
        for(auto p : b->pieces) {
                //if this new piece is being added on a coordinate that already has a piece, new piece replaces old piece
                if(p->getCoords() == c) {
                        p = temp;
                        //leave function
                        return;
                }
        }
        //adds piece to the vector of pieces
        b->getPieces().push_back(temp); //need to change to setPiece cause pieces vector is private
        
}

int main() {

        Board* b;
        Colour curPlayer= Colour::White;
        string command;
        bool gameStarted = false;

        //for checking specs
        int numWhiteK, numBlackK;
        while(cin >> command) {
                if(command == "setup") { //set up
                        string action;
                        string piece;
                        string position;
                        string colour;
                        while(cin >> action) {
                                if(action == "+") {
                                        //place piece
                                        cin >> piece >> position;

                                        //won't add the piece if it's a pawn on the first or last row of the board
                                        if(piece == "P" && (getCoordinate(position).x == 0 || getCoordinate(position).x == 7)){
                                                cout << "You can't have pawns on the first or last row of the board.";
                                        }
                                        else if(piece != "K") addPiece(piece, getCoordinate(position), curPlayer, b);
                                       
                                        else{
                                                 if(curPlayer == Colour::White && numWhiteK < 1) { //only add a white k if there isn't one yet
                                                        addPiece(piece, getCoordinate(position), curPlayer, b);
                                                        numWhiteK++;
                                                 }
                                                 if(curPlayer == Colour::Black && numBlackK < 1) {// only add a black K if there isn't one yet 
                                                        addPiece(piece, getCoordinate(position), curPlayer, b);
                                                        numBlackK++;
                                                 }
                                        }
                                        //doesn't add a King for a colour if you already have a King for that colour
                                        
                                }

                                else if(action == "-"){
                                        cin >> position;
                                        b->removePiece(getCoordinate(position));

                                }

                                else if(action == "=") {
                                        cin >> colour;
                                        if(colour == "white") curPlayer = Colour::White;
                                        else curPlayer = Colour::Black;
                                }

                                else if(action == "done") {
                                        //need to check specs for valid board
                                        while(numWhiteK < 1){//we need to add
                                                cout << "You're missing a white King" << endl;
                                                cout << "Provide the coordinates for the King, ex. 'a1'" << endl;
                                                cin << position;
                                                King temp {c, Colour::White, *b, "King"};
                                                if(temp.isLegal(getCoordiante(position))){
                                                        addPiece("K", getCoordinate(position), Colour::White, b)
                                                } else{
                                                        cout << "That isn't a legal position for the King, please provide an alternate position" << endl;
                                                }
                                
                                        }

                                        while(numBlackK < 1){//we need to add
                                                cout << "You're missing a black King" << endl;
                                                cout << "Provide the coordinates for the King, ex. 'a1'" << endl;
                                                cin << position;
                                                King temp {c, Colour::Black, *b, "King"};
                                                if(temp.isLegal(getCoordiante(position))){
                                                        addPiece("K", getCoordinate(position), Colour::Black, b)
                                                } else{
                                                        cout << "That isn't a legal position for the King, please provide an alternate position" << endl;
                                                }
                                
                                        }

                                        //there's shouldn't be more than 1 of each King after setup command


                                        DO I EVEN NEED THIS CHECK IF I DONT ADD PAWNS ON THE FIRST AND LAST ROW ANYWAYS

                                        //checking no pawns on first and last rows
                                        for(int j = 0; j < 8 ; i++) {
                                        Coordinate d{0, j};
                                                if(b->getPiece(d)->getType() == "Pawn") { //the piece is a pawn
                                                        b->removePiece(d); //they move it
                                                        cout << "Pawn from the first row was removed" << endl;
                                                }
                                                d.x = 7;
                                                //checking last row
                                                if(b->getPiece(d)->getType() == "Pawn") { //the piece is a pawn
                                                        b->removePiece(d); // they move it
                                                        cout << "Pawn from the last row was removed" << endl;
                                                }
                                        }
                                        //checking that king isn't in a checked posiiton
                                        //iterate through every piece on opposing side, call possible moves on those piece, check if any of those coordinates match King's coordinates'
                                        
                                        //checking white King
                                        //Figure out where both Kings are
                                        Coordinate whiteK = whiteKCoord(b), blackK = blackKCoord(b);
                                        if(whiteKChecked(b, whiteK)) {
                                                b->removePiece(whiteK);
                                                cout << "Your white King is in a checked position, please move it somewhere else" << endl;
                                                //display the board
                                                cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                cin << position;

                                                while(!b->getPiece(whiteK)->isLegal(getCoordinate(position))) {
                                                        cout << "Your white King is in a checked position, please move it somewhere else" << endl;
                                                        //display the board
                                                        cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                        cin << position;
                                                }
                                                
                                                b->move(b->getPiece(whiteK), getCoordinate(position));

                                        }
                                        if(blackKChecked(b, blackK)) {
                                                b->removePiece(blackK);
                                                cout << "Your black King is in a checked position, please move it somewhere else" << endl;
                                                //display the board
                                                cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                cin << position;
                                                while(!b->getPiece(blackK)->isLegal(getCoordinate(position))) {
                                                        cout << "Your black King is in a checked position, please move it somewhere else" << endl;
                                                        //display the board
                                                        cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                        cin << position;
                                                }
                                                b->move(b->getPiece(whiteK), getCoordinate(position));
                                        }

                                        break;
                                } //end of if done
                                else{
                                        cout << "You didn't provide a valid command, please start your command with +, -, or =" << endl;
                                        cout << "enter 'done' if you're done with set up" << endl;
                                }

                        }//done set up
                }
                else if(command == "game") {
                        string white-player;
                        string black-player;
                        cin << white-player << black-player;
                        if(white-player == "human") {
                                Player* p1{Colour::White};
                        } else {
                                istringstream iss{white-player};
                                char level;
                                for(int i = 0; i < 10; i++){iss >> level;}
                                Computer* p1{Colour::White, level - '0'};

                        }
                        if(black-player == "human") {
                                Player* p2{Colour::Black};
                        } else {
                                istringstream iss{black-player};
                                char level;
                                for(int i = 0; i < 10; i++){iss >> level;}
                                Computer* p2{Colour::Black, level - '0'};

                        }
                        gameStarted = true;

                }//end of game if
                
                else if(command == "resign") {
                        if(curPlayer == Colour::White) p2.incScore();
                        else p1.incScore();
                        cout << "----- Game finished -------" << endl;
                }
                else {

                        if(!gameStarted) {
                                cout << "If you wanted to play a game, start with the command:"<<endl;
                                cout << "'game white-player black-player'" << endl;
                                cout << "where white-player or black-player can be either 'human' or 'computer[1-4]" << endl;
                                cout <<endl;
                                cout << "If you weren't trying to start the game there must have been a typo in your command." << endl;
                        }
                        
                        else{ // game started
                                while(true){
                                        //white goes first
                                        //black goes
                                        if(white King is checkmated){
                                                p2->incScore();
                                                break;
                                        }
                                        if(black King is checkmated){
                                                p1->incScore();
                                                break;
                                        }
                                        if(there's a stalemate){
                                                p1->draw();
                                                p2->draw();
                                                break;
                                        }
                                }
                        }

                }                     


        }//end of while
}//end of main
