//
// Created by flamy on 07/12/21.
//

#ifndef TEMPLATE_MAP_H
#define TEMPLATE_MAP_H

#include "BST.h"

template <class Key, class Value>
        class MapIterator;

template <class Key, class Value>
class Map {

    BST<Key, Value> tree;
    int cnt;

public:
    friend class MapIterator<Key, Value>;
    typedef MapIterator<Key, Value> iterator;
    //constructor
    Map(): cnt(0) {};
    //methods
    [[nodiscard]] int size() const {return cnt;};
    [[nodiscard]] bool empty() const {return cnt==0;};
    std::pair<iterator, bool> insert (std::pair<Key, Value>);
    void clear() noexcept;
    Value& operator [] (const Key & key) const;
    Value& operator [] (Key && key);

    iterator begin() const;
    iterator end() const;
    iterator find(const Key&) const;
};

template <class Key, class Value>
class MapIterator {
private:
    node<Key, Value>* cur;
public:
    MapIterator():cur(nullptr) {};
    explicit MapIterator(node<Key, Value>* a): cur(a) {};
    bool operator !=(const MapIterator<Key, Value> &) const;
    bool operator == (const MapIterator<Key, Value> &) const;
    node<Key, Value>& operator*();
    node<Key, Value>* operator->();
    MapIterator<Key, Value>& operator ++();
    const MapIterator<Key, Value>& operator ++(int) const;
};

template<class Key, class Value>
typename Map<Key, Value>::iterator Map<Key, Value>::begin() const {
    return Map<Key, Value>::iterator(tree.minimum());
}

template<class Key, class Value>
typename Map<Key, Value>::iterator Map<Key, Value>::end() const {
    return Map<Key, Value>::iterator(nullptr);
}

template<class Key, class Value>
typename Map<Key, Value>::iterator Map<Key, Value>::find(const Key &k) const {
    auto res = tree.search(k);
    if (res == nullptr)
        return end();
    return Map<Key, Value>::iterator(res);
}

template<class Key, class Value>
std::pair<typename Map<Key, Value>::iterator, bool> Map<Key, Value>::insert(std::pair<Key, Value> info) {
    auto res = find(info.first);
    if (res != end())
        return std::make_pair(res, false);
    iterator tmp(tree.insert(info));
    cnt++;
    return std::make_pair(tmp, true);
}

template<class Key, class Value>
void Map<Key, Value>::clear() noexcept {
    tree.erase();
    cnt = 0;
}

template<class Key, class Value>
Value &Map<Key, Value>::operator[](const Key &key) const{
    auto p = find(key);
    if (p == end())
        throw std::invalid_argument("Invalid key!");
    return p->data.second;
}

template<class Key, class Value>
Value &Map<Key, Value>::operator[](Key &&key) {
    auto p = find(key);
    if (p == end()) {
        Value v;
        auto pp = insert(std::make_pair(key, v));
        if (!pp.second)
            throw std::invalid_argument("Insert is not completed!");
        p = pp.first;
    }
    return p->data.second;
}

template<class Key, class Value>
bool MapIterator<Key, Value>::operator!=(const MapIterator<Key, Value> &it) const {
    return cur != it.cur;
}

template<class Key, class Value>
bool MapIterator<Key, Value>::operator==(const MapIterator<Key, Value> &it) const {
    return cur == it.cur;
}

template<class Key, class Value>
node<Key, Value> &MapIterator<Key, Value>::operator*() {
    return *cur;
}

template<class Key, class Value>
node<Key, Value> *MapIterator<Key, Value>::operator->() {
    return cur;
}

template<class Key, class Value>
MapIterator<Key, Value> &MapIterator<Key, Value>::operator++() {
    cur = cur->next(cur);
    return *this;
}

template<class Key, class Value>
const MapIterator<Key, Value>& MapIterator<Key, Value>::operator++(int) const {
    const MapIterator& res(*this);
    ++cur;
    return res;
}

#endif //TEMPLATE_MAP_H