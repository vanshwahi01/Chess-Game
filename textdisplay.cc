#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() : theDisplay{vector<vector<char>>(8, vector<char>(8, ' '))} {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(i % 2 == 0) { // Every other row
        if(j % 2 == 0) { // Every other column
          theDisplay[i][j] = '_';
        }
      } else {
        if(j % 2 == 1) {
          theDisplay[i][j] = '_';
        }
      }
    }
  }
}

TextDisplay::~TextDisplay() {
  theDisplay.clear();
}

void TextDisplay::notify(char ch, int x, int y) {
    theDisplay[x][y] = ch;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int i = 0; i < 8; i++) {
    for (int j; j < 8; j++) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}
