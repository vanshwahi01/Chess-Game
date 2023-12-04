#include <string>
#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <string>
#include <iostream>
using namespace std;

// constant size of board
int sizeboard = 8;

class TextDisplay {
    char **theDisplay;
    public:
    TextDisplay();
    ~TextDisplay();
    void notify(char ch, int r, int c); // sets the coords to be the piece
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

