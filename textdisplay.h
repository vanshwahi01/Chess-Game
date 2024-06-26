#ifndef __TEXTDISPLAY__
#define __TEXTDISPLAY__
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class TextDisplay {
    vector<vector<char>> theDisplay;
    public:
    TextDisplay();
    ~TextDisplay();
    void notify(char ch, int x, int y); // sets the coords to be the piece
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
