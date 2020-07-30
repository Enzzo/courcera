#include <iostream>
#include <string>

struct Specialization {
	explicit Specialization(const std::string& s) { str = s; };
	std::string str;
};

struct Course {
	explicit Course(const std::string& s) { str = s; };
	std::string str;
};

struct Week {
	explicit Week(const std::string& s) { str = s; };
	std::string str;
};

struct LectureTitle {
	explicit LectureTitle(Specialization sp, Course cr, Week wk) {
		specialization = sp.str;
		course = cr.str;
		week = wk.str;
	};
	std::string specialization;
	std::string course;
	std::string week;
};

int main() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);

	LectureTitle title("C++", "White belt", "4th");

	LectureTitle title(string("C++"), string("White belt"), string("4th"));

	LectureTitle title = { "C++", "White belt", "4th" };

	LectureTitle title = { {"C++"}, {"White belt"}, {"4th"} };

	LectureTitle title(
		Course("White belt"),
		Specialization("C++"),
		Week("4th")
	);

	LectureTitle title(
		Specialization("C++"),
		Week("4th"),
		Course("White belt")
	);

	return 0;
}

/*
Допишите конструктор и структуры Specialization, Course, Week так, 
чтобы объект LectureTitle можно было создать с помощью кода

LectureTitle title(
	Specialization("C++"),
	Course("White belt"),
	Week("4th")
);
*/