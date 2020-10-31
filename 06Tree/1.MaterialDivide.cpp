#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>

char name[1000][300];

int main() {
    int t;
    std::scanf("%d", &t);
    std::cin.get();
    while (t--) {
        char mubiao[300];
        char tmp[400];
        int cnt = 0;
        while (true) {
            std::cin.getline(tmp, 300);
            std::size_t len = std::strlen(tmp);
            if (len == 0u)
                break;
            tmp[strlen(tmp)] = '\0';
            std::strcpy(name[cnt++], tmp);
        }
        std::cin.getline(mubiao, 300);
        bool isFound = false;
        int pos;
        for (int i = 0; i < cnt; i++) {
            if (!std::strcmp(mubiao, name[i])) {
                isFound = true;
                pos = i;
                break;
            }
        }
        std::stack<char> s;
        if (isFound)
            for (int i = pos + 1; i < cnt; i++) {
                if (s.empty() && name[i][0] == '}') {
                    break;
                } else if (name[i][0] == '{') {
                    s.push(name[i][0]);

                } else if (name[i][0] == '}')
                    s.pop();
                else if (s.empty())
                    std::printf("%s", name[i]);
            }
        else {
            std::printf("No");
        }
        std::printf("\n");
        std::cin.ignore();
        std::cin.ignore();
    }
    std::cin.get();
}