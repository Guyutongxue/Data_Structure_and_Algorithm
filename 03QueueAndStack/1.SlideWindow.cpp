// Luogu P1886

#include <iostream>
#include <deque>

int a[1000010];
std::deque<std::size_t> minQueue;
std::deque<std::size_t> maxQueue;
std::size_t n, k;

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (!minQueue.empty() && i - minQueue.front() >= k) {
            minQueue.pop_front();
        }
        while (!minQueue.empty() && a[minQueue.back()] > a[i]) {
            minQueue.pop_back();
        }
        minQueue.push_back(i);
        if (i >= k) {
            std::cout << a[minQueue.front()] << " ";
        }
    }
    std::cout << std::endl;
    for (int i = 1; i <= n; i++) {
        while (!maxQueue.empty() && i - maxQueue.front() >= k) {
            maxQueue.pop_front();
        }
        while (!maxQueue.empty() && a[maxQueue.back()] < a[i]) {
            maxQueue.pop_back();
        }
        maxQueue.push_back(i);
        if (i >= k) {
            std::cout << a[maxQueue.front()] << " ";
        }
    }
}