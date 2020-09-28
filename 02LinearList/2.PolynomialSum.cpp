#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        std::map<int, int, std::greater<int>> m;
        int c, e;
        while (std::cin >> c >> e, e >= 0) {
            auto it = m.find(e);
            if (it == m.end()) {
                m.insert({e, c});
            } else {
                it->second += c;
            }
        }
        while (std::cin >> c >> e, e >= 0) {
            auto it = m.find(e);
            if (it == m.end()) {
                m.insert({e, c});
            } else {
                it->second += c;
            }
        }
        bool isFirst = true;
        for (auto&& i : m) {
            if (i.second == 0)
                continue;
            std::cout << " [ " + isFirst << i.second << " " << i.first << " ]";
            isFirst = false;
        }
        std::cout << std::endl;
    }
}