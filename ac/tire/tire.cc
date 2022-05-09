#include"tire.h"
#include<queue>
#include<iostream>

tireTree::tireTree(){
    root = std::make_shared<treeNode>();
    root->isEnd = false;
    root->ch = '#';
    root->parent = nullptr;
    root->key = "";
}

tireTree::~tireTree(){

}
void tireTree::disp() {
    // BFS
    std::queue<std::shared_ptr<treeNode>>mq;
    mq.push(this->root);
    while (!mq.empty()) {
        int size = mq.size();
        for (int i = 0;i < size;i++) {
            auto node = mq.front();
            mq.pop();
            if (node != nullptr) {
                std::cout<<node->ch<<"|";
                for (auto &a:node->child)mq.push(a);   
            }
        }
        std::cout<<std::endl;
    }
}

bool tireTree::add(const std::string&str) {
    auto pos = root;
    std::string prefix;
    for (auto &s:str) {
        int idx = int(s) - int('a');
        if (idx < 0 || idx > 26) {
            return false;
        }
        prefix.push_back(s);
        if (pos->child[idx] == nullptr) {
            pos->child[idx] = std::make_shared<treeNode>();
            pos->child[idx]->isEnd = false;
            pos->child[idx]->ch = s;
            pos->child[idx]->parent = pos;
            pos->child[idx]->key = prefix;
        }
        pos = pos->child[idx];
    }
    pos->isEnd = true;
    return true;
}

std::shared_ptr<treeNode> tireTree::findByPrefix(const std::string&str) {
    auto pos = root;
    for (auto &s:str) {
        int idx = int(s) - int('a');
        if (idx < 0 || idx > 26) {
            return nullptr;
        }
        if (pos->child[idx] == nullptr) {
            return nullptr;
        }
        pos = pos->child[idx];
    }
    return pos;
}

std::shared_ptr<treeNode> tireTree::find(const std::string&str) {
    auto node = this->findByPrefix(str);
    if (node == nullptr || !node->isEnd){
        return nullptr;
    }
    return node;
}

bool tireTree::inTree(const std::string&str) {
    return this->find(str) != nullptr;
}

std::shared_ptr<treeNode> tireTree::getRoot() {
    return this->root;
}