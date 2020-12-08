#include "funcs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/*
 * Swap integers
 */
void replace(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/*
 * Writes first line of SVG file
 */
void beginSvgFile(ofstream &resultStream, int width, int height)
{
    resultStream << "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\""
                 << " width=\"" << width << "\""
                 << " height=\"" << height << "\""
                 << " >" << endl;
}

/*
 * Writes last line of SVG file
 */
void finishSvgFile(ofstream &resultStream)
{
    resultStream << "</svg>" << endl;
}

/*
 * Assigns TRUE to all elements of given matrix
 */
void setMatrixTrue(ContainerMatrix &matrix, int width, int height)
{
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            matrix[i][j] = true;
        }
    }
}

/*
 * Sets free the matrix and small arrays
 */
void freeMatrix(ContainerMatrix &matrix, int width)
{
    for(int i = 0; i < width; i++){
        free(matrix[i]);
    }
    free(matrix);
}

/*
 * Gets container shape from user and prepares bigger matrix
 */
double getContainer(ofstream &resultStream, ContainerMatrix &matrix, int &containerW, int &containerH)
{
    string shapeString;
    double emptyArea;

    cout << "Please enter the main container shape (R, C, T)" << endl;
    cin >> shapeString;
    Shape containerShape = string2Shape(shapeString.at(0));
    switch(containerShape){
        case Shape::Rectangle:
            getRectangleSize(containerW, containerH);
            beginSvgFile(resultStream, containerW, containerH);
            emptyArea = drawRectangle(resultStream, containerW, containerH, 0, 0, "red");
            matrix = (bool **)calloc(containerW, sizeof(bool *));
            for(int i = 0; i < containerW; i++){
                matrix[i] = (bool *)calloc(containerH, sizeof(bool));
            }
            setMatrixTrue(matrix, containerW, containerH);
            break;
        case Shape::Circle:
            int radius;
            getCircleleSize(radius);
            containerW = radius * 2;
            containerH = radius * 2;
            beginSvgFile(resultStream, containerW, containerH);
            emptyArea = drawCircle(resultStream, radius, radius, radius, "red");
            matrix = (bool **)calloc(containerW, sizeof(bool *));
            for(int i = 0; i < containerW; i++){
                matrix[i] = (bool *)calloc(containerH, sizeof(bool));
                for(int j = 0; j < containerH; j++){
                    if((i-radius)*(i-radius) + (j-radius)*(j-radius) <= radius*radius){
                        matrix[i][j] = true;
                    }
                    else{
                        matrix[i][j] = false;
                    }
                }
            }
            break;
        case Shape::Triangle:
            int sideLength;
            getTriangleSize(sideLength);
            containerH = sideLength * (sqrt(3) / 2.0);
            containerW = sideLength;
            beginSvgFile(resultStream, containerW, containerH);
            emptyArea = drawTriangle(resultStream, sideLength, Direction::Up, sideLength / 2, 0, "red");
            matrix = (bool **)calloc(containerW, sizeof(bool *));
            for(int i = 0; i < containerW; i++){
                matrix[i] = (bool *)calloc(containerH, sizeof(bool));
                for(int j = 0; j < containerH; j++){
                    if((j > floor(tan(60 * M_PI / 180.0) * i - containerH))
                       && (j > floor(tan(120 * M_PI / 180.0) * (i - containerW) - containerH))){
                        matrix[i][j] = true;
                    }
                    else{
                        matrix[i][j] = false;
                    }
                }
            }
            break;
    }
    return emptyArea;
}

/*
 * Converts character to Shape Enum Class
 */
Shape string2Shape(char shapeLetter)
{
    switch(shapeLetter) {
        case 'R':
            return Shape::Rectangle;
        case 'C':
            return Shape::Circle;
        case 'T':
            return Shape::Triangle;
        default:
            cerr << "Undefined shape!" << endl;
            exit(0);
    }
}

/*
 * Gets rectangle size from user
 */
void getRectangleSize(int &width, int &height)
{
    cout << "Please enter the width" << endl;
    cin >> width;
    cout << "Please enter the height" << endl;
    cin >> height;
}

/*
 * Gets circle size from user
 */
void getCircleleSize(int &radius)
{
    cout << "Please enter the radius" << endl;
    cin >> radius;
}

/*
 * Gets triangle size from user
 */
void getTriangleSize(int &sideLength)
{
    cout << "Please enter the side length" << endl;
    cin >> sideLength;
}

/*
 * Draws rectangle to SVG file
 */
double drawRectangle(ofstream &resultStream, int width, int height, int x, int y, string color)
{
    resultStream << "<rect width=\"" << width
                 << "\" height=\"" << height
                 << "\" x=\"" << x
                 << "\" y=\"" << y
                 << "\" fill=\"" << color
                 << "\" stroke=\"blue\" />" << endl;
    return width * height;
}

/*
 * Draws circle to SVG file
 */
double drawCircle(ofstream &resultStream, int radius, int centerX, int centerY, string color)
{
    resultStream << "<circle cx=\"" << centerX
                 << "\" cy=\"" << centerY
                 << "\" r=\"" << radius
                 << "\" fill=\"" << color
                 << "\" stroke=\"blue\" />" << endl;
    return M_PI * static_cast<double>(radius * radius);
}

/*
 * Draws triangle to SVG file
 */
double drawTriangle(ofstream &resultStream, int sideLength, Direction direction, int topX, int topY, string color)
{
    int baseA[2], baseB[2];
    int height = sideLength * (sqrt(3) / 2);
    int top[2] = {topX, topY};
    switch(direction) {
        case Direction::Up:
            baseA[0] = topX - (sideLength / 2);
            baseA[1] = topY + height;
            baseB[0] = topX + (sideLength / 2);
            baseB[1] = topY + height;
            break;
        case Direction::Down:
            baseA[0] = topX - (sideLength / 2);
            baseA[1] = topY - height;
            baseB[0] = topX + (sideLength / 2);
            baseB[1] = topY - height;
            break;
        case Direction::Left:
            baseA[0] = topX - height;
            baseA[1] = topY - (sideLength / 2);
            baseB[0] = topX + height;
            baseB[1] = topY - (sideLength / 2);
            break;
        case Direction::Right:
            baseA[0] = topX + height;
            baseA[1] = topY - (sideLength / 2);
            baseB[0] = topX + height;
            baseB[1] = topY + (sideLength / 2);
            break;
    }
    resultStream << "<polygon points=\"" << baseA[0] << "," << baseA[1] << " "
                 << baseB[0] << "," << baseB[1] << " "
                 << top[0] << "," << top[1]
                 << "\" fill=\"" << color
                 << "\" stroke=\"blue\" />" << endl;
    return (static_cast<double>(sideLength * sideLength) * (sqrt(3.0) / 2.0)) / 2.0;
}

/*
 * Compares big and small matrix' and returns their compatibility to each other
 */
bool isMatrixBeautiful(ContainerMatrix &org, ContainerMatrix &test, int iX, int iY, int w, int h)
{
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            if(true == test[i][j]){
                if(false == org[i+iX][j+iY]){
                    return false;
                }
            }
        }
    }
    return true;
}

/*
 * Assigns small matrix to the right place in the bigger matrix
 */
void assignMatrix(ContainerMatrix &org, ContainerMatrix &test, int iX, int iY, int w, int h) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (test[i][j])
                org[i + iX][j + iY] = false;
        }
    }
}