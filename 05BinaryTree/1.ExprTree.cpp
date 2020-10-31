#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>

char buf[70][300];
std::map<char, int> m;

struct Node {
    char data;
    Node* left;
    Node* right;
};

std::size_t getLayers(Node* root) {
    if (!root)
        return 0u;
    return std::max(getLayers(root->left), getLayers(root->right)) + 1;
}

void printTree(Node* root, int x, int y, std::size_t spaceNum) {
    if (!root)
        return;
    buf[y][x - 1] = root->data;
    if (root->left) {
        buf[y + 1][x - 2] = '/';
        printTree(root->left, x - spaceNum, y + 2, spaceNum >> 1);
    }
    if (root->right) {
        buf[y + 1][x] = '\\';
        printTree(root->right, x + spaceNum, y + 2, spaceNum >> 1);
    }
}

int calculate(Node* r) {
    switch (r->data) {
        case '+': return calculate(r->left) + calculate(r->right);
        case '-': return calculate(r->left) - calculate(r->right);
        case '*': return calculate(r->left) * calculate(r->right);
        case '/': return calculate(r->left) / calculate(r->right);
        default: return m[r->data];
    }
}

std::string getSuffixExpr(const std::string& infixExpr) {
    std::string result;
    std::stack<char> s;
    for (auto&& i : infixExpr) {
        if (isalpha(i))
            result += i;
        else if (i == '(')
            s.push(i);
        else if (i == ')') {
            while (s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        } else if (i == '+' || i == '-') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.push(i);
        } else {
            while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                result += s.top();
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    std::string infixExpr;
    std::cin >> infixExpr;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        char var;
        int val;
        std::cin >> var >> val;
        m[var] = val;
    }
    std::string suffixExpr = getSuffixExpr(infixExpr);
    std::cout << suffixExpr << std::endl;
    Node* root;
    std::stack<Node*> s;
    for (auto&& i : suffixExpr) {
        root = new Node{i, nullptr, nullptr};
        if (!std::isalpha(i)) {
            root->right = s.top();
            s.pop();
            root->left = s.top();
            s.pop();
        }
        s.push(root);
    }
    memset(buf, ' ', sizeof(buf));
    std::size_t n = getLayers(root);
    printTree(root, 1 << (n - 1), 0, 1 << (n - 2));
    int lines = 0;
    for (int i = 0; i < 70; i++) {
        int j = 69;
        while (j >= 0 && buf[i][j] == ' ')
            j--;
        if (j > -1) {
            lines++;
            buf[i][j + 1] = '\0';
        }
    }
    for (int i = 0; i < lines; ++i) {
        std::cout << buf[i] << std::endl;
    }
    std::cout << calculate(root) << std::endl;
}