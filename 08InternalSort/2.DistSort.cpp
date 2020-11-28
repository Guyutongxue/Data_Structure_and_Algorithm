#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    int x, y, z;
};

Point p[200];

struct Diff {
private:
    double getDistance() const {
        return std::sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) +
                         (a->z - b->z) * (a->z - b->z));
    }

public:
    const Point* a;
    const Point* b;
    double distance;
    Diff(const Point* a, const Point* b) : a{a}, b{b} {
        distance = getDistance();
    }
    bool operator<(const Diff& a2) const {
        if (distance != a2.distance)
            return distance > a2.distance;
        else if (a != a2.a)
            return a < a2.a;
        else
            return b < a2.b;
    }
};

std::ostream& operator<<(std::ostream& o, const Diff& d) {
    auto x = o.precision();
    o.precision(2);
    o << '(' << d.a->x << ',' << d.a->y << ',' << d.a->z << ")-(" << d.b->x << ',' << d.b->y << ','
      << d.b->z << ")=" << std::fixed << d.distance << std::defaultfloat;
    o.precision(x);
    return o;
}

std::vector<Diff> diff;

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].x >> p[i].y >> p[i].z;
    }
    int j;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            diff.emplace_back(p + i, p + j);
        }
    }
    std::sort(diff.begin(), diff.end());
    for (auto&& i : diff) {
        std::cout << i << std::endl;
    }
}