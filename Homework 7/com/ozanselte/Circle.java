package com.ozanselte;

import java.awt.*;

/**
 * Circular shape class
 */
public class Circle implements Shape {

    private double radius;
    private double x, y;

    /**
     * Default constructor. radius = 0
     */
    public Circle() {
        this(0, 0, 0);
    }

    /**
     * Constructor with radius
     * @param radius circle radius
     */
    public Circle(double radius) {
        this(radius, radius, radius);
    }

    /**
     * Full constructor
     * @param radius circle radius
     * @param x center-X
     * @param y center -Y
     */
    public Circle(double radius, double x, double y) {
        this.setRadius(radius);
        this.setLocation(x, y);
    }

    /**
     * Radius setter
     * @param radius circle radius
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setRadius(double radius) throws UnsupportedOperationException {
        if (0 > radius) throw new UnsupportedOperationException("Unsupported operation!");
        this.radius = radius;
    }

    /**
     * Location setter
     * @param x center-X
     * @param y center-Y
     */
    public void setLocation(double x, double y) {
        this.setX(x);
        this.setY(y);
    }

    /**
     * Center-X setter
     * @param x center-X
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setX(double x) throws UnsupportedOperationException {
        if (this.getRadius() > x) throw new UnsupportedOperationException("Unsupported operation!");
        this.x = x;
    }

    /**
     * Center-Y setter
     * @param y center-Y
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setY(double y) throws UnsupportedOperationException {
        if (this.getRadius() > y) throw new UnsupportedOperationException("Unsupported operation!");
        this.y = y;
    }

    /**
     * Radius getter
     * @return circle radius
     */
    public double getRadius() {
        return this.radius;
    }

    /**
     * Center-X getter
     * @return center-X
     */
    public double getX() {
        return this.x;
    }

    /**
     * Center-Y getter
     * @return center-Y
     */
    public double getY() {
        return this.y;
    }

    public double area() {
        return Math.PI * Math.pow(this.getRadius(), 2);
    }

    public double perimeter() {
        return 2 * Math.PI * this.getRadius();
    }

    public void increment() {
        this.setLocation(this.getX() + 1, this.getY() + 1);
    }

    public void decrement() {
        this.setLocation(this.getX() - 1, this.getY() - 1);
    }

    public void draw(Graphics graphics) {
        int x = (int)(this.getX() - this.getRadius());
        int y = (int)(this.getY() - this.getRadius());
        graphics.drawOval(x, y,
                (int)this.getRadius() * 2, (int)this.getRadius() * 2);
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
