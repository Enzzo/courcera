#include <iostream>
#include <string>
#include <algorithm>

class ReversibleString {
public:
	ReversibleString() {
		str = "";
	};

	ReversibleString(std::string s): str(s) {};

	void Reverse() {
		std::reverse(str.end(), str.begin());
	};

	std::string ToString() const {
		return str;
	};
private:
	std::string str;
};

int main() {
	ReversibleString r("evil");
	std::cout << r.ToString() << "\n";
	r.Reverse();
	std::cout << r.ToString() << "\n";
	ReversibleString evli;
	std::cout << evli.ToString() << "\n";
	return 0;
}