package com.ozanselte;

/**
 * An ordered collection (also known as a sequence). The user of this interface has precise
 * control over where in the list each element is inserted.
 *
 * @author Ozan Şelte
 * @version 1.0.0
 * @since 2019-01-11
 * @param <E> <code>Integer</code> or <code>String</code>
 */
public interface List<E> extends Collection<E> {
    public Iterator<E> iterator();
    public void add(E e);
    public void addAll(Collection<E> c);
    public void clear();
    public boolean contains(E e);
    public boolean containsAll(Collection<E> c);
    public boolean isEmpty();
    public void remove(E e);
    public void removeAll(Collection<E> c);
    public List<E> retainAll(Collection<E> c);
    public int size();
}