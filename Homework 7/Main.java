import javax.swing.*;
import java.awt.GridLayout;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import com.ozanselte.Shape;
import com.ozanselte.Rectangle;
import com.ozanselte.Circle;
import com.ozanselte.Triangle;
import com.ozanselte.ComposedShape;
import com.ozanselte.Polygon;
import com.ozanselte.PolygonDyn;
import com.ozanselte.PolygonVect;
import com.ozanselte.Selte;

public class Main {

    private static Shape container, small;
    private static ComposedShape composed;
    private static char smlShp;
    private static JRadioButton conR, conC, conT;
    private static JRadioButton smlR, smlC, smlT;
    private static JFrame frame;
    private static JTextField wF, hF, rF, sF;

    public static void main(String[] args) {
        int choose;
        do {
            System.out.println("Choose one of them:");
            System.out.println("[1] - Run driver code");
            System.out.println("[2] - Run Free GUI Test(experimental)");
            String read = System.console().readLine();
            choose = Integer.parseInt(read);
        } while(1 != choose && 2 != choose);
        if (1 == choose) testDriver();
        if (2 == choose) testGUI();
    }

    private static void testDriver() {
        Rectangle r = new Rectangle(500, 500, 100, 100);
        Circle c = new Circle(250);
        Triangle t = new Triangle(500);
        Shape[] shapes = new Shape[]{r, c, t};
        Selte.drawAll(shapes, "Ozan Şelte - 161044061");
        getEnter();

        System.out.println("---Rectangle---");
        System.out.println("area: " + r.area());
        System.out.println("perimeter: " + r.perimeter());
        System.out.println("---Circle---");
        System.out.println("area: " + c.area());
        System.out.println("perimeter: " + c.perimeter());
        System.out.println("---Triangle---");
        System.out.println("area: " + t.area());
        System.out.println("perimeter: " + t.perimeter());
        getEnter();

        System.out.println("Rectangle (x, y) = (" + r.getX() + ", " + r.getY() + ")");
        r.increment();
        System.out.println("After increment (x, y) = (" + r.getX() + ", " + r.getY() + ")");
        r.decrement();
        System.out.println("After decrement (x, y) = (" + r.getX() + ", " + r.getY() + ")");
        System.out.println("Circle (x, y) = (" + c.getX() + ", " + c.getY() + ")");
        c.increment();
        System.out.println("After increment (x, y) = (" + c.getX() + ", " + c.getY() + ")");
        c.decrement();
        System.out.println("After decrement (x, y) = (" + c.getX() + ", " + c.getY() + ")");
        System.out.println("Triangle (x, y) = (" + t.getX(0) + ", " + t.getY(0) + ")");
        t.increment();
        System.out.println("After increment (x, y) = (" + t.getX(0) + ", " + t.getY(0) + ")");
        t.decrement();
        System.out.println("After decrement (x, y) = (" + t.getX(0) + ", " + t.getY(0) + ")");
        getEnter();

        System.out.println("Sorted Shapes");
        Selte.sortShapes(shapes);
        for (int i = 0; i < shapes.length; i++) {
            System.out.println(shapes[i].getClass().getSimpleName() +
                    " area=" + shapes[i].area());
        }
        getEnter();

        Shape[] polygons = Selte.convertAll(shapes);
        System.out.println("Polygon shapes after convertAll.");
        for (int i = 0; i < polygons.length; i++) {
            System.out.println("Polygon area perimeter = " + polygons[i].area() + " " + polygons[i].perimeter());
        }
        Selte.drawAll(polygons, "Polygons - convertAll");
        getEnter();

        System.out.println();
        System.out.println("->It may take a minute to calculate the optimal positions.");
        System.out.println("->It may seem wrong in window but the number and positions are right.");
        System.out.println("->After calculating double to integer convertion cause the errors.");
        getEnter();
        ComposedShape[] com = new ComposedShape[9];
        com[0] = new ComposedShape(new Rectangle(125, 115), new Rectangle(10, 35));
        com[0].optimalFit(); Selte.drawAll(com[0].getShapes(), "R in R");
        com[1] = new ComposedShape(new Rectangle(100, 125), new Circle(15));
        com[1].optimalFit(); Selte.drawAll(com[1].getShapes(), "C in R");
        com[2] = new ComposedShape(new Rectangle(100, 150), new Triangle(40));
        com[2].optimalFit(); Selte.drawAll(com[2].getShapes(), "T in R");
        getEnter();
        com[3] = new ComposedShape(new Circle(60), new Rectangle(10, 40));
        com[3].optimalFit(); Selte.drawAll(com[3].getShapes(), "R in C");
        com[4] = new ComposedShape(new Circle(100), new Circle(15));
        com[4].optimalFit(); Selte.drawAll(com[4].getShapes(), "C in C");
        com[5] = new ComposedShape(new Circle(125), new Triangle(40));
        com[5].optimalFit(); Selte.drawAll(com[5].getShapes(), "T in C");
        getEnter();
        com[6] = new ComposedShape(new Triangle(80), new Rectangle(10, 35));
        com[6].optimalFit(); Selte.drawAll(com[6].getShapes(), "R in T");
        com[7] = new ComposedShape(new Triangle(100), new Circle(15));
        com[7].optimalFit(); Selte.drawAll(com[7].getShapes(), "C in T");
        com[8] = new ComposedShape(new Triangle(150), new Triangle(40));
        com[8].optimalFit(); Selte.drawAll(com[8].getShapes(), "T in T");
        getEnter();

        System.exit(0);
    }

    private static void getEnter() {
        try {
            System.out.println("Please press ENTER to continue.");
            System.in.read(new byte[1]);
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void testGUI() {
        conR = new JRadioButton("Rectangle");
        conC = new JRadioButton("Circle");
        conT = new JRadioButton("Triangle");
        ButtonGroup conGroup = new ButtonGroup();
        conGroup.add(conR);
        conGroup.add(conC);
        conGroup.add(conT);
        smlR = new JRadioButton("Rectangle");
        smlC = new JRadioButton("Circle");
        smlT = new JRadioButton("Triangle");
        ButtonGroup smlGroup = new ButtonGroup();
        smlGroup.add(smlR);
        smlGroup.add(smlC);
        smlGroup.add(smlT);
        JButton drawButton = new JButton("DRAW");
        frame = new JFrame();
        drawButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.setVisible(false);
                if (conR.isSelected()) {
                    Main.getRectangleC();
                }
                else if (conC.isSelected()) {
                    Main.getCircleC();
                }
                else if (conT.isSelected()) {
                    Main.getTriangleC();
                }

                if (smlR.isSelected()) {
                    Main.smlShp = 'R';
                }
                else if (smlC.isSelected()) {
                    Main.smlShp = 'C';
                }
                else if (smlT.isSelected()) {
                    Main.smlShp = 'T';
                }
            }
        });
        frame.setTitle("161044061 - Ozan Şelte");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridBagLayout());
        GridBagConstraints gbC = new GridBagConstraints();
        gbC.fill = GridBagConstraints.HORIZONTAL;
        gbC.gridx = 0; gbC.gridy = 0;
        frame.add(new JLabel(" Container shape:"), gbC);
        gbC.gridx = 0; gbC.gridy = 1; frame.add(conR, gbC);
        gbC.gridx = 1; gbC.gridy = 1; frame.add(conC, gbC);
        gbC.gridx = 2; gbC.gridy = 1; frame.add(conT, gbC);
        gbC.gridx = 0; gbC.gridy = 2;
        frame.add(new JLabel(" Small shape:"), gbC);
        gbC.gridx = 0; gbC.gridy = 3; frame.add(smlR, gbC);
        gbC.gridx = 1; gbC.gridy = 3; frame.add(smlC, gbC);
        gbC.gridx = 2; gbC.gridy = 3; frame.add(smlT, gbC);
        gbC.gridx = 1; gbC.gridy = 4;
        frame.add(drawButton, gbC);
        frame.pack();
        frame.setVisible(true);
    }

    private static void getRectangleC() {
        JFrame frame = new JFrame();
        frame.setTitle("Rectangle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(3, 2));
        frame.add(new JLabel("Width"));
        wF = new JTextField();
        frame.add(wF);
        frame.add(new JLabel("Height"));
        hF = new JTextField();
        frame.add(hF);

        JButton btn = new JButton("Ok");
        frame.add(btn);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (wF.getText().isEmpty() ||
                        hF.getText().isEmpty())
                    return;
                double w = Double.parseDouble(wF.getText());
                double h = Double.parseDouble(hF.getText());
                Main.container = new Rectangle(w, h);
                Main.frame.setVisible(false);
                switch (Main.smlShp) {
                    case 'R': Main.getRectangleS(); break;
                    case 'C': Main.getCircleS(); break;
                    case 'T': Main.getTriangleS(); break;
                }
            }
        });
        frame.pack();
        frame.setVisible(true);
    }

    private static void getRectangleS() {
        JFrame frame = new JFrame();
        frame.setTitle("Rectangle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(3, 2));
        frame.add(new JLabel("Width"));
        wF = new JTextField();
        frame.add(wF);
        frame.add(new JLabel("Height"));
        hF = new JTextField();
        frame.add(hF);

        JButton btn = new JButton("Ok");
        frame.add(btn);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (wF.getText().isEmpty() ||
                            hF.getText().isEmpty())
                        return;
                    double w = Double.parseDouble(wF.getText());
                    double h = Double.parseDouble(hF.getText());
                    Main.small = new Rectangle(w, h);
                    Main.frame.setVisible(false);
                    Main.composed = new ComposedShape(Main.container, Main.small);
                    Main.composed.optimalFit();
                    Shape[] shapes = Main.composed.getShapes();
                    Selte.drawAll(shapes, "Ozan Şelte - 161044061");
                    getEnter();
                }
                catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
        frame.pack();
        frame.setVisible(true);
    }

    private static void getCircleC() {
        JFrame frame = new JFrame();
        frame.setTitle("Circle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(2, 2));
        frame.add(new JLabel("Radius"));
        rF = new JTextField();
        frame.add(rF);

        JButton btn = new JButton("Ok");
        frame.add(btn);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (rF.getText().isEmpty())
                    return;
                double r = Double.parseDouble(rF.getText());
                Main.container = new Circle(r);
                Main.frame.setVisible(false);
                switch (Main.smlShp) {
                    case 'R': Main.getRectangleS(); break;
                    case 'C': Main.getCircleS(); break;
                    case 'T': Main.getTriangleS(); break;
                }
            }
        });
        frame.pack();
        frame.setVisible(true);
    }

    private static void getCircleS() {
        JFrame frame = new JFrame();
        frame.setTitle("Circle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(2, 2));
        frame.add(new JLabel("Radius"));
        rF = new JTextField();
        frame.add(rF);

        JButton btn = new JButton("Ok");
        frame.add(btn);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (rF.getText().isEmpty())
                        return;
                    double r = Double.parseDouble(rF.getText());
                    Main.small = new Circle(r);
                    Main.frame.setVisible(false);
                    Main.composed = new ComposedShape(Main.container, Main.small);
                    Main.composed.optimalFit();
                    Shape[] shapes = Main.composed.getShapes();
                    Selte.drawAll(shapes, "Ozan Şelte - 161044061");
                    getEnter();
                }
                    catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
        frame.pack();
        frame.setVisible(true);
    }

    private static void getTriangleC() {
        JFrame frame = new JFrame();
        frame.setTitle("Triangle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(2, 2));
        frame.add(new JLabel("Side Length"));
        sF = new JTextField();
        frame.add(sF);

        JButton btn = new JButton("Ok");
        frame.add(btn);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (sF.getText().isEmpty())
                    return;
                double r = Double.parseDouble(sF.getText());
                Main.container = new Triangle(r);
                Main.frame.setVisible(false);
                switch (Main.smlShp) {
                    case 'R': Main.getRectangleS(); break;
                    case 'C': Main.getCircleS(); break;
                    case 'T': Main.getTriangleS(); break;
                }
            }
        });
        frame.pack();
        frame.setVisible(true);
    }

    private static void getTriangleS() {
        JFrame frame = new JFrame();
        frame.setTitle("Triangle");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(2, 2));
        frame.add(new JLabel("Side Length"));
        sF = new JTextField();
        frame.add(sF);

        JButton btn = new JButton("Ok");
        frame.add(btn);
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (sF.getText().isEmpty())
                        return;
                    double r = Double.parseDouble(sF.getText());
                    Main.small = new Triangle(r);
                    Main.frame.setVisible(false);
                    Main.composed = new ComposedShape(Main.container, Main.small);
                    Main.composed.optimalFit();
                    Shape[] shapes = Main.composed.getShapes();
                    Selte.drawAll(shapes, "Ozan Şelte - 161044061");
                    getEnter();
                }
                catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
        frame.pack();
        frame.setVisible(true);
    }
}
