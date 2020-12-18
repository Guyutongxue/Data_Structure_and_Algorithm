#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
char s[1010][30];
struct Trie {
    Trie* next[26]{};
    int cnt{1};
};
Trie* root;
std::set<Trie*> dymems;

void insert(const char* str) {
    int len = strlen(str);
    Trie* p = root;
    Trie* q;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (!p->next[id]) {
            q = new Trie();
            dymems.insert(q);
            p->next[id] = q;
            p = p->next[id];
        } else {
            p = p->next[id];
            (p->cnt)++;
        }
    }
}
void find(const char* str) {
    int len = strlen(str);
    Trie* p = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        p = p->next[id];
        std::cout << str[i];
        if (p->cnt <= 1)
            return;
    }
}
int main() {
    root = new Trie();
    dymems.insert(root);
    int n = 0;
    while (std::cin >> s[n]) {
        insert(s[n]);
        n++;
    }
    for (int i = 0; i < n; i++) {
        std::cout << s[i] << ' ';
        find(s[i]);
        std::cout << '\n';
    }
    for(auto&& i : dymems) {
        delete i;
    }
}