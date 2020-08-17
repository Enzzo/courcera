#include <iostream>
#include <map>
#include <exception>


template<typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, const Key& k) try{
	return m.at(k);
}
catch (std::out_of_range) {
	throw std::runtime_error("");
}
catch (std::runtime_error) {

}
catch (...) {

}

int main() {
	/*
	std::map<std::string, int> m = { {"first", 1}, {"second", 2} };
	std::cout << GetRefStrict<std::string, int>(m, "first");
	*/

	std::map<int, std::string> m = { {0, "value"} };
	std::string& item = GetRefStrict(m, 1);
	item = "newvalue";
	std::cout << m[0] << std::endl; // выведет newvalue

	return 0;
}