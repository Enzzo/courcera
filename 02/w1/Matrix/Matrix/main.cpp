/*
	оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов (именно в этом порядке), 
	а затем все элементы матрицы: сначала элемент первой строки и первого столбца, затем элемент первой строки и второго столбца и так далее

	оператор вывода в поток ostream; он должен выводить матрицу в том же формате, в каком её читает оператор ввода, — в первой строке количество строк и столбцов, 
	во второй — элементы первой строки, в третьей — элементы второй строки и т.д.
	
	оператор проверки на равенство (==): он должен возвращать true, если сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы равны между собой, 
	в противном случае он должен возвращать false.
	
	оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой; 
	если переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.

Матрицы с нулём строк или нулём столбцов считаются пустыми. Любые две пустые матрицы равны. Сумма двух пустых матриц также является пустой матрицей.*/

#include <iostream>
#include <vector>

class Matrix {
private:
	std::vector<std::vector<int>>matrix;
	
public:

	//конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
	//конструктор от двух целочисленных параметров : num_rows и num_cols, — которые задают количество строк и столбцов матрицы соответственно
	Matrix(const int num_rows = 0, const int num_cols = 0){
		Reset(num_rows, num_cols);
	}

	//метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно; 
	//метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
	void Reset(const int num_rows = 0, const int num_cols = 0){

		//Если количество строк или количество столбцов, переданное в конструктор класса Matrix или метод Reset, оказалось отрицательным, 
		//то должно быть выброшено стандартное исключение out_of_range.
		if (num_rows < 0 || num_cols < 0) throw std::out_of_range("");
		
		matrix.resize(num_rows);
		for (std::vector<int> c : matrix) {
			c.resize(num_cols, 0);
		}
	}

	//константный метод At, который принимает номер строки и номер столбца(именно в этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
	const int At(const int num_r, const int num_c)const try {
		if (num_r < 0 || num_r > matrix.size() ||
			num_c < 0 || num_c > matrix.at(0).size()) throw std::out_of_range("");
		return matrix.at(num_r).at(num_c);
	}
	catch (std::out_of_range e) {

	}

	//неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
	int& At(const int num_r, const int num_c) try{
		return matrix.at(num_r).at(num_c);
	}
	catch (std::out_of_range e) {
		
	}

	//константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно
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