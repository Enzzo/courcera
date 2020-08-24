#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

std::vector<std::string>SplitIntoWords(const std::string& s) {
    /*
    ������ �������;
    ������ ������� ���� �� ��������� ���� � ��������;
    ������ � ��������� ������� ������ �� �������� ���������;
    ������ �� �������� ���� �������� ������.
    */
    std::vector<std::string> res;
    std::string::const_iterator isb = s.begin();
    std::string::const_iterator ise = s.begin();
    
    while (true) {
        ise = std::find(isb, s.end(), ' ');
        std::string str(isb, ise);
        res.push_back(str);

        if (ise != s.end())isb = ise + 1;
        else break;
    };
    
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