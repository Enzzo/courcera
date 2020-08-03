#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <exception>

class Rational {
public:
    Rational() {
        numerator = 0;
        denominator = 1;
    };

    Rational(long numerator, long denominator) {
        //if (denominator == 0)throw std::invalid_argument("");
        //”простим дробь:
        Format(numerator, denominator);
        this->numerator = numerator;
        this->denominator = denominator;
    };

    long Numerator() const {
        return numerator;
    }

    long Denominator() const {
        return denominator;
    }

    void Update(long n, long d) {
        //”простим дробь:
        Format(n, d);
        this->numerator = n;
        this->denominator = d;
    }

    Rational operator+(const Rational& r) const {
        long d, n;
        if (this->denominator != r.Denominator()) {
            d = this->denominator * r.Denominator();
            n = this->numerator * r.Denominator() + r.Numerator() * this->denominator;
        }
        else {
            d = this->denominator;
            n = this->numerator + r.Numerator();
        }

        //”простим дробь:
        Format(n, d);

        return Rational(n, d);
    }
    Rational operator-(const Rational& r) const {
        long d, n;
        if (this->denominator != r.Denominator()) {
            d = this->denominator * r.Denominator();
            n = this->numerator * r.Denominator() - r.numerator * this->denominator;
        }
        else {
            d = this->denominator;
            n = this->numerator - r.Numerator();
        }

        //”простим дробь:
        Format(n, d);

        return Rational(n, d);
    }
    Rational operator/(const Rational& r) const {
        
        long d, n;
        d = this->denominator * r.Numerator();
        n = this->numerator * r.Denominator();
        if (r.Denominator() == 0) throw std::domain_error("");
        //”простим дробь:
        Format(n, d);

        return Rational(n, d);
    }
    Rational operator*(const Rational& r) const {
        long d, n;

        d = this->denominator * r.Denominator();
        n = this->numerator * r.Numerator();
        
        //”простим дробь:
        Format(n, d);

        return Rational(n, d);
    }
    bool operator==(const Rational& r) const {
        return (this->numerator == r.Numerator() && this->denominator == r.Denominator());    
    }
    bool operator<(const Rational& r)const {
        
        long lv = this->numerator, rv = r.Numerator();

        if (this->denominator != r.Denominator()) {
            int d = this->denominator * r.Denominator();
            lv = this->numerator * r.Denominator();
            rv = r.Numerator() * this->denominator;
        }

        return lv < rv;
    }

private:
    long numerator, denominator;

    //возвращает наибольший общий знаменатель
    //a - числительб b - знаменатель
    long gcd(long a, long b)const {
        a = std::abs(a);
        b = std::abs(b);
        while (a > 0 && b > 0) {
            if (a > b) a %= b;
            else if (b > a) b %= a;
            else break;
        }
        if (a == 0)return b;
        return a;
    }

    //”прощает дробь
    //n - числитель d - знаменатель
    void Format(long& n, long& d) const {

        //наибольший общий делитель
        long g = gcd(n, d);
        short sign = 1;

        //если числитель и знаменатель отрицательные, то знак "минус" убираетс€
        if (n < 0 && d < 0) sign = 1;

        //иначе, если или числитель, или знаменатель отрицательный, то знак переноситс€ к числителю
        else if (n < 0 || d < 0)sign = -1;

        n = std::abs(n / g) * sign;
        d = std::abs(d / g);
    }
    
};

bool BadStream(std::istream& s) {
    if (s.peek() == '/' || s.peek() == ' ') {
        s.ignore(1);
        return false;
    }
    return true;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    long n = 0, d = 1;
    if (!is.eof()) {
        if (!BadStream(is))
            is >> n;
        if (!BadStream(is)) {
            is >> d;
            r.Update(n, d);
        }
    }    
    return is;
}
std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os << r.Numerator() << "/" << r.Denominator();
    return os;
}

int main() {

    std::istringstream inp("f /4 6/4");
    Rational r1, r2;
    inp >> r1 >> r2;
    std::cout << r1 <<" "<<r2<< std::endl;

    std::istringstream inp2("6 /4 6/f");
    Rational r3, r4;
    inp2 >> r3 >> r4;
    std::cout << r3 << " " << r4 << std::endl;
    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "5/7 is incorrectly read as " << r << std::endl;
            return 2;
        }
    }

    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 4;
        }
    }
    return 0;
}