#include <iostream>
#include <vector>

class Matrix {
public:
	Matrix(const int num_rows = 0, const int num_cols = 0):r(num_rows), c(num_cols){

	}
	void Reset(const int num_rows = 0, const int num_cols = 0){
		matrix.resize(num_rows);
	}
	const int At(const int num_r, const int num_c)const {
	}
	int& At(const int num_r, const int num_c) {

	}
	const int GetNumRows()const {
		return rows.size();
	}
	const int GetNumColumns()const {
		return columns.size();
	}
private:
	std::vector<std::vector<int>>rows;
	std::vector<int> columns;
};

std::istream& operator>>(std::istream& ist, Matrix& m) {
	return ist;
}
std::ostream& operator<<(std::ostream& ost, const Matrix& m) {
	return ost;
}
bool operator==(const Matrix& l, const Matrix& r) {
	return true;
}
Matrix& operator+(const Matrix& l, const Matrix& r) {

}

int main() {

	return 0;
}