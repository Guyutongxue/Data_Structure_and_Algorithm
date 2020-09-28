#include <iostream>
using namespace std;

int n;
int matrix[52][52]{};

int stepX(int x) {
    return x == n ? 1 : x + 1;
}

int stepY(int y) {
    return y == 1 ? n : y - 1;
}

void next(int& x,int& y) {
    int nx = stepX(x);
    int ny = stepY(y);
    if (matrix[nx][ny]) {
        y++;
    } else {
        x = nx;
        y = ny;
    }
}

int main() {
    cin >> n;
    int x = n;
    int y = 1;
    (n *= 2) -= 1;
    for (int i = 1; i <= n * n; i++) {
        matrix[x][y] = i;
        next(x, y);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[j][i] << " \n"[j == n];
        }
    }
}