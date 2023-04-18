#include<iostream>
using namespace std;

double uu[] = {0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7};
int p = 3;

double nb(double* uu, double u, int i, int p) {
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

int main() {
    cout << "res:" << endl;
    cout << nb(uu, 3.99999, 3, p) << endl;
    return 0;
}