//
// Created by ozanselte on 10/26/18.
//

#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H

#include <fstream>
#include <string>

using namespace std;

class Triangle {
public:
    Triangle(void);
    Triangle(double sideLength);
    Triangle(double sideLength, double topX, double topY);
    Triangle(double sideLength, double topX, double topY, bool isUpsideDown);
    double getX(int point) const;
    double getY(int point) const;
    double getPerimeter(void) const;
    double getArea(void) const;
    void draw(ostream& stream, string color, string stroke) const;
    void setTriangle(double sideLength, double topX, double topY, bool isUpsideDown);

    Triangle& operator ++();
    const Triangle operator ++(int);
    Triangle& operator --();
    const Triangle operator --(int);
    const Triangle operator +(double d) const;
    const Triangle operator -(double d) const;

    static double getTotalPerimeter(void);
    static double getTotalArea(void);

private:
    double xa = 0.0, ya = 0.0;
    double xb = 0.0, yb = 0.0;
    double xc = 0.0, yc = 0.0;
    static double totalPerimeter;
    static double totalArea;
};

ostream& operator <<(ostream& stream, const Triangle& obj);

#endif //HW3_TRIANGLE_H
