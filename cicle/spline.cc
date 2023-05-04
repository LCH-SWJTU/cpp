#include<iostream>
#include<vector>
typedef struct 
{
    double x;
    double y;
}point;

double nb(const std::vector<double>&uu, double u, int i, int p) {
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

point ci(const std::vector<double>&uu, const std::vector<point>&pos, double u, int i, int p) {
    point res = {0, 0};
    for (int j = i-p;j <= i; j ++) {
        double tmp = nb(uu, u, j, p);
        res.x += tmp * pos[j].x;
        res.y += tmp * pos[j].y;
    }
    return res;
}

static void getSplinePoint(const std::vector<point>& splinePointList, std::vector<point>& res) {
	int p = 3;
	// std::vector<double>uu{ 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7 };
	int n = splinePointList.size() - 1;
    std::vector<double>uu;
    for (int i = 0; i <= p; i ++) uu.push_back(0);
    for (int i = 1; i <= n - 1; i ++) uu.push_back(i);
    for (int i = 0; i <= p; i ++) uu.push_back(n);
    // for (auto a : uu) std::cout << a << std::endl;
	for (int i = p; i <= n + p - 1; i ++) {
		for (double u = uu[i]; u < uu[i + 1]; u += 0.5) {
			auto currPoint = ci(uu, splinePointList, u, i, p);
			res.push_back(currPoint);
		}
	}
}

int main() {
    std::vector<point>pos{ {100, 100}, {200, 500}, {300, 100}, {400, 100}, {500, 400}, {600, 300}, {700, 100}, {800, 200}};
    std::vector<point>res;
    getSplinePoint(pos, res);
    for (auto &r : res) {
    	std::cout << r.x << ", " << r.y << std::endl;
    } 
	return 0;
}
