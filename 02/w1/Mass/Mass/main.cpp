#include <iostream>
#include <limits>

int main() {

	std::istream& is = std::cin;
	
	//inputs:
	unsigned int n;			//0 - 10^5
	unsigned short r = 0;	//0 - 100
	unsigned int w, h, d;	//0 - 10^4
	
	//outputs:
	uint64_t V;				//0 - 10^12
	uint64_t M = 0;			//0 - 10^19 это суммарный объём


	is >> n >> r;

	for (size_t i = 0; i < n; i++) {
		is >> w >> h >> d;
		V = static_cast<uint64_t>(w) * static_cast<uint64_t>(h) * static_cast<uint64_t>(d);
		M += static_cast<uint64_t>(r) * V;
	}

	std::cout << M << std::endl;

	return 0;
}