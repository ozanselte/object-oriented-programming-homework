package com.ozanselte;

import java.awt.*;

/**
 * Rectangular shape class
 */
public class Rectangle implements Shape {

    private double width, height;
    private double x, y;

    /**
     * Default constructor. width = 0, height = 0
     */
    public Rectangle() {
        this(0);
    }

    /**
     * Constructor with a side for Square
     * @param side square side
     */
    public Rectangle(double side) {
        this(side, side);
    }

    /**
     * Constructor with sizes
     * @param width rectangle width
     * @param height rectangle height
     */
    public Rectangle(double width, double height) {
        this(width, height, 0, 0);
    }

    /**
     * Full constructor
     * @param width rectangle width
     * @param height rectangle height
     * @param x left corner X
     * @param y left corner Y
     */
    public Rectangle(double width, double height, double x, double y) {
        this.setSize(width, height);
        this.setLocation(x, y);
    }

    /**
     * Size setter
     * @param width rectangle width
     * @param height rectangle height
     */
    public void setSize(double width, double height) {
        this.setWidth(width);
        this.setHeight(height);
    }

    /**
     * Width setter
     * @param width rectangle width
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setWidth(double width) throws UnsupportedOperationException {
        if (0 > width) throw new UnsupportedOperationException("Unsupported operation!");
        this.width = width;
    }

    /**
     * Height setter
     * @param height rectangle height
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setHeight(double height) throws UnsupportedOperationException {
        if (0 > height) throw new UnsupportedOperationException("Unsupported operation!");
        this.height = height;
    }

    /**
     * Location setter
     * @param x left corner X
     * @param y left corner X
     */
    public void setLocation(double x, double y) {
        this.setX(x);
        this.setY(y);
    }

    /**
     * Left corner X setter
     * @param x left corner X
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setX(double x) throws UnsupportedOperationException {
        if (0 > x) throw new UnsupportedOperationException("Unsupported operation!");
        this.x = x;
    }

    /**
     * Left corner Y setter
     * @param y left corner Y
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public void setY(double y) throws UnsupportedOperationException {
        if (0 > y) throw new UnsupportedOperationException("Unsupported operation!");
        this.y = y;
    }

    /**
     * Width getter
     * @return width
     */
    public double getWidth() {
        return this.width;
    }

    /**
     * Height getter
     * @return height
     */
    public double getHeight() {
        return this.height;
    }

    /**
     * Left corner X getter
     * @return eft corner X
     */
    public double getX() {
        return this.x;
    }

    /**
     * Left corner Y getter
     * @return eft corner Y
     */
    public double getY() {
        return this.y;
    }

    public double area() {
        return this.getWidth() * this.getHeight();
    }

    public double perimeter() {
        return 2 * (this.getWidth() + this.getHeight());
    }

    public void increment() {
        this.setLocation(this.getX() + 1, this.getY() + 1);
    }

    public void decrement() {
        this.setLocation(this.getX() - 1, this.getY() - 1);
    }

    public void draw(Graphics graphics) {
        graphics.drawRect((int)this.getX(), (int)this.getY(),
                (int)this.getWidth(), (int)this.getHeight());
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
