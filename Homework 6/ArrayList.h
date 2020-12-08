//
// Created by ozanselte on 12/26/18.
//

#ifndef HW6_ARRAYLIST_H
#define HW6_ARRAYLIST_H

#include "List.h"
#include <string>

namespace SELTE_HW6 {
    template<typename E, typename C=std::vector <E> >
    class ArrayList : public List<E, C> {
    public:
        Iterator<E, C> iterator();
        void add(const E& e) ;
        void addAll(Collection<E, C>& c);
        void clear();
        bool contains(const E& e) const;
        bool containsAll(Collection<E, C>& c) const;
        bool isEmpty() const;
        void remove(const E& e);
        void removeAll(Collection<E, C>& c);
        ArrayList<E, C>& retainAll(Collection<E, C>& c);
        size_t size() const;

    private:
        C container;

        void sort(std::vector<E>& c);
        void sort(std::list<E>& c);
        void sort(std::set<E>& c);
    };
}

#endif //HW6_ARRAYLIST_H
