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
        if (denominator == 0)throw std::invalid_argument("");
        //Упростим дробь:
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
        //Упростим дробь:
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

        //Упростим дробь:
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

        //Упростим дробь:
        Format(n, d);

        return Rational(n, d);
    }
    Rational operator/(const Rational& r) const {
        
        long d, n;
        d = this->denominator * r.Numerator();
        n = this->numerator * r.Denominator();
        if (r.Denominator() == 0) throw std::domain_error("");
        //Упростим дробь:
        Format(n, d);

        return Rational(n, d);
    }
    Rational operator*(const Rational& r) const {
        long d, n;

        d = this->denominator * r.Denominator();
        n = this->numerator * r.Numerator();
        
        //Упростим дробь:
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

    //Упрощает дробь
    //n - числитель d - знаменатель
    void Format(long& n, long& d) const {

        //наибольший общий делитель
        long g = gcd(n, d);
        short sign = 1;

        //если числитель и знаменатель отрицательные, то знак "минус" убирается
        if (n < 0 && d < 0) sign = 1;

        //иначе, если или числитель, или знаменатель отрицательный, то знак переносится к числителю
        else if (n < 0 || d < 0)sign = -1;

        n = std::abs(n / g) * sign;
        d = std::abs(d / g);
    }
};
////////////////////////////////////////////////////////////////////////////////////
//                              ПЕРВЫЙ ВАРИАНТ
//Пропускает пробелы
//Если косая черта находится между цифрами, то распознаёт их как дробь
//Если хоть с одной стороны косой черты находится не число, то 
//              !!!    воспринимает это, как мусор и ничего в поток не передаёт
/*
std::istream& operator>> (std::istream& is, Rational& r) {
    char input, cd;
    long n = 0, d = 0;
    while (is>>input) {
        if (isspace(input))continue;
        if(isdigit(input)){
            is.unget();
            is >> n;
            if (isalpha(input))continue;
            while(is>>input){
                if (isspace(input))continue;
                if (isdigit(input)) {
                    is.unget(); break;
                }
                if (isalpha(input)) break;
                if (input == '/') {
                    while (is >> input) {
                        if (isspace(input))continue;
                        if (isdigit(input)) {
                            is.unget();
                            is >> d;
                            r.Update(n, d);
                            return is;
                        }
                        if (isalpha(input))return is;
                    }
                }
                else break;
            }
        }
    }
    return is;
}

////////////////////////////////////////////////////////////////////////////////////
//                              ВТОРОЙ ВАРИАНТ
//Пропускает пробелы
//Если косая черта находится между цифрами, то распознаёт их как дробь
//Если хоть с одной стороны косой черты находится не число, то 
//              !!!    возвращает в поток дробь по-умолчанию
std::istream& operator>> (std::istream& is, Rational& r) {
    char input, cd;
    long n = 0, d = 1;
    while (is >> input) {
        if (isspace(input))continue;
        if (isdigit(input)) {
            is.unget();
            is >> n;
        }
        else if (isalpha(input))
            n = 0;

        if (input == '/') {
            while (is >> input) {
                if (isspace(input))continue;
                if (isdigit(input)) {
                    is.unget();
                    is >> d;
                    r.Update(n, d);
                    return is;
                }
                if (isalpha(input)) {
                    r.Update(0, 1);
                    return is;
                }
            }
        }
    }
    return is;
}
*/
////////////////////////////////////////////////////////////////////////////////////
//                              ТРЕТИЙ ВАРИАНТ
// спотыкается на первом "плохом" символе (всё, что не является цифрой, косой чертой или пробелом)
// выдаёт значение по-умолчанию

std::istream& operator>> (std::istream& is, Rational& r) {
    char input;
    long n = 0, d = 1;
    while (is >> input) {
        if (isspace(input))continue;
        if (isdigit(input)) {
            is.unget();
            is >> n;
            continue;
        }
        else if (isalpha(input))
            return is;

        if (input == '/') {
            while (is >> input) {
                if (isspace(input))continue;
                if (isdigit(input)) {
                    is.unget();
                    is >> d;
                    r.Update(n, d);
                    return is;
                }
                if (isalpha(input)) {
                    //r.Update(0, 1);
                    return is;
                }
            }
        }return is;
    }
    return is;
}

std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os << r.Numerator() << "/" << r.Denominator();
    return os;
}

int main() {    
    try {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 1;
    }
    catch (std::invalid_argument&) {

    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 2;
    }
    catch (std::domain_error&) {

    }
    
    std::cout << "OK" << std::endl;
    return 0;
}