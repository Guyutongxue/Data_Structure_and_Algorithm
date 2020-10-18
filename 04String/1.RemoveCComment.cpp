#include <iostream>
#include <tuple>

int main() {
    for (char c; std::cin.get(c);) {
        if (c == '/') {
            char s{static_cast<char>(std::cin.get())};
            if (s == '*') {
                for (char m{static_cast<char>(std::cin.get())},
                     n{static_cast<char>(std::cin.get())};
                     m != '*' || n != '/';) {
                    std::tie(m, n) = std::make_tuple(n, std::cin.get());
                }
            } else {
                std::cout.put(c);
                std::cout.put(s);
            }
        } else if (c == '\'' || c == '"') {
            std::cout.put(c);
            char s;
            while ((s = std::cin.get()) != c) {
                std::cout.put(s);
                if (s == '\\')
                    std::cout.put(std::cin.get());
            }
            std::cout.put(s);
        } else {
            std::cout.put(c);
        }
    }
}