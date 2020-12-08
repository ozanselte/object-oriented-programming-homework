package com.ozanselte;

import javax.swing.*;
import java.awt.*;
import java.util.Arrays;

/**
 * Static functions' class.
 */
public class Selte extends JPanel {

    private Shape[] shapes;

    /**
     * Constructor for JPanel extends
     * @param shapes Shapes array
     */
    Selte(Shape[] shapes) {
        this.shapes = shapes;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < this.shapes.length; i++) {
            this.shapes[i].draw(g);
        }
    }

    /**
     * Creates a JFrame and draws inside the shapes.
     * @param shapes Shape array
     */
    public static void drawAll(Shape[] shapes, String title) {
        int maxX = (int)getMaxX(shapes);
        int maxY = (int)getMaxY(shapes);
        JFrame frame = new JFrame();
        frame.pack();
        Insets insets = frame.getInsets();
        frame = new JFrame();
        frame.setTitle(title);
        frame.setSize(maxX + insets.left + insets.right, maxY + insets.top + insets.bottom);
        frame.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        Selte panel = new Selte(shapes);
        frame.add(panel);
        frame.setVisible(true);
        frame.setResizable(false);
    }

    /**
     * Converts Shapes to Polygon Shapes
     * @param shapes Shapes array
     * @return Polygon Shapes array
     */
    public static Shape[] convertAll(Shape[] shapes) {
        Polygon[] polygons = new PolygonDyn[shapes.length];
        for (int i = 0; i < shapes.length; i++) {
            if (shapes[i].getClass().getSimpleName().equals("PolygonVect")
             || shapes[i].getClass().getSimpleName().equals("PolygonDyn")) {
                polygons[i] = (Polygon)shapes[i];
            }
            else {
                polygons[i] = new PolygonDyn(shapes[i]);
            }
        }
        return polygons;
    }

    /**
     * Shape array sorter
     * @param shapes Shape array
     */
    public static void sortShapes(Shape[] shapes) {
        Arrays.sort(shapes);
    }

    private static double getMaxX(Shape[] shapes) {
        Polygon[] polygon = (PolygonDyn[]) convertAll(shapes);
        double maxX = polygon[0].getMaxX();
        for (int i = 1; i < polygon.length; i++) {
            if (polygon[i].getMaxX() > maxX) {
                maxX = polygon[i].getMaxX();
            }
        }
        return maxX;
    }

    private static double getMaxY(Shape[] shapes) {
        Polygon[] polygon = (PolygonDyn[]) convertAll(shapes);
        double maxY = polygon[0].getMaxY();
        for (int i = 1; i < polygon.length; i++) {
            if (polygon[i].getMaxY() > maxY) {
                maxY = polygon[i].getMaxY();
            }
        }
        return maxY;
    }
}
