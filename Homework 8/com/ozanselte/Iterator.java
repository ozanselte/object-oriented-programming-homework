package com.ozanselte;

/**
 * An iterator over a collection.
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-11
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public class Iterator<E> {

    private int index;
    private E[] arr;

    /**
     * Constructor of Iterator class
     * @param a Array of E
     */
    public Iterator(E[] a) {
        arr = a;
        index = 0;
    }

    /**
     * Returns true if the iteration has more elements
     * @return True if the iteration has next element
     */
    public boolean hasNext() {
        if (arr.length - 1 > index) {
            return true;
        }
        return false;
    }

    /**
     * Returns the next element in the iteration and advances the
     * iterator
     * @return Next element
     * @throws ArrayIndexOutOfBoundsException in case of there is not a next element
     */
    public E next() throws ArrayIndexOutOfBoundsException {
        if (this.hasNext()) {
            index++;
        }
        else {
            throw new ArrayIndexOutOfBoundsException("Iterator cannot iterate! There is not a next point.");
        }
        return this.get();
    }

    /**
     * Returns the current element in the iteration
     * @return Current element
     */
    public E get() {
        return arr[index];
    }

    /**
     * Returns the current element in the iteration and advances the
     * iterator
     * @return Current element
     */
    public E step() {
        E e = this.get();
        if (this.hasNext()) {
            index++;
        }
        return e;
    }

    /**
     * Removes from the underlying collection the last element returned
     * by this iterator
     */
    public void remove() {
        @SuppressWarnings("unchecked")
        E[] futureArr = (E[])new Object[arr.length - 1];
        if (0 < index) {
            System.arraycopy(arr, 0, futureArr, 0, index);
        }
        if (futureArr.length > index) {
            System.arraycopy(arr, index+1, futureArr, index, arr.length-index-1);
        }
        arr = futureArr;
    }
}
