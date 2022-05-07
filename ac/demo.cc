#include<iostream>
#include<vector>
#include"tire/tire.cc"

int main () {
    tireTree t;
    std::vector<std::string>data{"adc", "rng", "uzi", "theshy", "jacklove"};
    for (auto &d:data) {
        t.add(d);
    }
    t.disp();
}