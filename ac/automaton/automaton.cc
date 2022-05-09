#include"automaton.h"
#include<queue>
#include<iostream>

automaton::~automaton() {}

// 初始化tire和fail map
automaton::automaton(const std::vector<std::string>& dict) {
    for (auto &s:dict) {
        tree.add(s);
    }
    std::queue<std::shared_ptr<treeNode>>mq;
    auto root = tree.getRoot();
    auto preRoot = std::make_shared<treeNode>(); // 虚拟节点，root的fail
    fail[root] = preRoot;
    mq.push(root);
    while(!mq.empty()) {
        auto pos = mq.front();
        mq.pop();
        for (int i = 0;i < 26;i++) {
            auto ch = pos->child[i];
            if (ch == nullptr) continue;
            auto p = fail[pos];
            while (p != preRoot) {
                if (p->child[i] != nullptr) {
                    fail[ch] = p->child[i];
                    break;
                }
                p = fail[p];
            }
            if (p == preRoot) {
                fail[ch] = root;
            }
            mq.push(ch);
        }
    }
}

std::vector<std::string> automaton::find(const std::string& source){
    std::vector<std::string>res;
    auto root = tree.getRoot();
    auto pos = root;
    int i = 0;
    while (i < source.length()) {
        int idx = source[i] - 'a';
        if (idx < 0 || idx > 26) {
            i++;
            pos = root;
            continue;
        }
        if (pos->child[idx]) {
            if (pos->child[idx]->isEnd) {
                res.push_back(pos->child[idx]->key);
            }
            pos = pos->child[idx];
            i++;
        } else {
            if (pos == root) {
                i++;
            } else {
                pos = fail[pos];
            }
        }
    }
    return res;
}

tireTree automaton::getTree() {
    return this->tree;
}

std::unordered_map<std::shared_ptr<treeNode>, std::shared_ptr<treeNode>> automaton::getFail(){
    return this->fail;
}
