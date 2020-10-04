#include <iostream>
#include <cstring>

int num[1000010]{};
bool used[1000010]{};
bool put[1000010]{};

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num[i];
        // out-of-range or duplicated
        if (num[i] > n || num[i] <= 0 || used[num[i]]) {
            std::cout << "NO" << std::endl;
            std::exit(0);
        }
        used[num[i]] = true;
    }
    std::memset(used, 0, sizeof(used));

    for (int i = 0; i < n; i++) {
        int m1 = num[i], m2 = num[i];
        for (int j = i + 1; j < n; ++j) {
            if (num[j] < m2) {
                m2 = num[j];
            } else if (num[j] < m1) {
                std::cout << "NO" << std::endl;
                std::exit(0);
            }
        }
    }
    int cur{0};
    for (int i = 0; i < n; i++) {
        if (cur < num[i]) {
            for (int j = cur + 1; j < num[i]; j++) {
                if (!used[j]) {
                    if (!put[j]) {
                        std::cout << "PUSH " << j << std::endl;
                        put[j] = true;
                    }
                    cur = j;
                }
            }
            used[num[i]] = true;
            if (!put[num[i]]) {
                std::cout << "PUSH " << num[i] << std::endl;
                put[num[i]] = true;
            }
            std::cout << "POP " << num[i] << std::endl;
        } else if (cur == num[i]) {
            used[cur] = true;
            if (!put[num[i]]) {
                std::cout << "PUSH " << num[i] << std::endl;
                put[num[i]] = true;
            }
            std::cout << "POP " << num[i] << std::endl;
            for (int j = cur; j >= 0; j--) {
                if (!used[j])
                    cur = j;
            }
        }
    }
}