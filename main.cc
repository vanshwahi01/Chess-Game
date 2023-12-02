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
                                                Coordinate C = getCoordinate(position);

                                                delete b[c.x][c.y]->piece;//remove piece

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

                                                //need to some how set piece type and colour
                                                b[kingC.x][kingC.y]->setPiece("King");
                                        
                                            }

                                            while(numBlackK < 1){//we need to add
                                                cout << "You're missing a black King" << endl;
                                                cout << "Provide the coordinates for the King, ex. 'a1'" << endl;
                                                string coordinates;
                                                cin >> coordinates;
                                                Coordinates kingC = getCoordinate(coordinates);

                                                //need to some how set piece type and colour
                                                b[kingC.x][kingC.y]->setPiece("King");
                                        
                                            }

                                            //checking no pawns on first and last rows
                                            for(int j = 0; j < 8 ; i++) {
                                                Pawn* pawn({0,0}, Colour::White, b);
                                                Coordinate d{0, j}
                                                if(b->getPiece(d) = dynamic_cast<Pawn*>(pawn)) { //the piece is a pawn
                                                        b->removePiece(d);
                                                        cout << "Pawn from the first row was removed" << endl;
                                                }
                                                d.x = 7;
                                                if(b->getPiece(d) = dynamic_cast<Pawn*>(pawn)) { //the piece is a pawn
                                                        b->removePiece(d);
                                                        cout << "Pawn from the last row was removed" << endl;
                                                }
                                            }
                                            delete pawn;

                                            //checking that king isn't in a checked posiiton
                                            iterate through every piece on opposing side, call possible moves on those piece, check if any of those coordinates match King's coordinates'
                                            
                                            //checking white King
                                            //Figure out where the King is

                                            //Compare every possible move from every piece on the board with the Coordinate of the King
                                            for(int i = 0; i < b->piece.size() ; i++) {
                                                for(int j = 0; j < b->piece.size(); j++) {
                                                        if(b->piece)
                                                }
                                            }
                                            b->piece
                                            
                                            
                                            
                                        }

                                }
                        }
                        if(command == "game") {
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
                        
                        if(command == "resign") {
                            if(curPlayer == Colour::White) p2.incScore();
                            else p1.incScore();
                        }
                        //calculate scores

                        


        }//end of while
}//end of main
