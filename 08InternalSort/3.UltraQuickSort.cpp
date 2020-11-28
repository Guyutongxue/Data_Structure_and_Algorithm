#include <iostream>

int s[500020]{};
std::size_t cnt;

void merge(std::size_t l1, std::size_t r1, std::size_t l2, std::size_t r2) {
    static int t[500020]{};
    std::size_t k = 0ull;
    while (l1 <= r1 && l2 <= r2) {
        if (s[l2] < s[l1]) {
            t[++k] = s[l2++];
            cnt += 1ull + r1 - l1;
        } else {
            t[++k] = s[l1++];
        }
    }
    while (l1 <= r1){
        t[++k] = s[l1++];}
    while (l2 <= r2){
        t[++k] = s[l2++];}
    for (std::size_t i = k, j = r2; i >= 1; i--, j--) {
        s[j] = t[i];
    }
}

void mergesort(std::size_t l, std::size_t r) {
    std::size_t mid = (l + r) / 2;
    if (l < r) {
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, mid, mid + 1, r);
    }
}

int main() {
    int n;
    while (std::cin >> n) {
        cnt = 0;
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++) {
            std::cin >> s[i];
        }
        mergesort(1, n);
        std::cout << cnt << std::endl;
    }
}