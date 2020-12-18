#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

bool similar(const std::string& longStr, const std::string& shortStr) {
    std::size_t shortLen = shortStr.size();
    for (std::size_t i = 0; i < shortLen; i++) {
        if (longStr[i] != shortStr[i]) {
            if (shortStr.substr(0, i) + longStr[i] + shortStr.substr(i) == longStr) {
                return true;
            }
        }
    }
    return shortStr + longStr.back() == longStr;
}
int main() {
    std::vector<std::string> dictionary;
    std::string word;
    std::string dic;
    bool flag = false;
    int sub = 0;

    while (std::cin >> dic, dic != "#") {
        dictionary.push_back(dic);
    }
    while (std::cin >> word, word != "#") {
        if (std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end()) {
            std::cout << word << " is correct" << std::endl;
            continue;
        }
        std::cout << word << ":";
        for (const auto& i : dictionary) {
            sub = i.length() - word.length();
            if (sub == 0) {
                auto p = std::mismatch(i.begin(), i.end(), word.begin());
                if (std::equal(p.first + 1, i.end(), p.second + 1)) {
                    std::cout << " " << i;
                }
            } else if (std::abs(sub) == 1) {
                if (i.length() < word.length()) {
                    if (similar(word, i)) {
                        std::cout << " " << i;
                    }
                } else {
                    if (similar(i, word)) {
                        std::cout << " " << i;
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}
