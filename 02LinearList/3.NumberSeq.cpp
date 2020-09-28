#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
int len[32000]{};

int getDigit(int i) {
    return (int)log10(i) + 1;
}

constexpr int MAX = numeric_limits<int>::max();

int main() {
    int t, n;
    unsigned sum = 0u;
    for (int i = 1; sum <= MAX; i++) {
        len[i] = len[i - 1] + getDigit(i);
        sum += len[i];
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; len[i] < n; i++) {
            n -= len[i];
        }
        int i = 1;
        for (; getDigit(i) < n; i++) {
            n -= getDigit(i);
        }
        while(int p = getDigit(i) - n) {
            p--;
            i /= 10;
        }
        cout << i % 10 << endl;
    }
}