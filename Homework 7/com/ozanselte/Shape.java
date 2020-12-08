package com.ozanselte;

import java.awt.*;

/**
 * Shape interface for HW8
 */
public interface Shape extends Comparable<Shape> {
    /**
     * Area getter
     * @return area
     */
    public double area();

    /**
     * Perimeter getter
     * @return perimeter
     */
    public double perimeter();

    /**
     * Position X and Y incrementer
     */
    public void increment();

    /**
     * Position X and Y decrementer
     */
    public void decrement();

    /**
     * JPanel drawer
     * @param graphics paintComponent Graphics
     */
    public void draw(Graphics graphics);
}
