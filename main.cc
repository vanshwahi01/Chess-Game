#include "board.h"
#include "player.h"
#include "piece.h"
#include "computer.h"
#include "coordinate.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "textdisplay.h"

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
        int y;
        iss >> y;
        coord.y = y - 1;

        return coord;
}

Coordinate whiteKCoord(Board &b) {
        for(auto p :b.getPieces()) {
                if(p->getType() == "King" && p->getColour() == Colour::White) {
                        return p->getCoords();
                }
        }
}
Coordinate blackKCoord(Board &b) {
        for(auto p :b.getPieces()) {
                if(p->getType() == "King" && p->getColour() == Colour::Black) {
                        return p->getCoords();
                }
        }
}

int main() {

        TextDisplay* td = new TextDisplay();
        Board b {td}; // this is blank board
        Colour curPlayer= Colour::White;
        string command;
        bool gameStarted = false;
        bool didSetUp = false;

        Player* p1{Colour::White};
        Player* p2{Colour::Black};
        Computer* cp1 = static_cast<Computer*>(p1);
        Computer* cp2 = static_cast<Computer*>(p2);
        //for checking specs
        int numWhiteK, numBlackK;
        string position;
        string endPosition;
        while(cin >> command) {
                if(command == "setup") { //set up
                     didSetUp = true;

                        string action;
                        string piece;
                        string colour;
                        while(cin >> action) {
                                if(action == "+") {
                                        //place piece
                                        cin >> piece >> position;

                                        //won't add the piece if it's a pawn on the first or last row of the board
                                        if(piece == "P" && (getCoordinate(position).x == 0 || getCoordinate(position).x == 7)){
                                                cout << "You can't have pawns on the first or last row of the board."<<endl;
                                                cout << "You can try adding the pawn in a valid position." << endl;
                                        }
                                        else if(piece != "K") {
                                                b.addPiece(piece, getCoordinate(position), curPlayer, b);
                                        }

                                        else{
                                                 if(curPlayer == Colour::White && numWhiteK < 1) { //only add a white k if there isn't one yet
                                                        b.addPiece(piece, getCoordinate(position), curPlayer, b);
                                                        numWhiteK++;
                                                 }
                                                 if(curPlayer == Colour::Black && numBlackK < 1) {// only add a black K if there isn't one yet
                                                        b.addPiece(piece, getCoordinate(position), curPlayer, b);
                                                        numBlackK++;
                                                 }
                                        }
                                        //doesn't add a King for a colour if you already have a King for that colour

                                }

                                else if(action == "-"){
                                        cin >> position;
                                        b.removePiece(getCoordinate(position));
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
                                                cin >> position;
                                             //   King temp {c, Colour::White, *b, "King"};
                                                if((getCoordinate(position).x < 0) || (getCoordinate(position).x > 7)|| (getCoordinate(position).y > 0)|| (getCoordinate(position).y > 7)){//temp.isLegal(getCoordiante(position))){
                                                        b.addPiece("K", getCoordinate(position), Colour::White, b);
                                                } else{
                                                        cout << "That isn't a legal position for the King, please provide an alternate position" << endl;
                                                }

                                        }

                                        while(numBlackK < 1){//we need to add
                                                cout << "You're missing a black King" << endl;
                                                cout << "Provide the coordinates for the King, ex. 'a1'" << endl;
                                                cin >> position;
                                               // King temp {c, Colour::Black, *b, "King"};
                                                if((getCoordinate(position).x < 0) || (getCoordinate(position).x > 7)|| (getCoordinate(position).y > 0)|| (getCoordinate(position).y > 7)){//temp.isLegal(getCoordiante(position))){
                                                        b.("K", getCoordinate(position), Colour::Black, b)
                                                } else{
                                                        cout << "That isn't a legal position for the King, please provide an alternate position" << endl;
                                                }

                                        }

                                        //there's shouldn't be more than 1 of each King after setup command


                                        // DO I EVEN NEED THIS CHECK IF I DONT ADD PAWNS ON THE FIRST AND LAST ROW ANYWAYS

                                        //checking no pawns on first and last rows
                                        // for(int j = 0; j < 8 ; i++) {
                                        // Coordinate d{0, j};
                                        //         ifb.getPiece(d)->getType() == "Pawn") { //the piece is a pawn
                                        //                 b.removePiece(d); //they move it
                                        //                 cout << "Pawn from the first row was removed" << endl;
                                        //         }
                                        //         d.x = 7;
                                        //         //checking last row
                                        //         ifb.getPiece(d)->getType() == "Pawn") { //the piece is a pawn
                                        //                 b.removePiece(d); // they move it
                                        //                 cout << "Pawn from the last row was removed" << endl;
                                        //         }
                                        // }
                                        //checking that king isn't in a checked posiiton
                                        //iterate through every piece on opposing side, call possible moves on those piece, check if any of those coordinates match King's coordinates'

                                        //checking white King
                                        //Figure out where both Kings are
                                        Coordinate whiteK = whiteKCoord(b), blackK = blackKCoord(b);
                                        if (b.getPiece(whiteK).isChecked(b)){

                                                cout << "Your white King is in a checked position, please move it somewhere else" << endl;
                                                //display the board
                                                cout << b;


                                                cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                cin >> position;

                                                while(b.getPiece(whiteK)->isLegal(getCoordinate(position))) {
                                                        cout << "Your white King is in a checked position, please move it somewhere else" << endl;
                                                        //display the board
                                                        cout <<b;
                                                        cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                        cin >> position;
                                                }

                                                b.move(whiteK, getCoordinate(position));

                                        }
                                        if(b.getPiece(blackK)->isChecked(b)){
                                                cout << "Your black King is in a checked position, please move it somewhere else" << endl;
                                                //display the board
                                                cout << b;
                                                cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                cin >> position;
                                                while(b.getPiece(blackK)->isLegal(getCoordinate(position))) {
                                                        cout << "Your black King is in a checked position, please move it somewhere else" << endl;
                                                        //display the board
                                                        cout << b;
                                                        cout << "Please provide new coordinates for the King (ex. 'a1')" << endl;
                                                        cin >> position;
                                                }
                                                b.move(whiteK, getCoordinate(position));
                                        }

                                        break;
                                } //end of if done
                                else{
                                        cout << "You didn't provide a valid command, please start your command with +, -, or =" << endl;
                                        cout << "enter 'done' if you're done with set up" << endl;
                                }

                        }
                } //end of set up command
                else if(command == "game") {
                        
                        if(!didSetUp) {
                                b.setUpNormalBoard();
                        }
                        string white_player;
                        string black_player;
                        cin >> white_player >> black_player; //computer[1]
                        if(white_player != "human") {
                                istringstream iss{white_player};
                                char level;
                                for(int i = 0; i < 10; i++){iss >> level;}
                                cp1->setLevel(level - '0');

                        }
                        if(black_player != "human") {
                                istringstream iss{black_player};
                                char level;
                                for(int i = 0; i < 10; i++){iss >> level;}
                                cp2->setLevel(level - '0');

                        }
                        gameStarted = true;


                }//end of game if

                else if(command == "resign") {
                        if(curPlayer == Colour::White) p2->incScore();
                        else p1->incScore();
                        cout << "----- Game finished -------" << endl;
                }
                else if (command == "move"){
                        Computer* temp = static_cast<Computer*>(p1);
                        Computer* temp2 = static_cast<Computer*>(p2);
                        int pLevel = cp1->getLevel();
                        int p2Level = cp2->getLevel();
                        if(temp){ // if player 1 is a computer i.e. dynamic cast worked

                                if(pLevel == 1){
                                        p1->randomPiece(b);

                                }
                                else if (pLevel == 2){

                                }
                        }
                        else{// p1 is human
                                cin >> position >> endPosition;
                                b.move(getCoordinate(position), getCoordinate(endPosition));

                        }
                        //black goes

                        if(temp2){
                                if(p2Level == 1){
                                        p2->randomPiece(b);
                                        //level 1 move function: get a random index of pieces vector, check if its the right colour, get random index of possible moves vector

                                       // b.move(getCoordinate(position), getCoordinate(endPosition));
                                }
                        }

                        else{//p2 is a human
                                cin >> position >> endPosition;
                                b.move(getCoordinate(position), getCoordinate(endPosition));
                        }

                        if(b.getPiece(whiteKCoord(b))->possibleMoves(b, b.getPiece(whiteKCoord(b)), whiteKCoord(b)).empty()){ //whiteK was checkmated
                                p2->incScore();
                                cout << "Game over: Black wins";
                                //display the board
                                cout << b;
                                break;

                        }
                        if(b.getPiece(blackKCoord(b))->possibleMoves(b, b.getPiece(blackKCoord(b)), blackKCoord(b)).empty()){ //blackK was checkmated
                                p1->incScore();
                                cout << "Game over: White wins";
                                //display the board
                                cout << b;
                                break;
                        }

                        bool isStalemate = false;
                        for(auto p: b.getPieces()) {
                                 if(p->getColour() != curPlayer) { // opposing player's colour
                                        if(!p->possibleMoves().empty()) {//possible moves of opponent's pieces - if it's not empty you have moves so there's no stalemate
                                                isStalemate = false;
                                                break;
                                        }
                                        isStalemate = true; //if the if statement is never triggered, the opponent has no possible moves i.e. stalemate
                                }
                        }
                        if(isStalemate){ // Add second condition of stalemate (insufficent material)
                                p1->draw();
                                p2->draw();
                                break;
                        }
                        if(curPlayer == Colour::White){
                                curPlayer = Colour::Black;
                        } else curPlayer = Colour::White;
                }
                 else {
                        //possible typo
                        cout << "You didn't output a valid command!" << endl;
                        cout << "You said: " << command << endl;
                        continue;
                }


        }//end of while

        delete td;
        delete p1;
        delete p2;
        delete cp1;
        delete cp2;
        
}//end of main