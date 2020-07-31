#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

class Rational {
public:
    Rational(){
        numerator = 0;
        denominator = 1;
    };

    Rational(int numerator, int denominator) {
        short sign = 1;
        if (numerator < 0 && denominator < 0)sign = 1;
        else if (numerator < 0 || denominator < 0)sign = -1;
        
        this->numerator = std::abs(numerator / gcd(numerator, denominator)) * sign;
        this->denominator = std::abs(denominator / gcd(numerator, denominator));
    };

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    Rational& operator+(const Rational& r) {

    }
    Rational& operator-(const Rational& r) {

    }
    bool operator==(const Rational& r) {
        return (numerator == r.numerator && denominator == r.denominator);
    }

private:
    int numerator, denominator;
    int gcd(int a, int b) const {
        if (a < 0) a *= (-1);
        if (b < 0) b *= (-1);
        return a ? gcd(((a > b) ? a : b) %= ((a > b) ? b : a), (a > b) ? b : a) : b;
    }
};



int main() {
    
    cout << "OK" << endl;
    return 0;
}
