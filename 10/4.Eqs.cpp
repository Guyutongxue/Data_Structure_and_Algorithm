// POJ 1840

#include <iostream>
int a[10];
int p[105];
int s[5];
constexpr const int M{12500000};
short y[25000005];
int main() {
    std::ios::sync_with_stdio(false);
    for (int i = -50; i <= 50; i++) {
        p[i + 50] = i * i * i;
    }
    for (int i = 1; i <= 5; i++) {
        std::cin >> a[i];
    }
    a[4] *= -1;
    a[5] *= -1;
    for (int i = -50; i <= 50; i++) {
        if (i == 0)
            continue;
        s[1] = a[4] * p[i + 50];
        for (int j = -50; j <= 50; j++) {
            if (j == 0)
                continue;
            int ans = s[1] + a[5] * p[j + 50];
            y[ans + M]++;
        }
    }
    int ans = 0;
    for (int i = -50; i <= 50; i++) {
        if (i == 0)
            continue;
        s[1] = a[1] * p[i + 50];
        for (int j = -50; j <= 50; j++) {
            if (j == 0)
                continue;
            s[2] = s[1] + a[2] * p[j + 50];
            for (int k = -50; k <= 50; k++) {
                if (k == 0)
                    continue;
                int x = s[2] + a[3] * p[k + 50];
                if (x >= -M && x <= M) {
                    ans += y[x + M];
                }
            }
        }
    }
    std::cout << ans << std::endl;
}