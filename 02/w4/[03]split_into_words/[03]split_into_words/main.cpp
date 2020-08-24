#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::vector<std::string>SplitIntoWords(const std::string& s) {
    /*
    строка непуста;
    строка состоит лишь из латинских букв и пробелов;
    первый и последний символы строки не являются пробелами;
    строка не содержит двух пробелов подряд.
    */
    std::vector<std::string> res;
    std::string::const_iterator isb = s.begin();
    std::string::const_iterator ise;
    do{
        ise = std::find(isb, s.end(), ' ');
        if (*ise == ' ') {
            std::string s(isb, ise);
            res.push_back(s);
            isb = ++ise;
        }
        else break;
    }while (ise != s.end());
    return res;
}

int main() {
    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;
	return 0;
}