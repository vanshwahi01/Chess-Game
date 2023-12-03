#include "board.h"
#include "player.h"
#include "pieces.h"
#include "coordinate.h"

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
        
}

int main() {

        Board* b;
        Colour curPlayer= Colour::White;
        string command;

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
                                        if(piece == "King"){
                                                
                                                //don't add a king if you already have one
                                                if((curPlayer == Colour::White && numWhiteK < 1) || curPlayer == Colour::Black && numBlackK < 1 ) {
                                                Coordinate c = getCoordinate(position);
                                                        b[c.x][c.y]->piece = piece;
                                                }
                                                
                                        } 
                                        else { 
                                                Coordinate c = getCoordinate(position);
                                                b[c.x][c.y]->piece = piece;
                                        }

                                }
                                if(action == "-"){
                                        cin >> position;
                                        Coordinate c = getCoordinate(position);
                                        b->removePiece(c);

                                }
                                if(action == "=") {
                                        cin >> colour;
                                        if(colour == "white") curPlayer = Colour::White;
                                        else curPlayer = Colour::Black;
                                }
                                if(action == "done") {
                                        //need to check specs for valid board
                                        while(numWhiteK < 1){//we need to add
                                        cout << "You're missing a white King" << endl;
                                        cout << "Provide the coordinates for the King, ex. 'a1'" << endl;
                                        string coordinates;
                                        cin >> coordinates;
                                        Coordinates kingC = getCoordinate(coordinates);

                                        b->setPiece("King", Colour::White, kingC);
                                
                                        }

                                        while(numBlackK < 1){//we need to add
                                        cout << "You're missing a black King" << endl;
                                        cout << "Provide the coordinates for the King, ex. 'a1'" << endl;
                                        string coordinates;
                                        cin >> coordinates;
                                        Coordinates bKingC = getCoordinate(coordinates);

                                        //need to some how set piece type and colour
                                        b->setPiece("King", Colour::Black, bKingC);
                                
                                        }

                                        //checking no pawns on first and last rows
                                        for(int j = 0; j < 8 ; i++) {
                                        Coordinate d{0, j};
                                        if(b->getPiece(d)->getType() == "Pawn") { //the piece is a pawn
                                                b->removePiece(d); //they move it
                                                cout << "Pawn from the first row was removed" << endl;
                                        }
                                        d.x = 7;
                                        if(b->getPiece(d)->getType() == "Pawn") { //the piece is a pawn
                                                b->removePiece(d); // they move it
                                                cout << "Pawn from the last row was removed" << endl;
                                        }
                                        }
                                        //checking that king isn't in a checked posiiton
                                        iterate through every piece on opposing side, call possible moves on those piece, check if any of those coordinates match King's coordinates'
                                        
                                        //checking white King
                                        //Figure out where both Kings are
                                        Coordinate whiteK = whiteKCoord(b), blackK = blackKCoord(b);
                                        if(whiteKChecked(b, whiteK)) {
                                                b->removePiece(whiteK);
                                                cout << "Your white King is in a checked position, please move it somewhere else" << endl;
                                                //display the board
                                                cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                string tempInput;
                                                cin << tempInput;
                                                Coordinate temp = getCoordinate(tempInput);
                                                while(!b->getPiece(whiteK)->isLegal(temp)) {
                                                        cout << "Your white King is in a checked position, please move it somewhere else" << endl;
                                                        //display the board
                                                        cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                        cin << tempInput;
                                                        temp = getCoordinate(tempInput);
                                                }
                                                b->move(b->getPiece(whiteK), temp);

                                        }
                                        if(blackKChecked(b, blackK)) {
                                                b->removePiece(blackK);
                                                cout << "Your black King is in a checked position, please move it somewhere else" << endl;
                                                //display the board
                                                cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                string tempBInput;
                                                cin << tempBInput;
                                                Coordinate tempB = getCoordinate(tempBInput);
                                                while(!b->getPiece(blackK)->isLegal(temp)) {
                                                        cout << "Your black King is in a checked position, please move it somewhere else" << endl;
                                                        //display the board
                                                        cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                        cin << tempBInput;
                                                        tempB = getCoordinate(tempBInput);
                                                }
                                                b->move(b->getPiece(whiteK), tempB);
                                        }
                                        
                                } //end of if done

                        }
                }
                else if(command == "game") {
                        string white-player;
                        string black-player;
                        cin << white-player << black-player;
                        if(white-player == "human") {
                                Player* p1;
                        } else {
                                Computer* p1;
                                istringstream iss{white-player};
                                char level;
                                for(int i = 0; i < 10; i++){iss >> level;}
                                int p1.level = level - '0';

                        }
                        if(black-player == "human") {
                                Player* p2;
                        } else {
                                Computer* p2;
                                istringstream iss{black-player};
                                char level;
                                for(int i = 0; i < 10; i++){iss >> level;}
                                int p2.level = level - '0';

                        }

                
                }//end of game if
                
                else if(command == "resign") {
                        if(curPlayer == Colour::White) p2.incScore();
                        else p1.incScore();
                }
                else {
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
                                        increment both scores by 0.5
                                        break;
                                }
                        }

                }                     


        }//end of while
}//end of main
