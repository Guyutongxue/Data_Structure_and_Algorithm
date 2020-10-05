#include <iostream>
#include <queue>
#include <stack>
#include <sstream>

std::ostringstream oss;
std::queue<std::size_t> inList;
std::queue<std::size_t> outList;
std::stack<std::size_t> mainStack;

int main() {
    std::size_t n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        inList.push(i);
    }
    for (int i = 1; i <= n; i++) {
        int value;
        std::cin >> value;
        if (value > n || value < 1) {
            std::cout << "NO" << std::endl;
            std::exit(0);
        }
        outList.push(value);
    }
    while (!outList.empty()) {
        if (mainStack.empty() || mainStack.top() != outList.front()) {
            if (inList.empty()) {
                std::cout << "NO" << std::endl;
                std::exit(0);
            }
            oss << "PUSH " << inList.front() << std::endl;
            mainStack.push(inList.front());
            inList.pop();
        } else {
            oss << "POP " << mainStack.top() << std::endl;
            mainStack.pop();
            outList.pop();
        }
    }
    std::cout << oss.str();
}