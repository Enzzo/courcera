#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>

class Figure {
public:
    virtual std::string Name()const = 0;
    virtual double Perimeter()const = 0;
    virtual double Area()const = 0;
};

class Rect : public Figure {
public:
    Rect(const double s1, const double s2){
        perimeter = (s1 + s2) * 2;
        area = s1 * s2;
    };
    virtual std::string Name()const override {
        return "RECT";
    }
    virtual double Perimeter()const override {
        return perimeter;
    }
    virtual double Area()const override {
        return area;
    }
private:
    double perimeter;
    double area;
};

class Triangle : public Figure {
public:
    Triangle(const double s1, const double s2, const double s3){
        perimeter = s1 + s2 + s3;
        double p = perimeter / 2;
        area = std::sqrt(p * (p - s1) * (p - s2) * (p - s3));
    }
    virtual std::string Name()const override {
        return "TRIANGLE";
    }
    virtual double Perimeter()const override {
        return perimeter;
    }
    virtual double Area()const override {
        return area;
    }
private:
    double perimeter;
    double area;
};

class Circle : public Figure {
public:
    Circle(const double r){
        const double pi = 3.14;
        perimeter = 2 * pi * r;
        area = pi * r * r;
    }
    virtual std::string Name()const override {
        return "CIRCLE";
    }
    virtual double Perimeter()const override {
        return perimeter;
    }
    virtual double Area()const override {
        return area;
    }
private:
    double perimeter;
    double area;
};
std::shared_ptr<Figure> CreateFigure(std::istream& is) {
    
    std::shared_ptr<Figure> f;
    
    std::string type;
    is >> type;
    is >> std::ws;
    
    std::vector<double> sides;
    std::string s;
    double x;

    while (is >> x) {
        sides.push_back(x);
    }

    if (type == "TRIANGLE") {
        f = std::make_shared<Triangle>(sides[0], sides[1], sides[2]);
    }
    else if (type == "RECT") {
        f = std::make_shared<Rect>(sides[0], sides[1]);
    }
    else if (type == "CIRCLE") {
        f = std::make_shared<Circle>(sides[0]);
    }
    
    return f;
}

int main() {
    ////////////////////////////////////////////////////////////
    std::ifstream ifs("input.txt");
    ////////////////////////////////////////////////////////////
    std::vector<std::shared_ptr<Figure>> figures;
    for (std::string line; std::getline(ifs, line); ) {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "ADD") {
            is >> std::ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                std::cout << std::fixed << std::setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << std::endl;
            }
        }
    }
    return 0;
}