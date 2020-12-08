package com.ozanselte;

/**
 * This is a generic class with one generic parameters which is the generic type E
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-11
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public interface Collection<E> {

    /**
     * Returns an iterator over the collection.
     * @return Iterator of the collection begin
     */
    public Iterator<E> iterator();

    /**
     * Ensures that this collection contains the specified element.
     * @param e The element
     */
    public void add(E e);

    /**
     * Adds all of the elements in the specified collection to this
     * collection.
     * @param c The collection
     */
    public void addAll(Collection<E> c);

    /**
     * Removes all of the elements from this collection.
     */
    public void clear();

    /**
     * Returns true if this collection contains the specified element.
     * @param e The element
     * @return Contains status
     */
    public boolean contains(E e);

    /**
     * Returns true if this collection contains all of the elements in the
     * specified collection.
     * @param c The collection
     * @return Contains status
     */
    public boolean containsAll(Collection<E> c);

    /**
     * Returns true if this collection contains no elements.
     * @return True if collection is empty
     */
    public boolean isEmpty();

    /**
     * Removes a single instance of the specified element from this
     * collection, if it is present
     * @param e The element
     */
    public void remove(E e);

    /**
     * Removes all of this collection's elements that are also contained
     * in the specified collection
     * @param c The collection
     */
    public void removeAll(Collection<E> c);

    /**
     * Retains only the elements in this collection that are contained in
     * the specified collection
     * @param c The collection
     * @return Retained collection
     */
    public Collection<E> retainAll(Collection<E> c);

    /**
     * Returns the number of elements in this collection.
     * @return Colelction size
     */
    public int size();
}