#include<iostream>
#include<vector>
using namespace std;

typedef struct 
{
    double x;
    double y;
}point;

double nb(const vector<double>&uu, double u, int i, int p) {
    if (p == 0) {
        if (u >= uu[i] && u < uu[i+1]) {
            return 1;
        } else {
            return 0;
        }
    }
    double r1 = 0;
    if (uu[i+p] == uu[i]){
        r1 = 0;
    } else {
        r1 = (u - uu[i]) / (uu[i+p] -uu[i]) * nb(uu, u, i, p-1);
    }

    double r2 = 0;
    if (uu[i+p+1] == uu[i+1]) {
        r2 = 0;
    } else {
        r2 = (uu[i+p+1]-u) / (uu[i+p+1] - uu[i+1]) * nb(uu, u, i+1, p-1);
    }
    return r1 + r2;
}

point ci(const vector<double>&uu, const vector<point>&pos, double u, int i, int p) {
    point res = {0, 0};
    for (int j = i-p;j <= i; j ++) {
        double tmp = nb(uu, u, j, p);
        res.x += tmp * pos[j].x;
        res.y += tmp * pos[j].y;
    }
    return res;
}


int main() {
    vector<point>pos{{1, 1}, {2, 5}, {3, -1}, {4, 10}, {5, -4}, {6, 3}, {7, 1}, {8, 0}};
    vector<double>uu{0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7};
    int p = 3;
    int n = pos.size() - 1;
    
    for(int i = p; i <= n+p-1;i++) {
        for(double u = uu[i]; u < uu[i+1]; u += 0.1) {
            auto r = ci(uu, pos, u, i, p);
            cout << r.x << ", ";
        }
        // cout << endl;
    }
    cout << endl;
    return 0;
}