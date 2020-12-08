#ifndef HW1_FUNCS_H
#define HW1_FUNCS_H

#include <fstream>
#include <string>

using namespace std;

enum class Shape
{
    Rectangle,
    Circle,
    Triangle
};

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

typedef bool** ContainerMatrix;

void replace(int &a, int &b);
void beginSvgFile(ofstream &resultStream, int width, int height);
void finishSvgFile(ofstream &resultStream);
void setMatrixTrue(ContainerMatrix &matrix, int width, int height);
void freeMatrix(ContainerMatrix &matrix, int width);
double getContainer(ofstream &resultStream, ContainerMatrix &matrix, int &containerW, int &containerH);
Shape string2Shape(char shapeLetter);
void getRectangleSize(int &width, int &height);
void getCircleleSize(int &radius);
void getTriangleSize(int &sideLength);
double drawRectangle(ofstream &resultStream, int width, int height, int x, int y, string color);
double drawCircle(ofstream &resultStream, int radius, int centerX, int centerY, string color);
double drawTriangle(ofstream &resultStream, int sideLength, Direction direction, int topX, int topY, string color);
bool isMatrixBeautiful(ContainerMatrix &org, ContainerMatrix &test, int iX, int iY, int w, int h);
void assignMatrix(ContainerMatrix &org, ContainerMatrix &test, int iX, int iY, int w, int h);

#endif //HW1_FUNCS_H
