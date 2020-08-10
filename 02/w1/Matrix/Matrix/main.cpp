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
	const std::vector<std::vector<int>>& GetMatrix() const{
		return matrix;
	}
	void SetMatrix(const std::vector<std::vector<int>>& m) {
		matrix = m;
	}
};

std::istream& operator>>(std::istream& ist, Matrix& mt) try{ 
	std::vector<std::vector<int>> m;
	int r, c;
	ist >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> m[i][j];
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
	if (l.GetMatrix().size() != r.GetMatrix().size() ||
		l.GetMatrix().at(0).size() != r.GetMatrix().at(0).size()) return false;
	for (int i = 0; i < l.GetMatrix().size(); i++) {
		for (int j = 0; j < l.GetMatrix()[i].size(); j++) {
			if (l.GetMatrix()[i][j] != r.GetMatrix()[i][j])return false;
		}
	}
	return true;
}
catch (std::out_of_range) {

}
Matrix& operator+(const Matrix& l, const Matrix& r)try {
	return ;
}
catch (std::out_of_range) {
	
};

int main() {
	return 0;
}