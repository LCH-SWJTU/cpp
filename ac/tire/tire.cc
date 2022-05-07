#include<iostream>
#include<vector>
struct treeNode {
    bool isEnd;
    std::shared_ptr<treeNode> child[26];
    int value;
};

class tireTree{
    private:
    /* data */
    std::shared_ptr<treeNode>root;
    public:
    tireTree();
    ~tireTree();
    void disp();
    bool add(const std::string&str, int val);
    std::shared_ptr<treeNode> find(std::string);
    bool inTree(const std::string&str);
    std::shared_ptr<treeNode> findByPrefix(const std::string&prefix);
    std::shared_ptr<treeNode> getRoot();
};
tireTree::tireTree(){
    root = std::make_shared<treeNode>();
    root->isEnd = false;
    root->value = -1;
}

tireTree::~tireTree(){

}
void tireTree::disp() {
    std::cout<<root->value<<std::endl;
}

bool tireTree::add(const std::string&str, int val) {
    std::shared_ptr<treeNode>pos = root;
    for (auto &s:str) {
        int idx = int(s) - int('a');
        if (idx < 0 || idx > 26) {
            return false;
        }
        if (pos->child[idx] == nullptr) {
            pos->child[idx] = std::make_shared<treeNode>();
            pos->child[idx]->isEnd = false;
            pos->child[idx]->value = -1;
        }
        pos = pos->child[idx];
    }
    pos->isEnd = true;
    pos->value = val;
    return true;
}
