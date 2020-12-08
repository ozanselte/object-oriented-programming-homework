//
// Created by ozanselte on 12/27/18.
//

#ifndef HW6_LINKEDLIST_H
#define HW6_LINKEDLIST_H

#include "List.h"
#include "Queue.h"
#include <stdexcept>

using std::range_error;

namespace SELTE_HW6 {
    template<typename E, typename C=std::vector<E> >
    class LinkedList : public List<E, C>, Queue<E, C> {
    public:
        Iterator<E, C> iterator();
        void add(const E& e);
        void addAll(Collection<E, C>& c);
        void clear();
        bool contains(const E& e) const;
        bool containsAll(Collection<E, C>& c) const;
        bool isEmpty() const;
        void remove(const E& e) throw(range_error);
        void removeAll(Collection<E, C>& c);
        LinkedList<E, C>& retainAll(Collection<E, C>& c);
        size_t size() const;

        E element();
        void offer(const E& e);
        E poll() throw(range_error);

    private:
        C container;
    };
}

#endif //HW6_LINKEDLIST_H
