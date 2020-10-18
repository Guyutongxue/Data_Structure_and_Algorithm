#include <iostream>
#include <regex>
#include <string>

std::string ans[52];

int main() {
    int n;
    std::cin >> n;
    for (int i{1}; i <= n; i++) {
        std::cin >> ans[i];
    }
    std::string pattern;
    std::cin >> pattern;
    std::regex reg(pattern, std::regex_constants::icase);
    for (int i = 1; i <= n; i++) {
        if (std::regex_match(ans[i], reg)) {
            std::cout << i << " " << ans[i] << std::endl;
        }
    }
}