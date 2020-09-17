#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class Figure {
public:
    virtual std::string Name()const = 0;
    virtual double Perimeter()const = 0;
    virtual double Area()const = 0;
};

class Rect : public Figure {
public:
    Rect(const double s1, const double s2) : perimeter((s1 + s2)*2) , area(s1 * s2) {};
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
    const double perimeter;
    const double area;
};

class Triangle : public Figure {
public:
    Triangle(const double s1, const double s2, const double s3) : perimeter(s1 + s2 + s3), ;
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
    const double perimeter;
    const double area;
};
std::shared_ptr<Figure> CreateFigure(std::istream& is) {
    
    std::shared_ptr<Figure> f = std::make_shared<Rect> (2, 3);

    return f;
}

int main() {
    std::vector<std::shared_ptr<Figure>> figures;
    for (std::string line; std::getline(std::cin, line); ) {
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