package com.ozanselte;

import java.awt.*;
import java.awt.geom.Point2D;
import java.util.ArrayList;

/**
 * Dynamic Polygon class
 */
public class PolygonDyn extends Polygon {

    private Point2D.Double[] points;

    /**
     * Polygon constructor
     * @param shape object which be converted to Polygon
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public PolygonDyn(Shape shape) throws UnsupportedOperationException {
        areaVal = shape.area();
        perimeterVal = shape.perimeter();
        switch (shape.getClass().getSimpleName()) {
            case "Rectangle":
                points = new Point2D.Double[4];
                Rectangle r = (Rectangle)shape;
                points[0] = new Point2D.Double(r.getX(), r.getY());
                points[1] = new Point2D.Double(r.getX(), r.getY() + r.getWidth());
                points[2] = new Point2D.Double(r.getX() + r.getHeight(), r.getY() + r.getWidth());
                points[3] = new Point2D.Double(r.getX() + r.getHeight(), r.getY());
                break;
            case "Circle":
                points = new Point2D.Double[100];
                Circle c = (Circle)shape;
                for (int i = 0; i < 100; ++i) {
                    points[i] = new Point2D.Double(Math.cos(2*i*Math.PI / 100) * c.getRadius() + c.getX(),
                            Math.sin(2*i*Math.PI / 100) * c.getRadius() + c.getY());
                }
                break;
            case "Triangle":
                points = new Point2D.Double[3];
                Triangle t = (Triangle)shape;
                for (int i = 0; i < 3; ++i) {
                    points[i] = new Point2D.Double(t.getX(i), t.getY(i));
                }
                break;
            default:
                System.err.println(shape.getClass().getSimpleName());
                throw new UnsupportedOperationException("Unsupported operation!");
        }
    }

    public double getMaxX() {
        double val = points[0].getX();
        for (int i = 1; i < points.length; i++) {
            if (points[i].getX() > val) {
                val = points[i].getX();
            }
        }
        return val;
    }

    public double getMaxY() {
        double val = points[0].getY();
        for (int i = 1; i < points.length; i++) {
            if (points[i].getY() > val) {
                val = points[i].getY();
            }
        }
        return val;
    }

    public void increment() {
        for (int i = 0; i < points.length; i++) {
            Point2D.Double point = points[i];
            double x = point.getX();
            double y = point.getY();
            points[i] = new Point2D.Double(x + 1, y + 1);
        }
    }

    public void decrement() throws UnsupportedOperationException {
        for (int i = 0; i < points.length; i++) {
            Point2D.Double point = points[i];
            double x = point.getX();
            double y = point.getY();
            if (1 > x) throw new UnsupportedOperationException("Unsupported operation!");
            if (1 > y) throw new UnsupportedOperationException("Unsupported operation!");
            points[i] = new Point2D.Double(x - 1, y - 1);
        }
    }

    public void draw(Graphics graphics) {
        int x[] = new int[points.length];
        int y[] = new int[points.length];
        for (int i = 0; i < points.length; i++) {
            Point2D.Double point = points[i];
            x[i] = (int)point.getX();
            y[i] = (int)point.getY();
        }
        graphics.drawPolygon(x, y, points.length);
    }
}
