package com.ozanselte;

/**
 * Queues order elements in a FIFO (first-in-first-out) manner. There is no random access with
 * this Collection. Some functions throw exceptions.
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-11
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public interface Queue<E> extends Collection<E> {
    public Iterator<E> iterator();

    /**
     * Inserts the specified element into this queue
     * @param e The element
     */
    public void add(E e);
    public void addAll(Collection<E> c);
    public void clear();
    public boolean contains(E e);
    public boolean containsAll(Collection<E> c);
    public boolean isEmpty();
    public void remove(E e);
    public void removeAll(Collection<E> c);
    public Queue<E> retainAll(Collection<E> c);
    public int size();

    /**
     * Ensures that this collection contains the specified element.
     * @return The element
     */
    public E element();

    /**
     * Inserts the specified element into this queue.
     * @param e The element
     */
    public void offer(E e);

    /**
     * Retrieves and removes the head of this queue, or throws if this
     * queue is empty.
     * @return First element of this queue
     */
    public E poll();
}