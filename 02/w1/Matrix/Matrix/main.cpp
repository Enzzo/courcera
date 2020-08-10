/*
	�������� ����� �� ������ istream; ������ ����� ������� � ������� ������� ���������� ����� � �������� (������ � ���� �������), 
	� ����� ��� �������� �������: ������� ������� ������ ������ � ������� �������, ����� ������� ������ ������ � ������� ������� � ��� �����

	�������� ������ � ����� ostream; �� ������ �������� ������� � ��� �� �������, � ����� � ������ �������� �����, � � ������ ������ ���������� ����� � ��������, 
	�� ������ � �������� ������ ������, � ������� � �������� ������ ������ � �.�.
	
	�������� �������� �� ��������� (==): �� ������ ���������� true, ���� ������������ ������� ����� ���������� ������ � ��� �� ��������������� �������� ����� ����� �����, 
	� ��������� ������ �� ������ ���������� false.
	
	�������� ��������: �� ������ ��������� ��� ������� � ���������� ����� �������, ������� �������� �� ������; 
	���� ���������� ������� ����� ������ ������� ���� �������� ������ ����������� ����������� ���������� invalid_argument.

������� � ���� ����� ��� ���� �������� ��������� �������. ����� ��� ������ ������� �����. ����� ���� ������ ������ ����� �������� ������ ��������.*/

#include <iostream>
#include <vector>
#include <fstream>

class Matrix {
private:
	std::vector<std::vector<int>>matrix;
	
public:
	
	//����������� �� ���������, ������� ������ ������� � ���� ����� � ���� ��������
	//����������� �� ���� ������������� ���������� : num_rows � num_cols, � ������� ������ ���������� ����� � �������� ������� ��������������
	Matrix(const int num_rows = 0, const int num_cols = 0){
		Reset(num_rows, num_cols);
	}

	//����� Reset, ����������� ��� ������������� ���������, ������� ������ ����� ���������� ����� � �������� ������� ��������������; 
	//����� Reset ������ ������� ������� �� �������� � �������� ��� � ��������
	void Reset(const int num_rows = 0, const int num_cols = 0){

		//���� ���������� ����� ��� ���������� ��������, ���������� � ����������� ������ Matrix ��� ����� Reset, ��������� �������������, 
		//�� ������ ���� ��������� ����������� ���������� out_of_range.
		if (num_rows < 0 || num_cols < 0) throw std::out_of_range("");
		
		matrix.resize(num_rows);
		for (std::vector<int> c : matrix) {
			c.resize(num_cols, 0);
		}
	}

	//����������� ����� At, ������� ��������� ����� ������ � ����� �������(������ � ���� �������; ��������� ����� � �������� ���������� � ����) � ���������� �������� � �������������� ������ �������
	const int At(const int num_r, const int num_c)const try {
		if (num_r < 0 || num_r > matrix.size() ||
			num_c < 0 || num_c > matrix.at(0).size()) throw std::out_of_range("");
		return matrix.at(num_r).at(num_c);
	}
	catch (std::out_of_range e) {

	}

	//������������� ����� At � ������ �� �����������, �� ������������ ������ �� �������� � �������������� ������ �������
	int& At(const int num_r, const int num_c) try{
		return matrix.at(num_r).at(num_c);
	}
	catch (std::out_of_range e) {
		
	}

	//����������� ������ GetNumRows � GetNumColumns, ������� ���������� ���������� ����� � �������� ������� ��������������
	const int GetNumRows()const {
		return matrix.size();
	}
	const int GetNumColumns()const {
		if (matrix.size() > 0)
			return matrix[0].size();
		return 0;
	}
	const std::vector<std::vector<int>>& GetMatrix() const{
		return matrix;
	}
	void SetMatrix(const std::vector<std::vector<int>>& m) {
		matrix = m;
	}
};

std::istream& operator>>(std::istream& ist, Matrix& mt) try{ 
	int r, c, x;
	ist >> r >> c;

	std::vector<std::vector<int>> m(r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ist >> x;
			m[i].push_back(x);
		}
	}
	mt.SetMatrix(m);
	return ist;
}
catch (std::out_of_range) {

}

std::ostream& operator<<(std::ostream& ost, const Matrix& m) try{
	for (const std::vector<int>& vi : m.GetMatrix()) {
		for (const int i : vi)
			ost << i<<" ";
		ost << std::endl;
	}
	return ost;
}
catch (std::out_of_range) {

}
bool operator==(const Matrix& l, const Matrix& r) try{
	if (l.GetNumRows() != r.GetNumRows() ||
		l.GetNumColumns() != r.GetNumColumns()) return false;

	for (int i = 0; i < l.GetNumRows(); i++) {
		for (int j = 0; j < l.GetNumColumns(); j++) {
			if (l.GetMatrix()[i][j] != r.GetMatrix()[i][j])return false;
		}
	}
	return true;
}
catch (std::out_of_range) {

}
Matrix& operator+(const Matrix& l, const Matrix& r)try {
	if (l.GetNumRows() != r.GetNumRows() ||
		l.GetNumColumns() != r.GetNumColumns()) throw std::invalid_argument("");
	
	std::vector<std::vector<int>>m(l.GetNumRows());
	for (int i = 0; i < l.GetNumRows(); i++) {
		for (int j = 0; j < l.GetNumColumns(); j++) {
			m[i].push_back(l.GetMatrix()[i][j] + r.GetMatrix()[i][j]);
		}
	}
	Matrix mt;
	mt.SetMatrix(m);
	return mt;
}
catch (std::out_of_range) {
	
}

int main()try {

	std::ifstream ifs("input.txt");
	Matrix a, b, c;
	while (ifs >> a >> b) {
		c = a + b;
		std::cout << c << std::endl;
	}
	
	return 0;
}
catch (std::invalid_argument) {

}
catch (std::out_of_range) {

}
catch (...) {

}