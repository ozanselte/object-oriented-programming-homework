//
// Created by ozanselte on 10/26/18.
//

#ifndef HW2_TRIANGLE_H
#define HW2_TRIANGLE_H

#include <fstream>
#include <string>

using namespace std;

class Triangle {
public:
    Triangle(void);
    Triangle(int sideLength);
    Triangle(int sideLength, int topX, int topY);
    Triangle(int sideLength, int topX, int topY, bool isUpsideDown);
    int getX(int point) const;
    int getY(int point) const;
    void draw(ofstream& stream, string color, string stroke) const;
    void setTriangle(int sideLength, int topX, int topY, bool isUpsideDown);
private:
    int xa, ya, xb, yb, xc, yc;
};


#endif //HW2_TRIANGLE_H
