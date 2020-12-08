package com.ozanselte;

import java.util.Arrays;

/**
 * Implementation of List and Queue interface functions
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-12
 * @see com.ozanselte.List
 * @see com.ozanselte.Queue
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public class LinkedList<E> implements List<E>, Queue<E> {

    private E[] arr;

    public Iterator<E> iterator() {
        return new Iterator<E>(arr);
    }

    @SuppressWarnings("unchecked")
    public void add(E e) {
        E[] futureArr = (E[])new Object[this.size() + 1];
        if (this.size() > 0) {
            System.arraycopy(this.arr, 0, futureArr, 0, this.size());
        }
        futureArr[this.size()] = e;
        arr = futureArr;
        Arrays.sort(arr);
    }

    public void addAll(Collection<E> c) {
        Iterator<E> it = c.iterator();
        for (int i = 0; i < c.size(); i++) {
            this.add(it.step());
        }
    }

    @SuppressWarnings("unchecked")
    public void clear() {
        this.arr = (E[])new Object[0];
    }

    public boolean contains(E e) {
        for (int i = 0; i < this.size(); i++) {
            if (this.arr[i].equals(e)) {
                return true;
            }
        }
        return false;
    }

    public boolean containsAll(Collection<E> c) {
        Iterator<E> it = c.iterator();
        for (int i = 0; i < c.size(); i++) {
            if (!this.contains(it.step())){
                return false;
            }
        }
        return true;
    }

    public boolean isEmpty() {
        return this.size() <= 0;
    }

    /**
     * Removes all of this collection's elements that are also contained
     * in the specified collection
     * @param e The element
     * @throws UnsupportedOperationException in case of not head element
     */
    @SuppressWarnings("unchecked")
    public void remove(E e) throws UnsupportedOperationException {
        if (this.arr[0].equals(e)) {
            E[] futureArr = (E[])new Object[arr.length - 1];
            System.arraycopy(arr, 1, futureArr, 0, arr.length-1);
            arr = futureArr;
        }
        else {
            throw new UnsupportedOperationException("The element cannot removed! It must be at head of the queue.");
        }
    }

    public void removeAll(Collection<E> c) {
        Iterator<E> it = c.iterator();
        for (int i = 0; i < c.size(); i++) {
            this.remove(it.step());
        }
    }

    public LinkedList<E> retainAll(Collection<E> c) {
        LinkedList<E> temp = new LinkedList<E>();
        Iterator<E> it = c.iterator();
        for (int i = 0; i < c.size(); i++) {
            E e = it.step();
            if (this.contains(e)) {
                temp.add(e);
            }
        }
        return temp;
    }

    public int size() {
        if (null == arr) {
            return 0;
        }
        return arr.length;
    }

    /**
     * Ensures that this collection contains the specified element.
     * @return The element
     * @throws UnsupportedOperationException in case of zero element in LinkedList
     */
    public E element() throws UnsupportedOperationException {
        if (this.size() > 0) {
            return arr[0];
        }
        else {
            throw new UnsupportedOperationException("There is no element in LinkedList!");
        }
    }

    public void offer(E e) {
        this.add(e);
    }

    public E poll() {
        E e = this.element();
        this.remove(e);
        return e;
    }
}
