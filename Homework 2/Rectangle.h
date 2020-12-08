//
// Created by ozanselte on 10/26/18.
//

#ifndef HW2_RECTANGLE_H
#define HW2_RECTANGLE_H

#include <fstream>
#include <string>

using namespace std;

class Rectangle {
public:
    Rectangle(void);
    Rectangle(int w, int h, int _x, int _y);
    void setSize(int w, int h);
    void setWidth(int w);
    void setHeight(int h);
    void setLocation(int _x, int _y);
    void setX(int _x);
    void setY(int _y);
    int getWidth(void) const;
    int getHeight(void) const;
    int getX(void) const;
    int getY(void) const;
    void draw(ofstream& stream, string color, string stroke) const;
private:
    int width, height;
    int x, y;
};

#endif //HW2_RECTANGLE_H