#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <exception>

class Rational {
public:
    Rational(long numerator = 0, long denominator = 1) {
        if (denominator == 0) {
            //std::cout << "invalid argument\n";
            throw std::invalid_argument("");
        }
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
        if (r.Numerator() == 0) {
            //std::cout << "invalid argument\n";
            throw std::domain_error("");
        }
        long d, n;
        d = this->denominator * r.Numerator();
        n = this->numerator * r.Denominator();

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

        //если числитель и знаменатель отрицательные, то знак "минус" убираетс¤
        if (n < 0 && d < 0) sign = 1;

        //иначе, если или числитель, или знаменатель отрицательный, то знак переноситс¤ к числителю
        else if (n < 0 || d < 0)sign = -1;

        n = std::abs(n / g) * sign;
        d = std::abs(d / g);
    }

};

bool operator==(const Rational& l, const Rational& r) {
    return (l.Numerator() == r.Numerator() && l.Denominator() == r.Denominator());
}
bool operator!=(const Rational& l, const Rational& r){
    return !(l == r);
}

class TesterFramework {
public:
    template<typename Function>
    void RunTest(Function f, const std::string& test_name) try {
        f();
        std::cerr << test_name << " OK" << std::endl;
    }
    catch (std::runtime_error e) {
        std::cerr << test_name << " fail: " << e.what() << std::endl;
        error_count++;
    }
    catch (...) {
        error_count++;
    }
    ~TesterFramework() {
        if (error_count > 0) {
            std::cerr << "ERROR COUNT: " << error_count << " \nPROGRAM TERMINATED\n";
            std::exit(1);
        }
    }
public:
    size_t error_count = 0;
};


template<typename T, typename U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
    if (t != u) {
        std::ostringstream os;
        //os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty())
            os << " hint: " << hint;
        throw std::runtime_error(os.str());
    }
}


void SkipSpaces(std::istream& is) {
    if (is.peek() == ' ')is.ignore(1);
}

std::istream& operator>>(std::istream& is, Rational& r) {
    long n = 0, d = 1;

    SkipSpaces(is);
    if (is >> n) {
        SkipSpaces(is);
        if (is.peek() == '/') {
            is.ignore(1);
            SkipSpaces(is);
            if (is >> d)
                r.Update(n, d);
        }
    }

    return is;
}
std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os << r.Numerator() << "/" << r.Denominator();
    return os;
}

void DefaultConstructor() {
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}
void Decrease() {
    Rational r(2, 4);
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 2);
}
void NegativeNumerator() {
    Rational r(-2, 4);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 2);
}
void NegativeDenumerator() {
    Rational r(2, -4);
    AssertEqual(r.Numerator(), -1);
    AssertEqual(r.Denominator(), 2);
}
void NegativeFraction() {
    Rational r(-3, -6);
    AssertEqual(r.Numerator(), 1);
    AssertEqual(r.Denominator(), 2);
}
void ZeroNumerator() {
    Rational r(0, 25);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestAll() {
    TesterFramework t;
    //конструктор по умолчанию
    t.RunTest(DefaultConstructor, "DefaultConstructor");

    //сокрщение дроби
    t.RunTest(Decrease, "Decrease");
    
    //отрицательный числитель
    t.RunTest(NegativeNumerator, "NegativeNumerator");

    //отрицательный знаменатель
    t.RunTest(NegativeDenumerator, "NegativeDenumerator");

    //отрицательный числитель и знаменатель
    t.RunTest(NegativeFraction, "NegativeFraction");
    
    //нулевой числитель
    t.RunTest(ZeroNumerator, "ZeroNumerator");
}

int main(){

    TestAll();

    return 0;
}