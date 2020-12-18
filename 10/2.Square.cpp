#include <iostream>
#include <stack>

constexpr const unsigned PRIME{21911u};
constexpr const unsigned OUTOFRANGE{999999};

struct Point {
    int x;
    int y;
};

struct HashTable {
    int x;
    int y;
    HashTable* next;
};

Point p[1005];
HashTable ht[PRIME];

void buildList(int n) {
    for (auto& i : ht) {
        i = {OUTOFRANGE, OUTOFRANGE, nullptr};
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        p[i] = {x, y};
        unsigned key = (x * x + y * y) % PRIME;
        HashTable* pt = ht + key;
        while (pt->next) {
            pt = pt->next;
        }
        *pt = {x, y, new HashTable{OUTOFRANGE, OUTOFRANGE, nullptr}};
    }
}

bool isExist(int x, int y) {
    unsigned key = (x * x + y * y) % PRIME;
    HashTable* pt = ht + key;

    while (pt) {
        if ((pt->x == x) && (pt->y == y))
            return true;
        pt = pt->next;
    }
    return false;
}

void destroyList() {
    std::stack<HashTable*> recycle;
    for (auto& i : ht) {
        HashTable* pt = &i;
        while (pt->next) {
            recycle.push(pt);
            pt = pt->next;
        }
        while (!recycle.empty()) {
            pt = recycle.top();
            delete pt->next;
            recycle.pop();
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    while (true) {
        int n, cnt;
        std::cin >> n;
        if (n == 0)
            break;
        cnt = 0;
        buildList(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = p[i].x;
                int y1 = p[i].y;
                int x2 = p[j].x;
                int y2 = p[j].y;
                int dx = x1 - x2;
                int dy = y1 - y2;
                if (isExist(x1 + dy, y1 - dx) && isExist(x2 + dy, y2 - dx)) {
                    cnt++;
                }
                if (isExist(x1 - dy, y1 + dx) && isExist(x2 - dy, y2 + dx)) {
                    cnt++;
                }
            }
        }
        std::cout << cnt / 4 << '\n';
        destroyList();
    }
}