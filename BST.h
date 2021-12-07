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
    ~BST() {root->erase(root);};
    node<Key, Value>* insert (std::pair<Key, Value> info);
    const Value& getValue (const Key& k) const;
    node<Key, Value>* search (const Key& k);
};

template<class Key, class Value>
node<Key, Value>* BST<Key, Value>::insert(std::pair<Key, Value> info) {
    root = root->insert(root, info);
    return root;
}

template<class Key, class Value>
const Value& BST<Key, Value>::getValue(const Key& k) const {
    node<Key, Value>* tmp = root->search(root, k);
    return tmp->data.second;
}

template<class Key, class Value>
node<Key, Value> *BST<Key, Value>::search(const Key &k) {
    return root->search(k);
}


#endif //TEMPLATE_BST_H
