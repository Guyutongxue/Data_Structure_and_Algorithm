#include <algorithm>
#include <iostream>
#include <string>

std::string s;
int k, r1, r2;

void dfs(int d1, int d2) {
    r1 = std::max(r1, d1);
    r2 = std::max(r2, d2);
    int cnt = 1;
    while (k < s.length()) {
        if (s.at(k) == 'd') {
            k++;
            dfs(d1 + 1, d2 + cnt);
            cnt++;
        } else {
            k++;
            break;
        }
    }
}

int main() {
    int n = 1;
    while (std::cin >> s, s != "#") {
        r1 = r2 = -1;
        k = 0;
        dfs(0, 0);
        std::cout <<"Tree " << n++ <<": " << r1 << " => " << r2 << std::endl;
    }
}