#include<iostream>
#include<vector>
// #include"tire/tire.h"
#include"automaton/automaton.h"

int main () {
    tireTree t;
    std::vector<std::string>data{"abc", "abe", "cdcd", "ccac", "bbac", "ab", "ef"};
    automaton ac(data);
    auto res = ac.find("rabcdef gcdc dd cdcd dddd");

    for (auto r:res) {
        std::cout<<r<<std::endl;
    }
}
