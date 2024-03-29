#ifndef _TIRE_H
#define _TIRE_H
#include<vector>
#include"node.h"
class tireTree{
    private:
    std::shared_ptr<treeNode>root;
    public:
    tireTree();
    ~tireTree();
    void disp();
    bool add(const std::string&str);
    std::shared_ptr<treeNode> find(const std::string&str);
    bool inTree(const std::string&str);
    std::shared_ptr<treeNode> findByPrefix(const std::string&prefix);
    std::shared_ptr<treeNode> getRoot();
};
#endif
