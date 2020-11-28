
#include <algorithm>
#include <iostream>

struct Node {
    int id, a, b;
    bool operator<(const Node& b) const {
        return a > b.a;
    }
};
Node p[50005];
int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].a >> p[i].b;
        p[i].id = i;
    }
    std::sort(p + 1, p + n + 1);
    int num = 0, id = p[1].id;
    for (int i = 1; i <= k; i++) {
        if (num < p[i].b) {
            num = p[i].b;
            id = p[i].id;
        }
    }
    std::cout << id << std::endl;
}