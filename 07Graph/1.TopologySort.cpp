#include <iostream>
#include <cstring>
bool adjacencyMat[105][105];
int inDegree[105];
int main() {
    int n, m;
    std::cin >> n >> m;
    memset(adjacencyMat, 0, sizeof(adjacencyMat));
    memset(inDegree, 0, sizeof(inDegree));
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        adjacencyMat[a][b] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adjacencyMat[i][j]) {
                inDegree[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int item = 0;
        for (int j = 1; j <= n; j++) {
            if (inDegree[j] == 0) {
                item = j;
                break;
            }
        }
        std::cout << "v" << item << " \n"[i == n];
        inDegree[item] = -1;
        for (int j = 1; j <= n; j++) {
            if (adjacencyMat[item][j]) {
                inDegree[j]--;
            }
        }
    }
}