//
// Created by ozanselte on 12/20/18.
//

#ifndef HW5_POINT2D_H
#define HW5_POINT2D_H


class Point2D {
public:
    Point2D();
    Point2D(double _x, double _y);
    Point2D& operator =(const Point2D& obj);
    ~Point2D();
    void setX(double _x);
    void setY(double _y);
    inline double getX() const { return x; };
    inline double getY() const { return y; };

private:
    double x, y;
};


#endif //HW5_POINT2D_H
