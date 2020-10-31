#include <iostream>
#include <vector>

std::vector<int> tree;

void dfs(std::size_t x, std::size_t y, std::size_t r) {
    if (x == y)
        return;
    std::size_t j;
    for (j = x; j <= y; j++) {
        if (tree[j] == tree[r]) {
            break;
        }
    }
    if (x < j) {
        std::size_t left = r - y + j - 1;
        std::cout << " " << tree[left];
        dfs(x, j - 1, left);
    }
    if (j < y) {
        std::size_t right = r - 1;
        std::cout << " " << tree[right];
        dfs(j + 1, y, right);
    }
}

int main() {
    for (int i; std::cin >> i;) {
        tree.push_back(i);
    }
    std::cout << tree.back();
    dfs(0, tree.size() / 2 - 1, tree.size() - 1);
}