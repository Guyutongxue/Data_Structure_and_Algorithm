#include <algorithm>
#include <iostream>
struct Edge {
    int x, y, w;
    bool operator<(const Edge& b) const {
        return w < b.w;
    }
};
Edge e[80];
int parent[30]{};
int n, m{0};
int sum{0};
int getRoot(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = getRoot(parent[i]);
}
void kruskal() {
    int fx, fy, cnt = 1;
    for (int i = 0; i < m && cnt < n; i++) {
        fx = getRoot(e[i].x);
        fy = getRoot(e[i].y);
        if (fx != fy) {
            parent[fx] = fy;
            sum += e[i].w;
            cnt++;
        }
    }
}
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        char xc, yc;
        int edge, w;
        std::cin >> xc >> edge;
        for (int j = 0; j < edge; j++) {
            std::cin >> yc >> w;
            e[m++] = {i, yc - 'A', w};
        }
    }
    std::sort(e, e + m);
    kruskal();
    std::cout << sum << std::endl;
}