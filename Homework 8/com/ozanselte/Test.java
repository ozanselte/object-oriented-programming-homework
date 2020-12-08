package com.ozanselte;

public class Test<C extends Collection> {

    private final static int TEST_N = 15;

    private static void printCollection(Collection c) {
        Iterator it = c.iterator();
        int size = c.size();
        System.out.print("isEmpty: " + c.isEmpty() + " size: " + c.size() + " - ");
        for (int i = 0; i < size; ++i) {
            System.out.print(it.step() + ", ");
        }
        System.out.println();
    }

    @SuppressWarnings("unchecked")
    public void testInteger() {
        try {
            C c = (C)new HashSet<Integer>();
            C t = (C)new ArrayList<Integer>();
            C r = (C)new LinkedList<Integer>();
            printCollection(c);
            for (int i = 0; i < TEST_N; i+=2) {
                c.add(i);
            }
            for (int i = 1; i < TEST_N/2; i+=2) {
                t.add(i);
            }
            for (int i = 0; i < TEST_N/2; i+=3) {
                r.add(i);
            }
            printCollection(c);
            System.out.println("contains(1): " + c.contains(1) + " containsAll: " + c.containsAll(t));
            c.addAll(t);
            printCollection(c);
            System.out.println("contains(1): " + c.contains(1) + " containsAll: " + c.containsAll(t));
            c.remove(2);
            c.removeAll(t);
            printCollection(c);
            printCollection(c.retainAll(r));
            c.clear();
            printCollection(c);
        }
        catch (UnsupportedOperationException e) {
            e.printStackTrace();
        }
        catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        }
    }

    @SuppressWarnings("unchecked")
    public void testString() {
        try{
            C c = (C)new HashSet<String>();
            C t = (C)new ArrayList<String>();
            C r = (C)new LinkedList<String>();
            printCollection(c);
            for (int i = 0; i < TEST_N; i+=2) {
                c.add("." + i + "@");
            }
            for (int i = 1; i < TEST_N/2; i+=2) {
                t.add("." + i + "@");
            }
            for (int i = 0; i < TEST_N/2; i+=3) {
                r.add("." + i + "@");
            }
            printCollection(c);
            System.out.println("contains(1): " + c.contains(".1@") + " containsAll: " + c.containsAll(t));
            c.addAll(t);
            printCollection(c);
            System.out.println("contains(1): " + c.contains(".1@") + " containsAll: " + c.containsAll(t));
            c.remove(".2@");
            c.removeAll(t);
            printCollection(c);
            printCollection(c.retainAll(r));
            c.clear();
            printCollection(c);
        }
        catch (UnsupportedOperationException e) {
            e.printStackTrace();
        }
        catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        }
    }

    public void testLinkedInteger() {
        try {
            LinkedList<Integer> c = new LinkedList<>();
            LinkedList<Integer> t = new LinkedList<>();
            LinkedList<Integer> r = new LinkedList<>();
            printCollection(c);
            for (int i = 0; i < TEST_N; i+=2) {
                c.add(i);
            }
            for (int i = 1; i < TEST_N/2; i+=2) {
                t.add(i);
            }
            for (int i = 0; i < TEST_N/2; i+=3) {
                r.add(i);
            }
            printCollection(c);
            System.out.println("contains(1): " + c.contains(1) + " containsAll: " + c.containsAll(t));
            c.addAll(t);
            printCollection(c);
            System.out.println("contains(1): " + c.contains(1) + " containsAll: " + c.containsAll(t));
            System.out.println("Element func: " + c.element());
            c.remove(0);
            printCollection(c);
            printCollection(c.retainAll(r));
            System.out.println("Poll func: " + c.poll());
            printCollection(c);
            c.clear();
            printCollection(c);
            System.out.println("   >>This exception has throwen intentionally.");
            c.removeAll(t);
        }
        catch (UnsupportedOperationException e) {
            e.printStackTrace();
        }
        catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        }
    }

    public void testLinkedString() {
        try {
            LinkedList<String> c = new LinkedList<>();
            LinkedList<String> t = new LinkedList<>();
            LinkedList<String> r = new LinkedList<>();
            printCollection(c);
            for (int i = 0; i < TEST_N; i+=2) {
                c.add("." + i + "@");
            }
            for (int i = 1; i < TEST_N/2; i+=2) {
                t.add("." + i + "@");
            }
            for (int i = 0; i < TEST_N/2; i+=3) {
                r.add("." + i + "@");
            }
            printCollection(c);
            System.out.println("contains(1): " + c.contains(".1@") + " containsAll: " + c.containsAll(t));
            c.addAll(t);
            printCollection(c);
            System.out.println("contains(1): " + c.contains(".1@") + " containsAll: " + c.containsAll(t));
            System.out.println("Element func: " + c.element());
            c.remove(".1@");
            printCollection(c);
            printCollection(c.retainAll(r));
            System.out.println("Poll func: " + c.poll());
            printCollection(c);
            c.clear();
            printCollection(c);
            System.out.println("   >>This exception has throwen intentionally.");
            c.removeAll(t);
        }
        catch (UnsupportedOperationException e) {
            e.printStackTrace();
        }
        catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        }
    }
}
