package com.ozanselte;

import java.awt.*;

/**
 * Triangular shape class
 */
public class Triangle implements Shape {

    Double[] x, y;

    /**
     * Default constructor. sideLength = 0
     */
    public Triangle() {
        this(0);
    }

    /**
     * Constructor with a side length
     * @param sideLength
     */
    public Triangle(double sideLength) {
        this(sideLength, sideLength / 2, 0);
    }

    /**
     * Constructor with a side length and a top point
     * @param sideLength side length
     * @param topX top points X
     * @param topY top points Y
     */
    public Triangle(double sideLength, double topX, double topY) {
        this(sideLength, topX, topY, false);
    }

    /**
     * Constructor with a side length, a top point and rotation
     * @param sideLength side length
     * @param topX top points X
     * @param topY top points Y
     * @param isUpsideDown rotation. True if up side down.
     */
    public Triangle(double sideLength, double topX, double topY, boolean isUpsideDown) {
        this.x = new Double[3];
        this.y = new Double[3];
        double height = sideLength * Math.sqrt(3) / 2;
        setPoint(0, topX, topY);
        if (isUpsideDown) {
            setPoint(1, topX - sideLength / 2, topY - height);
            setPoint(2, topX + sideLength / 2, topY - height);
        }
        else {
            setPoint(1, topX - sideLength / 2, topY + height);
            setPoint(2, topX + sideLength / 2, topY + height);
        }
    }

    /**
     * Point position setter
     * @param index point index
     * @param x x coordinate
     * @param y y coordinate
     */
    public void setPoint(int index, double x, double y) {
        this.setX(index, x);
        this.setY(index, y);
    }

    /**
     * Point X setter
     * @param index point index
     * @param x x coordinate
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setX(int index, double x) throws UnsupportedOperationException {
        if (3 <= index) {
            throw new UnsupportedOperationException("Unsupported operation!");
        }
        if (0 > x) {
            throw new UnsupportedOperationException("Unsupported operation!");
        }
        this.x[index] = x;
    }

    /**
     * Point Y setter
     * @param index point index
     * @param y y coordinate
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setY(int index, double y) throws UnsupportedOperationException {
        if (3 <= index) {
            throw new UnsupportedOperationException("Unsupported operation!");
        }
        if (0 > y) {
            throw new UnsupportedOperationException("Unsupported operation!" + y);
        }
        this.y[index] = y;
    }

    /**
     * Points X getter
     * @param index point index
     * @return x coordinate
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public double getX(int index) throws UnsupportedOperationException {
        if (3 <= index) {
            throw new UnsupportedOperationException("Unsupported operation!");
        }
        return this.x[index];
    }

    /**
     * Points Y getter
     * @param index point index
     * @return y coordinate
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public double getY(int index) throws UnsupportedOperationException {
        if (3 <= index) {
            throw new UnsupportedOperationException("Unsupported operation!");
        }
        return this.y[index];
    }

    /**
     * Triangles center coordinates X getter
     * @return centers X
     */
    public double getCenterX() {
        return (getX(0) + getX(1) + getX(2)) / 3.0;
    }

    /**
     * Triangles center coordinates Y getter
     * @return centers Y
     */
    public double getCenterY() {
        return (getY(0) + getY(1) + getY(2)) / 3.0;
    }

    public double area() {
        double sideLength = Math.abs(this.getX(1) - this.getX(2));
        return Math.pow(sideLength, 2) * Math.sqrt(3) / 4;
    }

    public double perimeter() {
        double sideLength = Math.abs(this.getX(1) - this.getX(2));
        return Math.pow(sideLength, 2) * 3;
    }

    public void increment() {
        for (int i = 0; i < 3; i++) {
            this.setPoint(i, this.getX(i) + 1, this.getY(i) + 1);
        }
    }

    public void decrement() {
        for (int i = 0; i < 3; i++) {
            this.setPoint(i, this.getX(i) - 1, this.getY(i) - 1);
        }
    }

    public void draw(Graphics graphics) {
        int x[] = {this.x[0].intValue(), this.x[1].intValue(), this.x[2].intValue()};
        int y[] = {this.y[0].intValue(), this.y[1].intValue(), this.y[2].intValue()};
        graphics.drawPolygon(x, y, 3);
    }

    /**
     * Comparator for Comparable
     * @param shape right object
     * @return comparement
     */
    public int compareTo(Shape shape) {
        if (this.area() == shape.area()) return 0;
        else if (this.area() > shape.area()) return 1;
        else return -1;
    }
}
