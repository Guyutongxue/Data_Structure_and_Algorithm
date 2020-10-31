#include <iostream>
#include <queue>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, ans{0};
        std::cin >> n;
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for (int i = 1; i <= n; i++) {
            int v;
            std::cin >> v;
            q.push(v);
        }
        while (q.size() != 1) {
            int t1, t2;
            t1 = q.top();
            q.pop();
            t2 = q.top();
            q.pop();
            ans += t1 + t2;
            q.push(t1 + t2);
        }
        std::cout << ans << std::endl;
    }
}
