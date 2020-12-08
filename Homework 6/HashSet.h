//
// Created by ozanselte on 12/25/18.
//

#ifndef HW6_HASHSET_H
#define HW6_HASHSET_H

#include "Set.h"
#include <stdexcept>

using std::invalid_argument;

namespace SELTE_HW6 {
    template<typename E, typename C=std::vector<E> >
    class HashSet : public Set<E, C>{
    public:
        Iterator<E, C> iterator();
        void add(const E& e) throw(invalid_argument) ;
        void addAll(Collection<E, C>& c);
        void clear();
        bool contains(const E& e) const;
        bool containsAll(Collection<E, C>& c) const;
        bool isEmpty() const;
        void remove(const E& e);
        void removeAll(Collection<E, C>& c);
        HashSet<E, C>& retainAll(Collection<E, C>& c);
        size_t size() const;

    private:
        C container;
    };
}

#endif //HW6_HASHSET_H
