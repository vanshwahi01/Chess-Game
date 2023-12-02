#ifndef PLAYER_H
#define PLAYER_H
#include player.h
#include <vector>
using namespace std;

class Computer : public Player {
        int level = 1;
        vector<Pieces*> p(16);

        public:
                Computer(int level);
                int getLevel();
                void setLevel();
}

#endif
