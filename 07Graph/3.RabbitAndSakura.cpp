#include <cstring>
#include <iostream>
#include <map>
#include <stack>

std::int32_t adjacencyMat[100][100];
bool isVisited[10010];
int low[5000];
int path[100010];
int n, m, r;
void dijkstra(int x) {
    memset(isVisited, false, sizeof(isVisited));
    memset(path, 0, sizeof(path));
    for (int i = 1; i <= n; i++) {
        low[i] = 0x3f3f3f3f;
        path[i] = x;
    }
    low[x] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if ((u == -1 || low[j] < low[u]) && !isVisited[j]) {
                u = j;
            }
        }
        isVisited[u] = true;
        for (int k = 1; k <= n; k++) {
            if (!isVisited[k] && low[k] > low[u] + adjacencyMat[u][k]) {
                low[k] = low[u] + adjacencyMat[u][k];
                path[k] = u;
            }
        }
    }
}

int main() {
    while (std::cin >> n) {
        std::map<std::string, int> str2Int;
        std::map<int, std::string> int2Str;
        memset(adjacencyMat, 0x3f, sizeof(adjacencyMat));
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (i == j)
                    adjacencyMat[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            std::string str;
            std::cin >> str;
            str2Int[str] = i;
            int2Str[i] = str;
        }
        std::cin >> m;
        while (m--) {
            int c;
            std::string s1, s2;
            std::cin >> s1 >> s2 >> c;
            adjacencyMat[str2Int[s1]][str2Int[s2]] = adjacencyMat[str2Int[s2]][str2Int[s1]] = c;
        }
        std::cin >> r;
        while (r--) {
            std::string s1, s2;
            std::cin >> s1 >> s2;
            if (s1 == s2) {
                std::cout << s1 << std::endl;
                continue;
            }
            dijkstra(str2Int[s1]);
            int v = 0;
            int keep = str2Int[s2];
            std::stack<int> re;
            while (keep != str2Int[s1]) {
                re.push(keep);
                keep = path[keep];
            }
            re.push(str2Int[s1]);
            while (re.size() > 1) {
                int top = re.top();
                re.pop();
                std::cout << int2Str[top] << "->(" << adjacencyMat[top][re.top()] << ")->";
            }
            std::cout << s2 << std::endl;
        }
    }
}