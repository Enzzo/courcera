#include <iostream>
#include <map>
#include <exception>



template<typename Key, typename Value>
Value& GetRefStrict(const std::map<Key, Value>& m, const Key& k) try{
	return m.at(k);
}
catch (std::runtime_error) {

};

int main() {
	std::map<std::string, int> m = { {"first", 1}, {"second", 2} };
	std::cout << GetRefStrict<std::string, int>(m, "first");
	return 0;
}