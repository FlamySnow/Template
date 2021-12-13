//
// Created by flamy on 07/12/21.
//
#include "Map.h"
#include <string>

int main () {
    Map<std::string, int> map;
    int a = 0;
    std::string s;
    int v;
    do {
        std::cout << "0. Quit." << std::endl;
        std::cout << "1. Insert." << std::endl;
        std::cout << "2. Search." << std::endl;
        std::cout << "Enter a value: ";
        std::cin >> a;
        switch (a) {
            case 1: {
                std::cout << "Enter string: ";
                std::cin >> s;
                std::cout << "Enter number: ";
                std::cin >> v;
                map.insert(std::make_pair(s, v));
            }
            break;
            case 2: {
                std::cout << "Enter string: ";
                std::cin >> s;
                std::cout << map.find(s)->data.second << std::endl;
            }
            break;
            case 0:
                break;
            default:
                std::cout << "Enter 0, 1 or 2!" << std::endl;
        }
    } while (a != 0);
}