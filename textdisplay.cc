#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() : theDisplay{vector<vector<char>>(8, vector<char>(8, ' '))} {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(i % 2 == 0) { // Every other row
        if(j % 2 = 0) { // Every other column
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

void TextDisplay::notify(char ch, int r, int c) {
    theDisplay[r][c] = ch;
}

// ostream &operator<<(ostream &out, const TextDisplay &td) {
//   for (int row=sizeboard-1 ; row>=0 ; row--) {
//     for (int col=0; col < sizeboard; col++) {
//       if (td.theDisplay[row][col]==' ') {
//         if ((row % 2 == 0 && col % 2 == 0) ||(row % 2 !=0 && col % 2 != 0)) {
//           out << "_";
//         }
//         else {
//           out << " ";
//         }
//       }
//       else {
//         out << td.theDisplay[row][col];
//       }  
//     }
//     out << endl;
//   }  
//   return out;
// }

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int i = 0; i < 8; i++) {
    for (int j; j < 8; j++) {
      out << theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}

