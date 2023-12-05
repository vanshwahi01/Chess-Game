#ifndef __TEXTDISPLAY__
#define __TEXTDISPLAY__
#include <string>
#include <iostream>
using namespace std;

// constant size of board
int sizeboard = 8;

class TextDisplay {
    vector<vector<chartheDisplay>>;
    public:
    TextDisplay();
    ~TextDisplay();
    void notify(char ch, const Coordinate& c); // sets the coords to be the piece
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

