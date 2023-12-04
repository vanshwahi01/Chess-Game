#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {
  theDisplay = new char*[sizeboard];
  for (int i=0; i < sizeboard; i++) {
    theDisplay[i]=new char[sizeboard];
    }
}

TextDisplay::~TextDisplay() { 
  for (int i =0; i < sizeboard; i++) {
    delete [] theDisplay[i];
  }
  delete [] theDisplay;
}

void TextDisplay::notify(char ch, int r, int c) {
    theDisplay[r][c]=ch;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int row=sizeboard-1 ; row>=0 ; row--) {
    for (int col=0; col < sizeboard; col++) {
      if (td.theDisplay[row][col]==' ') {
        if ((row % 2 == 0 && col % 2 == 0) ||(row % 2 !=0 && col % 2 != 0)) {
          out << "_";
        }
        else {
          out << " ";
        }
      }
      else {
        out << td.theDisplay[row][col];
      }  
    }
    out << endl;
  }  
  return out;
}

