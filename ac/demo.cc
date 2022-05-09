#include<iostream>
#include<vector>
// #include"tire/tire.h"
#include"automaton/automaton.h"

int main () {
    tireTree t;
    std::vector<std::string>data{"abc", "abe", "cdcd", "ccac", "bbac"};
    automaton ac(data);
    ac.getTree().disp();
    auto mp = ac.getFail();
    for (auto p:mp) {
        std::cout<<p.first<<"\t"<<p.second<<"\t"<<p.first->key<<"\t"<<p.second->key<<std::endl;
    }
    std::cout<<mp.size()<<std::endl;
}