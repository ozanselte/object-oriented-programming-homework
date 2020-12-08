import com.ozanselte.*;

public class Main {

    public static void main(String[] args) {
        System.out.println("\n\nHashSet Integer Test");
        Test<HashSet<Integer>> testHsInt = new Test<>();
        testHsInt.testInteger();
        System.out.println("\nHashSet String Test");
        Test<HashSet<String>> testHsStr = new Test<>();
        testHsStr.testString();

        System.out.println("\n\nArrayList Integer Test");
        Test<ArrayList<Integer>> testAlInt = new Test<>();
        testAlInt.testInteger();
        System.out.println("\nArrayList String Test");
        Test<ArrayList<String>> testAlStr = new Test<>();
        testAlStr.testString();

        System.out.println("\n\nLinkedList Integer Test");
        Test<LinkedList<Integer>> testLlInt = new Test<>();
        testLlInt.testLinkedInteger();
        System.out.println("\nLinkedList String Test");
        Test<LinkedList<String>> testLlStr = new Test<>();
        testLlStr.testLinkedString();
    }
}
