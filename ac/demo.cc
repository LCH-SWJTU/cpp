#include<iostream>
#include<vector>
// #include"tire/tire.h"
#include"automaton/automaton.h"
using namespace std;

int main () {
    tireTree t;
    std::vector<std::string>data{"adc", "rng", "uzi", "theshy", "jacklove"};
    automaton ac(data);
    ac.getTree().disp();
}