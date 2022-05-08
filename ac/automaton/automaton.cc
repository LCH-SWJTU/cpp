#include"automaton.h"
#include<queue>
#include<iostream>


automaton::~automaton() {

}

// 初始化tire和fail map
automaton::automaton(const std::vector<std::string>& dict) {
    for (auto &s:dict) {
        tree.add(s);
    }

    std::queue<std::shared_ptr<treeNode>>mq;
    auto root = tree.getRoot();
    fail[root] = root;
    mq.push(root);
    while(!mq.empty()) {
        auto pos = mq.front();
        mq.pop();
        for (int i = 0;i < 26;i++) {
            auto ch = pos->child[i];
            if (ch == nullptr) continue;
            if (fail[pos] == root) {
                fail[ch] = root; //第一层fail都指向root
            } else {
                auto p = fail[pos];
                bool sign = false;
                while (p != root) {
                    if (p->child[i] != nullptr) {
                        sign = true;
                        break;
                    }
                    p = fail[p];
                }
                if (sign) {
                    fail[ch] = p->child[i];
                } else {
                    fail[ch] = root;
                }
            }
            mq.push(ch);
        }
    }
}

tireTree automaton::getTree() {
    return this->tree;
}

std::unordered_map<std::shared_ptr<treeNode>, std::shared_ptr<treeNode>> automaton::getFail(){
    return this->fail;
}
