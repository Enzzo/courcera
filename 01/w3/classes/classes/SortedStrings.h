#pragma once
#include <string>
#include <vector>
#include <algorithm>

class SortedStrings{
public: 
	void AddString(const std::string&);
	std::vector<std::string> GetSortedStrings();
private:
	std::vector<std::string> v;
};

void SortedStrings::AddString(const std::string& s) {
	v.push_back(s);
	std::sort(v.begin(), v.end());
}

std::vector<std::string> SortedStrings::GetSortedStrings() {
	return v;
}