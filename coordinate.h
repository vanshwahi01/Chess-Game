#ifndef COORDINATE_H
#define COORDINATE_H
using namespace std;

class Coordinate {
        public:
                Coordinate();
                Coordinate(int x, int y);
                int x = 0;
                int y = 0;
                bool operator==(const Coordinate& other);
};

#endif
