#include <iostream>
#include <string>
/*
variant 1
int main() {
	int x;
	int y; 
	char op;
	std::string result;
	unsigned short N;
	std::cin >> x >> N;
	result = std::to_string(x);

	while (N-- > 0) {
		std::cin >> op >> y;
		result = "(" + result + ") "+op+" "+std::to_string(y);
		std::cout << result;
	}

	return 0;
}
*/

//variant 2
int main() {
	int x;
	int y;
	char prev = ' ';
	char op;
	std::string result;
	unsigned short N;
	std::cin >> x >> N;
	result = std::to_string(x);

	while (N-- > 0) {
		std::string l = "";
		std::string r = "";
		std::cin >> op >> y;
		switch (op) {
		case '*':
		case '/':
			if (prev == '+' || prev == '-') {
				l = "(";
				r = ")";
			}
		}			

		result = l + result + r +" "+ op + " " + std::to_string(y);
		std::cout << result;
		prev = op;
	}
	return 0;
}

/*
8
3 //(три операции)
* 3
- 6
/ 1
*/