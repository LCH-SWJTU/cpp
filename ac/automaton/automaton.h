#ifndef _AUTOMATON_H
#define _AUTOMATON_H
#include<vector>
#include <memory>
#include<unordered_map>
#include"../tire/tire.h"
class automaton {
    private:
    tireTree tree;
    std::unordered_map<std::shared_ptr<treeNode>, std::shared_ptr<treeNode>>fail;
    public:
    automaton(const std::vector<std::string>& dict);
    ~automaton();
    std::vector<std::string> find(const std::string& source);
    tireTree getTree();
    std::unordered_map<std::shared_ptr<treeNode>, std::shared_ptr<treeNode>> getFail();
};
#endif
