//
// Created by ozanselte on 10/26/18.
//

#ifndef HW2_CIRCLE_H
#define HW2_CIRCLE_H

#include <fstream>
#include <string>

using namespace std;

class Circle {
public:
    Circle();
    Circle(int r, int _x, int _y);
    void setRadius(int r);
    void setLocation(int _x, int _y);
    void setX(int _x);
    void setY(int _y);
    int getRadius(void) const;
    int getX(void) const;
    int getY(void) const;
    void draw(ofstream& stream, string color, string stroke) const;
private:
    int radius;
    int x, y;
};


#endif //HW2_CIRCLE_H
