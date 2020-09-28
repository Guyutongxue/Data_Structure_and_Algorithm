#include <iostream>
#include <cmath>
using namespace std;
int len[32000]{};

int getDigit(int i) {
    return (int)log10(i) + 1;
}

int main() {
    int t, n, sum = 0;
    for (int i = 1; sum >= 0; i++) {
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