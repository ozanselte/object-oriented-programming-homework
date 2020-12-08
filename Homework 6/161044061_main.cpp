#include <iostream>

#include "HashSet.cpp"
#include "ArrayList.cpp"
#include "LinkedList.cpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::to_string;
using namespace SELTE_HW6;

const int TEST_N = 15;

template<typename C>
void printCollection(C& c);

template<typename C>
void testInt();

template<typename C>
void testString();

template<typename C>
void testLinkedInt();

template<typename C>
void testLinkedString();

int main() {
    cout << endl << "  >>HashSet Int Vector Tests" << endl;
    testInt<HashSet<int, std::vector<int> > >();
    cout << endl << "  >>HashSet Int List Tests" << endl;
    testInt<HashSet<int, std::list<int> > >();
    cout << endl << "  >>HashSet Int Set Tests" << endl;
    testInt<HashSet<int, std::set<int> > >();
    cout << endl << "  >>HashSet String Vector Tests" << endl;
    testString<HashSet<string, std::vector<string> > >();
    cout << endl << "  >>HashSet String List Tests" << endl;
    testString<HashSet<string, std::list<string> > >();
    cout << endl << "  >>HashSet String Set Tests" << endl;
    testString<HashSet<string, std::set<string> > >();
    cout << endl << endl << endl;

    cout << endl << "  >>ArrayList Int Vector Tests" << endl;
    testInt<ArrayList<int, std::vector<int> > >();
    cout << endl << "  >>ArrayList Int List Tests" << endl;
    testInt<ArrayList<int, std::list<int> > >();
    cout << endl << "  >>ArrayList Int Set Tests" << endl;
    testInt<ArrayList<int, std::set<int> > >();
    cout << endl << "  >>ArrayList String Vector Tests" << endl;
    testString<ArrayList<string, std::vector<string> > >();
    cout << endl << "  >>ArrayList String List Tests" << endl;
    testString<ArrayList<string, std::list<string> > >();
    cout << endl << "  >>ArrayList String Set Tests" << endl;
    testString<ArrayList<string, std::set<string> > >();
    cout << endl << endl << endl;

    cout << endl << "  >>LinkedList Int Vector Tests" << endl;
    testLinkedInt<LinkedList<int, std::vector<int> > >();
    cout << endl << "  >>LinkedList Int List Tests" << endl;
    testLinkedInt<LinkedList<int, std::list<int> > >();
    cout << endl << "  >>LinkedList Int Set Tests" << endl;
    testLinkedInt<LinkedList<int, std::set<int> > >();
    cout << endl << "  >>LinkedList String Vector Tests" << endl;
    testLinkedString<LinkedList<string, std::vector<string> > >();
    cout << endl << "  >>LinkedList String List Tests" << endl;
    testLinkedString<LinkedList<string, std::list<string> > >();
    cout << endl << "  >>LinkedList String Set Tests" << endl;
    testLinkedString<LinkedList<string, std::set<string> > >();
    cout << endl << endl << endl;
    return 0;
}

template<typename C>
void printCollection(C& c)
{
    auto it = c.iterator();
    auto size = c.size();
    cout << "isEmpty: " << c.isEmpty() << " size: " << c.size() << " - ";
    for (int i = 0; i < size; ++i) {
        cout << it.step() << ", ";
    }
    cout << endl;
}

template<typename C>
void testInt()
{
    try{
        C c, t, r;
        printCollection<C>(c);
        for (int i = 0; i < TEST_N; i+=2) {
            c.add(i);
        }
        for (int i = 1; i < TEST_N/2; i+=2) {
            t.add(i);
        }
        for (int i = 0; i < TEST_N/2; i+=3) {
            r.add(i);
        }
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(1) << " containsAll: " << c.containsAll(t) << endl;
        c.addAll(t);
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(1) << " containsAll: " << c.containsAll(t) << endl;
        c.remove(2);
        c.removeAll(t);
        printCollection<C>(c);
        printCollection<C>(c.retainAll(r));
        c.clear();
        printCollection<C>(c);
    }
    catch(std::exception& e){
        cerr << e.what() << endl;
    }
}

template<typename C>
void testString()
{
    try{
        C c, t, r;
        printCollection<C>(c);
        for (int i = 0; i < TEST_N; i+=2) {
            c.add('.' + to_string(i) + '@');
        }
        for (int i = 1; i < TEST_N/2; i+=2) {
            t.add('.' + to_string(i) + '@');
        }
        for (int i = 0; i < TEST_N/2; i+=3) {
            r.add('.' + to_string(i) + '@');
        }
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(".1@") << " containsAll: " << c.containsAll(t) << endl;
        c.addAll(t);
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(".1@") << " containsAll: " << c.containsAll(t) << endl;
        c.remove(".2@");
        c.removeAll(t);
        printCollection<C>(c);
        printCollection<C>(c.retainAll(r));
        c.clear();
        printCollection<C>(c);
    }
    catch(std::exception& ex){
        cerr << ex.what() << endl;
    }
}

template<typename C>
void testLinkedInt()
{
    try{
        C c, t, r;
        printCollection<C>(c);
        for (int i = 0; i < TEST_N; i+=2) {
            c.add(i);
        }
        for (int i = 1; i < TEST_N/2; i+=2) {
            t.offer(i);
        }
        for (int i = 0; i < TEST_N/2; i+=3) {
            r.offer(i);
        }
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(1) << " containsAll: " << c.containsAll(t) << endl;
        c.addAll(t);
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(1) << " containsAll: " << c.containsAll(t) << endl;
        cout << "Element func: " << c.element() << endl;
        c.remove(0);
        printCollection<C>(c);
        printCollection<C>(c.retainAll(r));
        cout << "Poll func: " << c.poll() << endl;
        printCollection<C>(c);
        c.clear();
        printCollection<C>(c);
        cout << "  >>This exception has throwen intentionally." << endl;
        c.removeAll(t);
    }
    catch(std::exception& e){
        cerr << e.what() << endl;
    }
}

template<typename C>
void testLinkedString()
{
    try{
        C c, t, r;
        printCollection<C>(c);
        for (int i = 0; i < TEST_N; i+=2) {
            c.add('.' + to_string(i) + '@');
        }
        for (int i = 1; i < TEST_N/2; i+=2) {
            t.offer('.' + to_string(i) + '@');
        }
        for (int i = 0; i < TEST_N/2; i+=3) {
            r.offer('.' + to_string(i) + '@');
        }
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(".1@") << " containsAll: " << c.containsAll(t) << endl;
        c.addAll(t);
        printCollection<C>(c);
        cout << "contains(1): " << c.contains(".1@") << " containsAll: " << c.containsAll(t) << endl;
        cout << "Element func: " << c.element() << endl;
        c.remove(".0@");
        printCollection<C>(c);
        printCollection<C>(c.retainAll(r));
        cout << "Poll func: " << c.poll() << endl;
        printCollection<C>(c);
        c.clear();
        printCollection<C>(c);
        cout << "  >>This exception has throwen intentionally." << endl;
        c.removeAll(t);
    }
    catch(std::exception& ex){
        cerr << ex.what() << endl;
    }
}