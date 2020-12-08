package com.ozanselte;

import java.awt.*;

/**
 * ComposedShape class for composed shaped
 */
public class ComposedShape implements Shape {

    private Shape[] shapes;
    private Shape container, small;
    private double width, height;

    /**
     * Constructor
     * @param container Big shape
     * @param small Small shape
     */
    public ComposedShape(Shape container, Shape small) {
        this.container = container;
        this.small = small;
        switch (this.container.getClass().getSimpleName()) {
            case "Rectangle":
                Rectangle rectangle = (Rectangle)this.container;
                this.width = rectangle.getWidth();
                this.height = rectangle.getHeight();
                break;
            case "Circle":
                Circle circle = (Circle)this.container;
                this.width = 2 * circle.getRadius();
                this.height = 2 * circle.getRadius();
                break;
            case "Triangle":
                Triangle triangle = (Triangle)this.container;
                this.width = Math.abs(triangle.getX(1) - triangle.getX(2));
                this.height = this.width * Math.sqrt(3) / 2;
                break;
        }
    }

    /**
     * Shapes array getter with container
     * @return Shape array which includes small shapes and container
     */
    public Shape[] getShapes() {
        Shape[] n = new Shape[this.shapes.length + 1];
        for (int i = 0; i < this.shapes.length; i++) {
            n[i] = shapes[i];
        }
        n[shapes.length] = this.container;
        return n.clone();
    }

    /**
     * Small shape fitter
     */
    public void optimalFit() {
        switch (this.small.getClass().getSimpleName()) {
            case "Rectangle":
                this.rectangleOptimalFit();
                break;
            case "Circle":
                this.circleOptimalFit();
                break;
            case "Triangle":
                this.triangleOptimalFit();
                break;
        }
    }

    private void rectangleOptimalFit() {
        Rectangle small = (Rectangle)this.small;
        boolean doItHorizontal = (small.getHeight() > small.getWidth());
        if(doItHorizontal){
            rectangleFit(small.getHeight(), small.getWidth());
            rectangleFit(small.getWidth(), small.getHeight());
        }
        else{
            rectangleFit(small.getWidth(), small.getHeight());
            rectangleFit(small.getHeight(), small.getWidth());
        }
    }

    private void rectangleFit(double width, double height) {
        for(int i = 0; i < this.width-width+1; i++){
            for(int j = 0; j < this.height-height+1; j++){
                Rectangle temp = new Rectangle(width, height, i, j);
                if(isRectangleFitsContainer(temp)){
                    boolean compatible = true;
                    int length = (null == this.shapes)? 0 : this.shapes.length;
                    for(int k = 0; k < length; k++){
                        if(!isRectanglesCompatible(temp, (Rectangle)this.shapes[k])){
                            compatible = false;
                        }
                    }
                    if(compatible){
                        this.addShape(temp);
                        j += (height-1);
                    }
                }
            }
        }
    }

    private void circleOptimalFit() {
        Circle small = (Circle)this.small;
        double radius = small.getRadius();
        for(int i = (int)radius; i < this.width-radius+1; i++){
            for(int j = (int)radius; j < this.height-radius+1; j++){
                Circle temp = new Circle(radius, i, j);
                if(isCircleFitsContainer(temp)){
                    boolean compatible = true;
                    int length = (null == this.shapes)? 0 : this.shapes.length;
                    for(int k = 0; k < length; k++){
                        if(!isCirclesCompatible(temp, (Circle)this.shapes[k])){
                            compatible = false;
                        }
                    }
                    if(compatible){
                        this.addShape(temp);
                        j += (radius-1);
                    }
                }
            }
        }
    }

    private void triangleOptimalFit() {
        Triangle small = (Triangle)this.small;
        double triangleH = Math.abs(small.getY(1) - small.getY(0));
        double sideLength = Math.abs(small.getX(2) - small.getX(1));
        double halfSide = sideLength / 2.0;
        for(int j = 0; j < this.height-triangleH+1; j++){
            for(int i = (int)halfSide; i < this.width-halfSide+1; i++){
                if(0>i) System.out.println(i);
                boolean fit = triangleFit(new Triangle(sideLength, i, j, false));
                if(fit){
                    i += sideLength - 1;
                }
            }
        }
        for(int j = (int)triangleH+1; j < this.width-halfSide+1; j++){
            for(int i = (int)halfSide; i < this.height-halfSide+1; i++){
                boolean fit = triangleFit(new Triangle(sideLength, i, j, true));
                if(fit){
                    i += sideLength - 1;
                }
            }
        }
    }

    private boolean triangleFit(Triangle temp) {
        if(isTriangleFitsContainer(temp)){
            boolean compatible = true;
            int length = (null == this.shapes) ? 0 : this.shapes.length;
            for(int k = 0; k < length; k++){
                if(!isTrianglesCompatible(temp, (Triangle)this.shapes[k])){
                    compatible = false;
                }
            }
            if(compatible){
                this.addShape(temp);
                return true;
            }
        }
        return false;
    }

    private boolean isRectangleFitsContainer(Rectangle rectangle) {
        double w = rectangle.getWidth() - 1;
        double h = rectangle.getHeight() - 1;
        double x = rectangle.getX();
        double y = rectangle.getY();
        if(isPointFitsContainer(x, y)
        && isPointFitsContainer(x, y + h)
        && isPointFitsContainer(x + w, y)
        && isPointFitsContainer(x + w, y + h)){
            return true;
        }
        return false;
    }

    private boolean isCircleFitsContainer(Circle circle) {
        double r = circle.getRadius();
        double x = circle.getX();
        double y = circle.getY();
        if(isPointFitsContainer(x - r, y)
                && isPointFitsContainer(x, y - r)
                && isPointFitsContainer(x + r, y)
                && isPointFitsContainer(x, y - r)){
            return true;
        }
        return false;
    }

    private boolean isTriangleFitsContainer(Triangle triangle) {
        double a[] = {triangle.getX(0), triangle.getY(0)};
        double b[] = {triangle.getX(1), triangle.getY(1)};
        double c[] = {triangle.getX(2), triangle.getY(2)};
        if(isPointFitsContainer(a[0], a[1])
        && isPointFitsContainer(b[0], b[1])
        && isPointFitsContainer(c[0], c[1])){
            return true;
        }
        return false;
    }

    private boolean isRectanglesCompatible(Rectangle a, Rectangle b) {
        double aw = a.getWidth();
        double ah = a.getHeight();
        double ax = a.getX();
        double ay = a.getY();
        for(int i = (int)ax; i < ax + aw; i++){
            for(int j = (int)ay; j < ay + ah; j++){
                if(isPointFitsRectangle(i, j, b)){
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isCirclesCompatible(Circle a, Circle b) {
        double ar = a.getRadius();
        double ax = a.getX();
        double ay = a.getY();
        for(int i = (int)(ax - ar); i < ax + ar - 1; i++){
            for(int j = (int)(ay - ar); j < ay + ar - 1; j++){
                if(isPointFitsCircle(i, j, b)){
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isTrianglesCompatible(Triangle a, Triangle b) {
        Double[] xA = {a.getX(0), a.getX(1), a.getX(2)};
        Double[] yA = {a.getY(0), a.getY(1), a.getY(2)};
        Double[] xB = {b.getX(0), b.getX(1), b.getX(2)};
        Double[] yB = {b.getY(0), b.getY(1), b.getY(2)};
        for(int i = 0; i < 3; i++){
            if(isPointFitsTriangle(xA[i], yA[i], b)){
                return false;
            }
            if(isPointFitsTriangle(xB[i], yB[i], a)){
                return false;
            }
            double xD = Math.abs(a.getCenterX() - b.getCenterX());
            double yD = Math.abs(a.getCenterY() - b.getCenterY());
            double sideLength = Math.abs(xA[2] - xA[1]);
            double height = sideLength * Math.sqrt(3) / 2;
            if((Math.pow(xD, 2) + Math.pow(yD, 2)) < Math.pow(2*height/3, 2)-sideLength*1.5){
                return false;
            }
        }
        return true;
    }

    private boolean isPointFitsContainer(double pX, double pY) {
        double x, y;
        switch (this.container.getClass().getSimpleName()) {
            case "Rectangle":
                Rectangle rectangle = (Rectangle)this.container;
                double w = rectangle.getWidth();
                double h = rectangle.getHeight();
                x = rectangle.getX();
                y = rectangle.getY();
                if((x <= pX) && (pX <= x + w)
                        && (y <= pY) && (pY <= y + h)){
                    return true;
                }
                break;
            case "Circle":
                Circle circle = (Circle)this.container;
                x = circle.getX();
                y = circle.getY();
                double r = circle.getRadius() - 0.5;
                if((pX-x)*(pX-x) + (pY-y)*(pY-y) < r*r){
                    return true;
                }
                break;
            case "Triangle":
                Triangle triangle = (Triangle)this.container;
                double a = triangle.getX(0);
                double b = triangle.getY(0);
                double border = triangle.getY(1);
                double tan60 = 1.73205080757;
                double tan120 = -1.73205080757;
                boolean isUpsideDown = (triangle.getY(1) < triangle.getY(0));
                if(isUpsideDown){
                    if((pY - b) < tan120 * (pX - a)
                            && (pY - b) < tan60 * (pX - a)){
                        if(pY > border) {
                            return true;
                        }
                    }
                }
                else{
                    if((pY - b) > tan120 * (pX - a)
                            && (pY - b) > tan60 * (pX - a)){
                        if(pY < border){
                            return true;
                        }
                    }
                }
                break;
        }
        return false;
    }

    private boolean isPointFitsRectangle(double pX, double pY, Rectangle rectangle) {
        double w = rectangle.getWidth();
        double h = rectangle.getHeight();
        double x = rectangle.getX();
        double y = rectangle.getY();
        if((x > pX) || (pX >= x + w)
                || (y > pY) || (pY >= y + h)){
            return false;
        }
        return true;
    }

    private boolean isPointFitsCircle(double pX, double pY, Circle circle) {
        double x = circle.getX();
        double y = circle.getY();
        double r = circle.getRadius() - 0.5;
        if((pX-x)*(pX-x) + (pY-y)*(pY-y) < r*r){
            return true;
        }
        return false;
    }

    private boolean isPointFitsTriangle(double pX, double pY, Triangle triangle) {
        double a = triangle.getX(0);
        double b = triangle.getY(0);
        double border = triangle.getY(1);
        double tan60 = 1.73205080757;
        double tan120 = -1.73205080757;
        boolean isUpsideDown = (triangle.getY(1) < triangle.getY(0));
        if(isUpsideDown){
            if((pY - b) < tan120 * (pX - a)
                    && (pY - b) < tan60 * (pX - a)){
                if(pY > border) {
                    return true;
                }
            }
        }
        else{
            if((pY - b) > tan120 * (pX - a)
                    && (pY - b) > tan60 * (pX - a)){
                if(pY < border){
                    return true;
                }
            }
        }
        return false;
    }

    private void addShape(Shape shape) {
        int length = (null == this.shapes)? 0 : this.shapes.length;
        Shape[] future = new Shape[length + 1];
        for (int i = 0; i < length; i++) {
            future[i] = this.shapes[i];
        }
        future[length] = shape;
        this.shapes = future;
    }

    public double area() {
        return this.container.area();
    }

    public double perimeter() {
        return this.container.perimeter();
    }

    public void increment() {
        if (null == shapes) return;
        for (int i = 0; i < this.shapes.length; i++) {
            this.shapes[i].increment();
        }
    }

    public void decrement() {
        if (null == shapes) return;
        for (int i = 0; i < this.shapes.length; i++) {
            this.shapes[i].decrement();
        }
    }

    public void draw(Graphics graphics) {
        this.container.draw(graphics);
        if (null == this.shapes) return;
        for (int i = 0; i < this.shapes.length; i++) {
            this.shapes[i].draw(graphics);
        }
    }

    /**
     * Comparator for Comparable
     * Compares according to container shape
     * @param shape right object
     * @return comparement
     */
    public int compareTo(Shape shape) {
        if (this.area() == shape.area()) return 0;
        else if (this.area() > shape.area()) return 1;
        else return -1;
    }
}
