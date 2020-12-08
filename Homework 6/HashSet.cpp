//
// Created by ozanselte on 12/25/18.
//

#include "HashSet.h"

namespace SELTE_HW6 {
    template<typename E, typename C>
    Iterator<E, C> HashSet<E, C>::iterator() {
        return Iterator<E, C>(container);
    }

    template<typename E, typename C>
    void HashSet<E, C>::add(const E& e) throw(invalid_argument) {
        if(!contains(e)){
            container.insert(container.end(), e);
        }
        else{
            throw invalid_argument("Member is already inside HashSet Collection!");
        }
    }

    template<typename E, typename C>
    void HashSet<E, C>::addAll(Collection<E, C>& c) {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            add(it.step());
        }
    }

    template<typename E, typename C>
    void HashSet<E, C>::clear() {
        container.clear();
    }

    template<typename E, typename C>
    bool HashSet<E, C>::contains(const E& e) const {
        for(auto i : container){
            if(e == i){
                return true;
            }
        }
        return false;
    }

    template<typename E, typename C>
    bool HashSet<E, C>::containsAll(Collection<E, C>& c) const {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            if(!contains(it.step())){
                return false;
            }
        }
        return true;
    }

    template<typename E, typename C>
    bool HashSet<E, C>::isEmpty() const {
        return container.empty();
    }

    template<typename E, typename C>
    void HashSet<E, C>::remove(const E& e) {
        for(auto it = container.begin(); it != container.end(); ++it) {
            if(e == *it){
                container.erase(it);
                return;
            }
        }
    }

    template<typename E, typename C>
    void HashSet<E, C>::removeAll(Collection<E, C>& c) {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            remove(it.step());
        }
    }

    template<typename E, typename C>
    HashSet<E, C>& HashSet<E, C>::retainAll(Collection<E, C>& c) {
        static HashSet<E, C> temp;
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
    size_t HashSet<E, C>::size() const {
        return container.size();
    }
}