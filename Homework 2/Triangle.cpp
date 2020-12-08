//
// Created by ozanselte on 10/26/18.
//

#include "Triangle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

Triangle::Triangle(void)
{
    setTriangle(0, 0, 0, false);
}

Triangle::Triangle(int sideLength)
{
    setTriangle(sideLength, sideLength / 2.0, 0, false);
}

Triangle::Triangle(int sideLength, int topX, int topY)
{
    setTriangle(sideLength, topX, topY, false);
}

Triangle::Triangle(int sideLength, int topX, int topY, bool isUpsideDown)
{
    setTriangle(sideLength, topX, topY, isUpsideDown);
}

int Triangle::getX(int point) const
{
    switch (point){
        case 0:
            return xa;
        case 1:
            return xb;
        case 2:
            return xc;
        default:
            cerr << "Triangle point must between zero and two." << endl;
            exit(EXIT_FAILURE);
    }
}

int Triangle::getY(int point) const
{
    switch (point){
        case 0:
            return ya;
        case 1:
            return yb;
        case 2:
            return yc;
        default:
            cerr << "Triangle point must between zero and two." << endl;
            exit(EXIT_FAILURE);
    }
}

void Triangle::draw(ofstream& stream, string color, string stroke) const
{
    stream <<
    "<polygon points=\"" <<
    xa << "," << ya << " " <<
    xb << "," << yb << " " <<
    xc << "," << yc << "\" " <<
    "fill=\"" << color << "\" " <<
    "stroke=\"" << stroke << "\" />" <<
    endl;
}

void Triangle::setTriangle(int sideLength, int topX, int topY, bool isUpsideDown)
{
    if(0 > sideLength){
        cerr << "Triangle Side Length cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    if(0 > topX){
        cerr << "Triangle Top X-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    if(0 > topY){
        cerr << "Triangle Top Y-coordinate cannot be smaller than zero." << endl;
        exit(EXIT_FAILURE);
    }
    int h = sideLength * (sqrt(3) / 2.0);
    xa = topX;
    ya = topY;
    xb = topX - sideLength/2;
    yb = topY + (isUpsideDown ? -h : h);
    xc = topX + sideLength/2;
    yc = topY + (isUpsideDown ? -h : h);
}