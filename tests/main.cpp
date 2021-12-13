#include <iostream>
#include "../Map.h"
#include "gtest/gtest.h"
#include <string>

TEST (Map, Constructor) {
    Map<std::string, int> map;
    ASSERT_EQ(map.size(), 0);
    ASSERT_EQ(map.empty(), true);
}

TEST (Map, IndexOperator) {
    Map<int, int> map;
    map[1] = 3;
    map[2] = 4;
    map[3] = 5;
    ASSERT_EQ(map[1], 3);
    ASSERT_EQ(map[2], 4);
    ASSERT_EQ(map[3], 5);
    map[3] = 6;
    ASSERT_EQ(map[3], 6);
    map[4];
    ASSERT_EQ(map[4], 0);
}

TEST (Map, CIndexOperator) {
    Map<int, int> map;
    const int cint = 5;
    map[5] = 6;
    ASSERT_EQ(map[cint] , 6);
    const int cint2 = 2;
    ASSERT_ANY_THROW(map[cint2] = 7);
}

TEST (Map, Insert) {
    Map<std::string, int> map;
    map.insert(std::make_pair("Murka", 5));
    ASSERT_EQ(map["Murka"], 5);
    map.insert(std::make_pair("Stanislav", 19));
    ASSERT_EQ(map["Stanislav"], 19);
    ASSERT_EQ(map.insert(std::make_pair("Murka", 20)).second, false);
}

TEST (Map, Clear) {
    Map <int, int> map;
    map[1] = 1;
    map[2] = 2;
    map[3] = 3;
    map[4] = -4;
    map.clear();
    ASSERT_EQ(map.empty(), true);
}

TEST (Map, EndBegin) {
    Map <int, int> map;
    map[1] = 1;
    map[2] = 2;
    map[3] = 3;
    for (auto p = map.begin(); p != map.end(); ++p)
        ASSERT_EQ(p->data.second, p->data.first);
}

TEST (Map, Find) {
    Map <int, int> map;
    map[1] = -1;
    map[2] = -2;
    map[3] = -3;
    ASSERT_EQ(map.find(1)->data.second, -1);
    ASSERT_EQ(map.find(2)->data.second, -2);
    ASSERT_EQ(map.find(3)->data.second, -3);
}