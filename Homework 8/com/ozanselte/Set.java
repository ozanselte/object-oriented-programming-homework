package com.ozanselte;

/**
 * A collection that contains no duplicate elements. There is no order for this collection. In other
 * words, you don’t have to keep the insertion order of the e
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-11
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public interface Set<E> extends Collection<E> {
    public Iterator<E> iterator();
    public void add(E e);
    public void addAll(Collection<E> c);
    public void clear();
    public boolean contains(E e);
    public boolean containsAll(Collection<E> c);
    public boolean isEmpty();
    public void remove(E e);
    public void removeAll(Collection<E> c);
    public Set<E> retainAll(Collection<E> c);
    public int size();
}
