#include <iostream>
#include <string>
#include <set>
#include <map>

int main() {

    int q;
    std::cin >> q;

    std::string request;

    //std::set<std::set<std::string>> line;
    std::map < std::string, std::set<std::string>> dictionary;

    while (q-- > 0) {
        std::cin >> request;
        if (request == "ADD") {
            std::string word1;
            std::string word2;
            std::cin >> word1 >> word2;
            
            dictionary[word1].insert(word2);
            dictionary[word2].insert(word1);
        }
        else if (request == "COUNT") {
            std::string word;
            std::cin >> word;

            std::cout << dictionary[word].size() << std::endl;
        }
        else if (request == "CHECK") {
            std::string word1;
            std::string word2;
            std::cin >> word1 >> word2;

            if (dictionary[word1].count(word2) > 0) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }
	return 0;
}