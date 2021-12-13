//
// Created by flamy on 07/12/21.
//

#ifndef TEMPLATE_BST_H
#define TEMPLATE_BST_H
#include "Node.hpp"

template <class Key, class Value>
class BST {
    node<Key, Value>* root;
public:
    BST(): root(nullptr) {};
    ~BST() {root->erase(root); root = nullptr;};
    node<Key, Value>* insert (std::pair<Key, Value> info);
    const Value& getValue (const Key& k) const;
    node<Key, Value> * search (const Key& k) const;
    node<Key, Value>* next (const Key& k);
    node<Key, Value>* minimum () const;
    node<Key, Value> * maximum () const;
    void erase() {root->erase(root); root = nullptr;};
};

template<class Key, class Value>
node<Key, Value>* BST<Key, Value>::insert(std::pair<Key, Value> info) {
    root = root->insert(root, root, info);
    return root->search(root, info.first);
}

template<class Key, class Value>
const Value& BST<Key, Value>::getValue(const Key& k) const {
    node<Key, Value>* tmp = root->search(root, k);
    return tmp->data.second;
}

template<class Key, class Value>
node<Key, Value> * BST<Key, Value>::search(const Key &k) const {
    return root->search(root, k);
}

template<class Key, class Value>
node<Key, Value> *BST<Key, Value>::next(const Key &k) {
    node<Key, Value>* tmp = search(k);
    return tmp->next(tmp);
}

template<class Key, class Value>
node<Key, Value> *BST<Key, Value>::minimum() const{
    return root->minimum(root);
}

template<class Key, class Value>
node<Key, Value> * BST<Key, Value>::maximum() const {
    return root->maximum(root);
}


#endif //TEMPLATE_BST_H
