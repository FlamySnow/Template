//
// Created by flamy on 07/12/21.
//

#include "BST.h"
#include <string>

int main () {
    BST<std::string, int> tree;
    tree.insert(std::make_pair("aaaaa", 1));
    tree.insert(std::make_pair("aa", 2));
    tree.insert(std::make_pair("aaaa", 3));
    tree.insert(std::make_pair("b", 4));
    tree.insert(std::make_pair("c", 5));
    tree.insert(std::make_pair("cccc", 6));
    return 0;
}