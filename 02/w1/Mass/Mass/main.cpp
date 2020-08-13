#include <iostream>

int main() {

	std::istream& is = std::cin;
	
	//inputs:
	int n;			//0 - 10^5
	int r;			//0 - 100
	int w, h, d;	//0 - 10^4
	
	//outputs:
	int V;			//0 - 10^12
	int M = 0;		//0 - 10^19 это суммарный объём

	is >> n >> r;

	for (size_t i = 0; i < n; i++) {
		is >> w >> h >> d;
		V = w * h * d;
		M += V;
	}

	return 0;
}