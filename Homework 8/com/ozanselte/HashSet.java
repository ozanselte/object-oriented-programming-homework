package com.ozanselte;

/**
 * Implementation of Set interface functions
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-11
 * @see com.ozanselte.Set
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public class HashSet<E> implements Set<E> {

    private E[] arr;

    public Iterator<E> iterator() {
        return new Iterator<E>(arr);
    }

    /**
     * Ensures that this collection contains the specified element.
     * @param e The element
     * @throws UnsupportedOperationException in case of passing already contained element.
     */
    @SuppressWarnings("unchecked")
    public void add(E e) throws UnsupportedOperationException {
        if (this.contains(e)) {
            throw new UnsupportedOperationException("Member is already inside HashSet Collection!");
        }
        else {
            E[] futureArr = (E[])new Object[this.size() + 1];
            if (this.size() > 0) {
                System.arraycopy(this.arr, 0, futureArr, 0, this.size());
            }
            futureArr[this.size()] = e;
            arr = futureArr;
        }
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

    @SuppressWarnings("unchecked")
    public void remove(E e) {
        for (int i = 0; i < this.size(); i++) {
            if (this.arr[i].equals(e)) {
                E[] futureArr = (E[])new Object[arr.length - 1];
                if (0 < i) {
                    System.arraycopy(arr, 0, futureArr, 0, i);
                }
                if (futureArr.length > i) {
                    System.arraycopy(arr, i+1, futureArr, i, arr.length-i-1);
                }
                arr = futureArr;
                return;
            }
        }
    }

    public void removeAll(Collection<E> c) {
        Iterator<E> it = c.iterator();
        for (int i = 0; i < c.size(); i++) {
            this.remove(it.step());
        }
    }

    public HashSet<E> retainAll(Collection<E> c) {
        HashSet<E> temp = new HashSet<E>();
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
}
