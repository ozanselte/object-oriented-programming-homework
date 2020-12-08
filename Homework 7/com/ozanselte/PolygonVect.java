package com.ozanselte;

import java.awt.*;
import java.awt.geom.Point2D;
import java.util.ArrayList;

/**
 * Polygon class which using ArrayList
 */
public class PolygonVect extends Polygon {

    private ArrayList<Point2D.Double> points = new ArrayList<>();

    /**
     * Polygon constructor
     * @param shape object which be converted to Polygon
     * @throws UnsupportedOperationException in case of UnsupportedOperation
     */
    public PolygonVect(Shape shape) throws UnsupportedOperationException {
        areaVal = shape.area();
        perimeterVal = shape.perimeter();
        switch (shape.getClass().getSimpleName()) {
            case "Rectangle":
                Rectangle r = (Rectangle)shape;
                points.add(new Point2D.Double(r.getX(), r.getY()));
                points.add(new Point2D.Double(r.getX(), r.getY() + r.getWidth()));
                points.add(new Point2D.Double(r.getX() + r.getHeight(), r.getY() + r.getWidth()));
                points.add(new Point2D.Double(r.getX() + r.getHeight(), r.getY()));
                break;
            case "Circle":
                Circle c = (Circle)shape;
                for (int i = 0; i < 100; ++i) {
                    points.add(new Point2D.Double(Math.cos(2*i*Math.PI / 100) * c.getRadius() + c.getX(),
                            Math.sin(2*i*Math.PI / 100) * c.getRadius() + c.getY()));
                }
                break;
            case "Triangle":
                Triangle t = (Triangle)shape;
                for (int i = 0; i < 3; ++i) {
                    points.add(new Point2D.Double(t.getX(i), t.getY(i)));
                }
                break;
            default:
                throw new UnsupportedOperationException("Unsupported operation!");
        }
    }

    public double getMaxX() {
        double val = points.get(0).getX();
        for (int i = 1; i < points.size(); i++) {
            if (points.get(i).getX() > val) {
                val = points.get(i).getX();
            }
        }
        return val;
    }

    public double getMaxY() {
        double val = points.get(0).getY();
        for (int i = 1; i < points.size(); i++) {
            if (points.get(i).getY() > val) {
                val = points.get(i).getY();
            }
        }
        return val;
    }

    public void increment() {
        ArrayList<Point2D.Double> futurePoints = new ArrayList<>();
        for (int i = 0; i < points.size(); i++) {
            Point2D.Double point = points.get(i);
            double x = point.getX();
            double y = point.getY();
            point.setLocation(x + 1, y + 1);
            futurePoints.add(point);
        }
        points = futurePoints;
    }

    public void decrement() throws UnsupportedOperationException {
        ArrayList<Point2D.Double> futurePoints = new ArrayList<>();
        for (int i = 0; i < points.size(); i++) {
            Point2D.Double point = points.get(i);
            double x = point.getX();
            double y = point.getY();
            if (1 > x) throw new UnsupportedOperationException("Unsupported operation!");
            if (1 > y) throw new UnsupportedOperationException("Unsupported operation!");
            point.setLocation(x - 1, y - 1);
            futurePoints.add(point);
        }
        points = futurePoints;
    }

    public void draw(Graphics graphics) {
        int x[] = new int[points.size()];
        int y[] = new int[points.size()];
        for (int i = 0; i < points.size(); i++) {
            Point2D.Double point = points.get(i);
            x[i] = (int)point.getX();
            y[i] = (int)point.getY();
        }
        graphics.drawPolygon(x, y, points.size());
    }
}
