//
// Created by ozanselte on 12/27/18.
//

#include "LinkedList.h"

namespace SELTE_HW6 {
    template<typename E, typename C>
    Iterator<E, C> LinkedList<E, C>::iterator() {
        return Iterator<E, C>(container);
    }

    template<typename E, typename C>
    void LinkedList<E, C>::add(const E& e) {
        container.insert(container.end(), e);
    }

    template<typename E, typename C>
    void LinkedList<E, C>::addAll(Collection<E, C>& c) {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            add(it.step());
        }
    }

    template<typename E, typename C>
    void LinkedList<E, C>::clear() {
        container.clear();
    }

    template<typename E, typename C>
    bool LinkedList<E, C>::contains(const E& e) const {
        for(auto i : container){
            if(e == i){
                return true;
            }
        }
        return false;
    }

    template<typename E, typename C>
    bool LinkedList<E, C>::containsAll(Collection<E, C>& c) const {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            if(!contains(it.step())){
                return false;
            }
        }
        return true;
    }

    template<typename E, typename C>
    bool LinkedList<E, C>::isEmpty() const {
        return container.empty();
    }

    template<typename E, typename C>
    void LinkedList<E, C>::remove(const E& e) throw(range_error) {
        if(isEmpty()){
            throw range_error("LinkedList is empty. Remove cannot be used!");
        }
        if(*container.begin() != e){
            throw range_error("Object cannot removed! It has to be begin of the LinkedList.");
        }
        container.erase(container.begin());
    }

    template<typename E, typename C>
    void LinkedList<E, C>::removeAll(Collection<E, C>& c) {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            remove(it.step());
        }
    }

    template<typename E, typename C>
    LinkedList<E, C>& LinkedList<E, C>::retainAll(Collection<E, C>& c) {
        static LinkedList<E, C> temp;
        temp.clear();
        auto it = c.iterator();
        for(int i = 0; i < c.size(); i++){
            E e = it.step();
            if(contains(e)){
                temp.add(e);
            }
        }
        return temp;
    }

    template<typename E, typename C>
    size_t LinkedList<E, C>::size() const {
        return container.size();
    }

    template<typename E, typename C>
    E LinkedList<E, C>::element()
    {
        return *(container.begin());
    }

    template<typename E, typename C>
    void LinkedList<E, C>::offer(const E& e)
    {
        add(e);
    }

    template<typename E, typename C>
    E LinkedList<E, C>::poll() throw(range_error)
    {
        if(isEmpty()){
            throw range_error("LinkedList is empty. Pull cannot be used!");
        }
        E e = element();
        remove(e);
        return e;
    }
}