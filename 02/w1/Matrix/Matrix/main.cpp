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
	std::vector<std::vector<int>>& GetMatrix() {
		return matrix;
	}
};

std::istream& operator>>(std::istream& ist, const Matrix& m) {
	m.
	for(const std::vector<int>& v : m.GetMatrix()){}
	return ist;
}
std::ostream& operator<<(std::ostream& ost, const Matrix& m) {
	return ost;
}
bool operator==(const Matrix& l, const Matrix& r) {
	return true;
}
Matrix& operator+(const Matrix& l, const Matrix& r) {
	return ;
};

int main() {
	return 0;
}