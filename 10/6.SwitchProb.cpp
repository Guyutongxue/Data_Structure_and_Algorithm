#include <algorithm>
#include <cstring>
#include <iostream>
unsigned length;
bool a[50][50];
int ans[50];

void gauss() {
    int k = 0;
    for (int col = 0; k < length && col < length; k++, col++) {
        int i = k;
        while (i < length && !a[i][col])
            i++;
        if (!a[i][col]) {
            k--;
            continue;
        }
        if (i > k) {
            for (int r = col; r <= length; r++) {
                std::swap(a[i][r], a[k][r]);
            }
        }
        for (i = k + 1; i < length; i++) {
            if (a[i][col]) {
                for (int j = col; j <= length; j++) {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for (int i = k; i < length; i++) {
        if (a[i][length]) {
            std::cout << "Oh,it's impossible~!!\n";
            return;
        }
    }
    std::cout << (1 << (length - k)) << '\n';
}

int main() {
    int i, t;
    std::cin >> t;
    while (t--) {
        std::memset(a, false, sizeof(a));
        std::cin >> length;
        for (i = 0; i < length; i++) {
            std::cin >> a[i][length];
            a[i][i] = true;
        }
        int x;
        for (i = 0; i < length; i++) {
            std::cin >> x;
            a[i][length] = a[i][length] ^ x;
        }
        int m, n;
        while (std::cin >> m >> n) {
            if (m + n == 0)
                break;
            a[n - 1][m - 1] = true;
        }
        gauss();
    }
}