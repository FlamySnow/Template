#ifndef TEMPLATE_NODE_HPP
#define TEMPLATE_NODE_HPP

#include <utility>
#include <iostream>

template <class Key, class Value>
class node {
public:
    std::pair<Key, Value> data;
    node *left, *right;
    //конструкторы
    node(): left(nullptr), right(nullptr) {};
    explicit node(std::pair<Key, Value> info): data(info), left(nullptr), right(nullptr) {};
    //методы
    node<Key, Value>* insert (node<Key, Value>* pNode, std::pair<Key, Value> info);
    void traverse (const node<Key, Value>* pNode) const;
    node<Key, Value>* search(node<Key, Value>* pNode, Key k);
    void erase(node<Key, Value>* pNode);
};

template<class Key, class Value>
node<Key, Value>* node<Key, Value>::insert(node<Key, Value> *pNode, std::pair<Key, Value> info) {
    if (!pNode)
        return new node(info);
    if (info.first > pNode->data.first)
        pNode->right = insert(pNode->right, info);
    else
        pNode->left = insert(pNode->left, info);
    return pNode;
}

template<class Key, class Value>
void node<Key, Value>::traverse(const node<Key, Value> *pNode) const {
    if (!pNode)
        return;
    traverse(pNode->left);
    std::cout << pNode->data.second << " ";
    traverse(pNode->right);
}

template<class Key, class Value>
node<Key, Value>* node<Key, Value>::search(node<Key, Value> *pNode, Key k) {
    if (pNode == nullptr || pNode->data.first == k)
        return pNode;
    if (pNode->data.first < k)
        return search(pNode->right, k);
    return search(pNode->left, k);
}

template<class Key, class Value>
void node<Key, Value>::erase(node<Key, Value> *pNode) {
    if (!pNode)
        return;
    erase(pNode->right);
    erase(pNode->left);
    delete pNode;
}


#endif //TEMPLATE_NODE_HPP