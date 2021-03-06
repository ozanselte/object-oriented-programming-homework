//
// Created by ozanselte on 12/24/18.
//

#ifndef HW6_COLLECTION_H
#define HW6_COLLECTION_H

#include <vector>
#include <list>
#include <set>
#include "Iterator.cpp"

namespace SELTE_HW6 {
    template<typename E, typename C=std::vector<E> >
    class Collection {
    public:
        virtual Iterator<E, C> iterator() =0;
        virtual void add(const E& e) =0;
        virtual void addAll(Collection<E, C>& c) =0;
        virtual void clear() =0;
        virtual bool contains(const E& e) const =0;
        virtual bool containsAll(Collection<E, C>& c) const =0;
        virtual bool isEmpty() const =0;
        virtual void remove(const E& e) =0;
        virtual void removeAll(Collection<E, C>& c) =0;
        virtual Collection<E, C>& retainAll(Collection<E, C>& c) =0;
        virtual size_t size() const =0;
    };
}

#endif //HW6_COLLECTION_H
