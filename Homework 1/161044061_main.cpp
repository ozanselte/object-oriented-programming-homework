#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "funcs.h"

using namespace std;

int main() {
    ofstream resultStream;
    double emptyArea;
    int containerW, containerH;
    int times;
    int width, height;
    ContainerMatrix matrix, newMatrix;
    string shapeString;

    resultStream.open("output.svg");
    emptyArea = getContainer(resultStream, matrix, containerW, containerH);

    /*
     * Getting small shape
     */
    cout << "Please enter the small shape (R, C, T)" << endl;
    cin >> shapeString;
    Shape smallShape = string2Shape(shapeString.at(0));
    switch(smallShape){
        case Shape::Rectangle:
            getRectangleSize(width, height);
            /*
             * I'm trying up2down and left2right so bigger width is more efficient.
             */
            if(height > width){
                replace(width, height);
            }
            newMatrix = (bool **)calloc(width, sizeof(bool *));
            for(int i = 0; i < width; i++){
                newMatrix[i] = (bool *)calloc(height, sizeof(bool));
            }
            setMatrixTrue(newMatrix, width, height);
            for(int i = 0; i < containerW-width+1; i++){
                for(int j = 0; j < containerH-height+1; j++){
                    bool isGood = isMatrixBeautiful(matrix, newMatrix, i, j, width, height);
                    if(isGood){
                        int area = drawRectangle(resultStream, width, height, i, j, "green");
                        emptyArea -= area;
                        times++;
                        assignMatrix(matrix, newMatrix, i, j, width, height);
                        j += (height - 1);
                    }
                }
            }
            freeMatrix(newMatrix, width);
            /*
             * Then, for empty areas, trying rotated
             */
            replace(width, height);
            newMatrix = (bool **)calloc(width, sizeof(bool *));
            for(int i = 0; i < width; i++){
                newMatrix[i] = (bool *)calloc(height, sizeof(bool));
            }
            setMatrixTrue(newMatrix, width, height);
            for(int i = 0; i < containerW-width+1; i++){
                for(int j = 0; j < containerH-height+1; j++){
                    bool isGood = isMatrixBeautiful(matrix, newMatrix, i, j, width, height);
                    if(isGood){
                        int area = drawRectangle(resultStream, width, height, i, j, "green");
                        emptyArea -= area;
                        times++;
                        assignMatrix(matrix, newMatrix, i, j, width, height);
                        j += (height - 1);
                    }
                }
            }
            freeMatrix(newMatrix, width);
            break;
        case Shape::Circle:
            int radius;
            getCircleleSize(radius);
            width = radius * 2;
            height = radius * 2;
            newMatrix = (bool **)calloc(width, sizeof(bool *));
            for(int i = 0; i < width; i++){
                newMatrix[i] = (bool *)calloc(height, sizeof(bool));
                for(int j = 0; j < height; j++){
                    if((i-radius)*(i-radius) + (j-radius)*(j-radius) <= radius*radius){
                        newMatrix[i][j] = true;
                    }
                    else{
                        newMatrix[i][j] = false;
                    }
                }
            }
            for(int i = radius; i < containerW-radius+1; i++){
                for(int j = radius; j < containerH-radius+1; j++){
                    bool isGood = isMatrixBeautiful(matrix, newMatrix, i-radius, j-radius, width, height);
                    if(isGood){
                        int area = drawCircle(resultStream, radius, i, j, "green");
                        emptyArea -= area;
                        times++;
                        assignMatrix(matrix, newMatrix, i-radius, j-radius, width, height);
                        j += (radius-1);
                    }
                }
            }
            freeMatrix(newMatrix, width);
            break;
        case Shape::Triangle:
            int sideLength;
            getTriangleSize(sideLength);
            height = sideLength * (sqrt(3) / 2);
            width = sideLength;
            newMatrix = (bool **)calloc(width, sizeof(bool *));
            for(int i = 0; i < width; i++){
                newMatrix[i] = (bool *)calloc(height, sizeof(bool));
                for(int j = 0; j < height; j++){
                    if((j+3 > ceil(tan(60 * M_PI / 180.0) * i - height))
                       && (j+3 > ceil(tan(120 * M_PI / 180.0) * (i - width) - height))){
                        newMatrix[i][j] = true;
                    }
                    else{
                        newMatrix[i][j] = false;
                    }
                }
            }
            for(int i = width/2; i < containerW-width/2+1; i++){
                for(int j = 0; j < containerH-height+1; j++){
                    bool isGood = isMatrixBeautiful(matrix, newMatrix, i-width/2, j, width, height);
                    if(isGood){
                        int area = drawTriangle(resultStream, sideLength, Direction::Up, i, j, "green");
                        emptyArea -= area;
                        times++;
                        assignMatrix(matrix, newMatrix, i-width/2, j, width, height);
                    }
                }
            }
            freeMatrix(newMatrix, width);
            /*
             * Then, for empty areas, trying rotated triangles
             */
            newMatrix = (bool **)calloc(width, sizeof(bool *));
            for(int i = 0; i < width; i++){
                newMatrix[i] = (bool *)calloc(height, sizeof(bool));
                for(int j = 0; j < height; j++){
                    if((j+3 >= ceil(tan(60 * M_PI / 180.0) * (i - width)))
                       && (j+3 >= ceil(tan(120 * M_PI / 180.0) * i))){
                        newMatrix[i][j] = true;
                    }
                    else{
                        newMatrix[i][j] = false;
                    }
                }
            }
            for(int i = width/2; i < containerW-width/2+1; i++){
                for(int j = height; j < containerH+1; j++){
                    bool isGood = isMatrixBeautiful(matrix, newMatrix, i-width/2, j-height, width, height);
                    if(isGood){
                        int area = drawTriangle(resultStream, sideLength, Direction::Down, i, j, "green");
                        emptyArea -= area;
                        times++;
                        assignMatrix(matrix, newMatrix, i-width/2, j-height, width, height);
                    }
                }
            }
            freeMatrix(newMatrix, width);
            break;
    }
    finishSvgFile(resultStream);
    cout << "I can fit at most " << times
    << " small shapes into the main container. The empty area (red) in container is "
    << emptyArea << "." << endl;
    freeMatrix(matrix, containerW);
    return 0;
}