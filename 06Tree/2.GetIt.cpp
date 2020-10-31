#include <algorithm>
#include <iostream>

bool relation[100005];
int set[100005];

int getRoot(int x) {
    if (x == set[x])
     return x;
    int father = set[x];
    getRoot(father);
    relation[x] = relation[father] ^ relation[x];
    return set[x] = set[father];
}

void merge(int a, int b) {
    int ra{getRoot(a)};
    int rb{getRoot(b)};
    set[ra] = rb;
    relation[ra] = !(relation[b] ^ relation[a]);
}

int main() {
    int n, m;
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            set[i] = i;
            relation[i] = false;
        }
        while (m--) {
            char cmd;
            int x, y;
            std::cin >> cmd;
            if (cmd == 'D') {
                std::cin >> x >> y;
                merge(y, x);
            } else if (cmd == 'A') {
                std::cin >> x >> y;
                int px = getRoot(x);
                int py = getRoot(y);
                if (px != py) {
                    std::cout << "Not sure yet." << std::endl;
                } else if (relation[x] ==relation[y]) {
                    std::cout << "In the same gang." << std::endl;
                } else {
                    std::cout << "In different gangs." << std::endl;
                }
            }
        }
    }
}