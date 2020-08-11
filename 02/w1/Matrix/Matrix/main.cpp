#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

class Matrix {
private:
	std::vector<std::vector<int>>matrix;
	
public:
	
	//конструктор по умолчанию, который создаЄт матрицу с нулЄм строк и нулЄм столбцов
	//конструктор от двух целочисленных параметров : num_rows и num_cols, Ч которые задают количество строк и столбцов матрицы соответственно
	Matrix(const int num_rows = 0, const int num_cols = 0){
		Reset(num_rows, num_cols);
	}

	//метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно; 
	//метод Reset мен€ет размеры матрицы на заданные и обнул€ет все еЄ элементы
	void Reset(int num_rows = 0, int num_cols = 0){

		//≈сли количество строк или количество столбцов, переданное в конструктор класса Matrix или метод Reset, оказалось отрицательным, 
		//то должно быть выброшено стандартное исключение out_of_range.
		if (num_rows < 0) throw std::out_of_range("rows value less than 0");
		if (num_cols < 0) throw std::out_of_range("columts value less than 0");
		if (num_rows == 0 || num_cols == 0)num_rows = num_cols = 0;

		matrix.assign(num_rows, std::vector<int>(num_cols, 0));
	}

	//константный метод At, который принимает номер строки и номер столбца(именно в этом пор€дке; нумераци€ строк и столбцов начинаетс€ с нул€) и возвращает значение в соответствущей €чейке матрицы
	const int At(const int num_r, const int num_c)const{
		return matrix.at(num_r).at(num_c);
	}

	//неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей €чейке матрицы
	int& At(const int num_r, const int num_c){
		return matrix.at(num_r).at(num_c);
	}

	//константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно
	const int GetNumRows()const {
		return matrix.size();
	}
	const int GetNumColumns()const {
		int c = 0;
		if (matrix.size() > 0)
			c = matrix.at(0).size();
		return c;
	}
	const std::vector<std::vector<int>>& GetMatrix() const{
		return matrix;
	}
	void SetMatrix(const std::vector<std::vector<int>>& m) {
		matrix = m;
	}
};

std::istream& operator>>(std::istream& ist, Matrix& mt) { 
	int r, c, x;
	ist >> r >> c;
	if (r < 0 || c < 0) throw std::out_of_range("");
	std::vector<std::vector<int>> m(r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			ist >> x;
			m.at(i).push_back(x);
		}
	}
	mt.SetMatrix(m);
	return ist;
}

std::ostream& operator<<(std::ostream& ost, const Matrix& m){
	ost << m.GetNumRows() << " " << m.GetNumColumns() << std::endl;
	for (const std::vector<int>& vi : m.GetMatrix()) {
		for (const int i : vi)
			ost << i<<" ";
		ost << std::endl;
	}
	return ost;
}
bool operator==(const Matrix& l, const Matrix& r){
	if (l.GetNumRows() != r.GetNumRows() ||
		l.GetNumColumns() != r.GetNumColumns()) return false;

	for (int i = 0; i < l.GetNumRows(); i++) {
		for (int j = 0; j < l.GetNumColumns(); j++) {
			if (l.GetMatrix().at(i).at(j) != r.GetMatrix().at(i).at(j))return false;
		}
	}
	return true;
}

Matrix operator+(const Matrix& l, const Matrix& r){
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

int main(){

	//std::ifstream ifs("input.txt");
	Matrix one;
	Matrix two;
	//ifs >> one >> two;
	std::cin >> one >> two;
	std::cout << one + two << std::endl;
	
	return 0;
}