#include <algorithm>
#include <iostream>
#include <string>
int n, m;
std::string file[1003][103];
std::string tmp;
int num[1005];
int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num[i];
        for (int j = 0; j < num[i]; j++) {
            std::cin >> file[i][j];
        }
    }
    std::cin >> m;
    while (m--) {
        std::cin >> tmp;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < num[i]; j++) {
                if (file[i][j] == tmp) {
                    std::cout << i + 1 << ' ';
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
            std::cout << "NOT FOUND";
        std::cout << std::endl;
    }
}