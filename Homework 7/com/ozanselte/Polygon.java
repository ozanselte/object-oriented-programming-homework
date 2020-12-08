package com.ozanselte;

import java.awt.*;

/**
 * Polygon abstract class
 */
public abstract class Polygon implements Shape {

    protected double perimeterVal, areaVal;

    public double area() {
        return areaVal;
    }

    public double perimeter() {
        return perimeterVal;
    }

    /**
     * Last X point getter
     * @return highest X
     */
    public abstract double getMaxX();

    /**
     * Last Y point getter
     * @return highest Y
     */
    public abstract double getMaxY();

    public abstract void increment();
    public abstract void decrement();
    public abstract void draw(Graphics graphics);

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
