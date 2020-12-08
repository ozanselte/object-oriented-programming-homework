//
// Created by ozanselte on 12/24/18.
//

#include "Iterator.h"

namespace SELTE_HW6 {
    template<typename E, typename C>
    bool Iterator<E, C>::hasNext()
    {
        if(container.end() == iterator){
            return false;
        }
        ++iterator;
        if(container.end() == iterator){
            --iterator;
            return false;
        }
        --iterator;
        return true;
    }

    template<typename E, typename C>
    E Iterator<E, C>::next() throw(range_error)
    {
        if(!hasNext()){
            throw range_error("Iterator cannot iterate to the next point! There is not a next point.");
        }
        return *(++iterator);
    }

    template<typename E, typename C>
    E Iterator<E, C>::step()
    {
        E e = *(iterator);
        if(hasNext()){
            next();
        }
        return e;
    }

    template<typename E, typename C>
    Iterator<E, C>& Iterator<E, C>::remove()
    {
        E obj = *iterator;
        container.erase(iterator);
        return(obj);
    }

    template<typename E, typename C>
    Iterator<E, C>::Iterator(C& c)
    : container(c), iterator(c.begin())
    { /* EMPTY */ }
}