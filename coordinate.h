#ifndef COORDINATE_H
#define COORDIATE_H
using namespace std;

class Coordinate {
        public:
                Coordinate();
                Coordinate(int x, int y);
                int x = 0;
                int y = 0;
                operator==(const Coordinates& other);
};

#endif
