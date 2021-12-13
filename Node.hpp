#ifndef TEMPLATE_NODE_HPP
#define TEMPLATE_NODE_HPP

#include <utility>
#include <iostream>

template <class Key, class Value>
class node {
public:
    std::pair<Key, Value> data;
    node *left, *right, *parent;
    //конструкторы
    node(): left(nullptr), right(nullptr), parent(nullptr) {};
    explicit node(std::pair<Key, Value> info, node<Key, Value>* par): data(info), parent(par), left(nullptr), right(nullptr) {};
    //методы
    node<Key, Value>* insert (node<Key, Value>* pNode, node<Key, Value>* par, std::pair<Key, Value> info);
    void traverse (const node<Key, Value>* pNode) const;
    node<Key, Value>* search(node<Key, Value>* pNode, Key k);
    void erase(node<Key, Value>* pNode);
    node<Key, Value>* next (node<Key, Value>* cur);
    node<Key, Value>* minimum(node<Key, Value>* pNode) const;
    node<Key, Value>* maximum(node<Key, Value>* pNode) const;
};

template<class Key, class Value>
node<Key, Value>* node<Key, Value>::insert(node<Key, Value> *pNode, node<Key, Value>* par, std::pair<Key, Value> info) {
    if (!pNode)
        return new node(info, par);
    if (info.first > pNode->data.first)
        pNode->right = insert(pNode->right, pNode, info);
    else
        pNode->left = insert(pNode->left, pNode, info);
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
    pNode = nullptr;
}

template<class Key, class Value>
node<Key, Value> *node<Key, Value>::next(node<Key, Value>* cur) {
    if (cur->right != nullptr)
        return minimum(cur->right);
    node<Key, Value>* tmp = cur->parent;
    while (tmp != nullptr && cur == tmp->right) {
        cur = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

template<class Key, class Value>
node<Key, Value> *node<Key, Value>::minimum(node<Key, Value> *pNode) const {
    if (pNode == nullptr)
        return pNode;
    if (pNode->left == nullptr)
        return pNode;
    return minimum(pNode->left);
}

template<class Key, class Value>
node<Key, Value> *node<Key, Value>::maximum(node<Key, Value> *pNode) const {
    if (pNode == nullptr)
        return pNode;
    if (pNode->right == nullptr)
        return pNode;
    return maximum(pNode->right);
}

#endif //TEMPLATE_NODE_HPP