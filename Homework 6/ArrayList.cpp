//
// Created by ozanselte on 12/26/18.
//

#include "ArrayList.h"
#include <algorithm>

namespace SELTE_HW6 {
    template<typename E, typename C>
    Iterator<E, C> ArrayList<E, C>::iterator() {
        return Iterator<E, C>(container);
    }

    template<typename E, typename C>
    void ArrayList<E, C>::add(const E& e) {
        container.insert(container.end(), e);
        sort(container);
    }

    template<typename E, typename C>
    void ArrayList<E, C>::addAll(Collection<E, C>& c) {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            add(it.step());
        }
    }

    template<typename E, typename C>
    void ArrayList<E, C>::clear() {
        container.clear();
    }

    template<typename E, typename C>
    bool ArrayList<E, C>::contains(const E& e) const {
        for(auto i : container){
            if(e == i){
                return true;
            }
        }
        return false;
    }

    template<typename E, typename C>
    bool ArrayList<E, C>::containsAll(Collection<E, C>& c) const {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            if(!contains(it.step())){
                return false;
            }
        }
        return true;
    }

    template<typename E, typename C>
    bool ArrayList<E, C>::isEmpty() const {
        return container.empty();
    }

    template<typename E, typename C>
    void ArrayList<E, C>::remove(const E& e) {
        for(auto it = container.begin(); it != container.end(); it++) {
            if(e == *it){
                container.erase(it);
                return;
            }
        }
    }

    template<typename E, typename C>
    void ArrayList<E, C>::removeAll(Collection<E, C>& c) {
        auto it = c.iterator();
        for(int i = 0; i < c.size(); ++i){
            remove(it.step());
        }
    }

    template<typename E, typename C>
    ArrayList<E, C>& ArrayList<E, C>::retainAll(Collection<E, C>& c) {
        static ArrayList<E, C> temp;
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
    size_t ArrayList<E, C>::size() const {
        return container.size();
    }

    template<typename E, typename C>
    void ArrayList<E, C>::sort(std::vector<E>& c)
    {
        std::sort(c.begin(), c.end());
    }

    template<typename E, typename C>
    void ArrayList<E, C>::sort(std::list<E>& c)
    {
        c.sort();
    }

    template<typename E, typename C>
    void ArrayList<E, C>::sort(std::set<E>& c)
    {
        /* Set Container is already sorted. */
        return;
    }
}