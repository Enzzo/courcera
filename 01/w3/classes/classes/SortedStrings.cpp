#include "SortedStrings.h"

void SortedStrings::AddString(const std::string& s) {
	v.push_back(s);
	std::sort(v.begin(), v.end());
}

std::vector<std::string> SortedStrings::GetSortedStrings() {
	return v;
}