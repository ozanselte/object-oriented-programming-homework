//
// Created by ozanselte on 12/24/18.
//

#ifndef HW6_ITERATOR_H
#define HW6_ITERATOR_H

#include <vector>
#include <list>
#include <set>
#include <memory>
#include <stdexcept>

using std::range_error;

namespace SELTE_HW6 {
    template<typename E, typename C=std::vector<E> >
    class Iterator {
    public:
        bool hasNext();
        E next() throw(range_error);
        E step();
        Iterator& remove();

        Iterator(C& c);

    private:
        C& container;
        typename C::iterator iterator;
    };
}

#endif //HW6_ITERATOR_H
