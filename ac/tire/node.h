#ifndef _UTIL_H
#define _UTIL_H
#include<iostream>
struct treeNode {
    bool isEnd;
    std::shared_ptr<treeNode>child[26];
    char ch;
    std::shared_ptr<treeNode>parent;
    std::string key;
};
#endif