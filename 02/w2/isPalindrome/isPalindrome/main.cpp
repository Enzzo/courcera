#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception & e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    return false;
}

void EmptyString() {
    AssertEqual(IsPalindrom(" "), true);
}
void SingleToken() {
    AssertEqual(IsPalindrom("p"), true);
    AssertEqual(IsPalindrom("a"), true);
    AssertEqual(IsPalindrom("f"), true);
    AssertEqual(IsPalindrom("b"), true);
    AssertEqual(IsPalindrom("c"), true);
    AssertEqual(IsPalindrom("d"), true);
}
void WithSpaces() {
    AssertEqual(IsPalindrom("p p"), true);
    AssertEqual(IsPalindrom("p pa"), false);
    AssertEqual(IsPalindrom("pl lp"), true);
    AssertEqual(IsPalindrom("pl p"), false);
    AssertEqual(IsPalindrom("a a"), true);
    AssertEqual(IsPalindrom("d pa"), false);
    AssertEqual(IsPalindrom("pr rp"), true);
    AssertEqual(IsPalindrom("pl f"), false);
}
void Simple() {
    AssertEqual(IsPalindrom("levehl"), false);
    AssertEqual(IsPalindrom("abba"), true);
    AssertEqual(IsPalindrom("abba "), false);
    AssertEqual(IsPalindrom("aa"), true);
}
void Test1(){
    AssertEqual(IsPalindrom("Levehl"), false);
    AssertEqual(IsPalindrom("ABBA"), true);
    AssertEqual(IsPalindrom("ABBA "), false);
    AssertEqual(IsPalindrom(" leveL"), false);
    AssertEqual(IsPalindrom("aA"), false);
    AssertEqual(IsPalindrom("aba"), true);
    AssertEqual(IsPalindrom("abb a "), false);
    AssertEqual(IsPalindrom(" ledel"), false);
	AssertEqual(IsPalindrom("777777"), true);
}
void Test2() {
	AssertEqual(IsPalindrom("<ww>"), false, "dont palindrom 0");
	AssertEqual(IsPalindrom("asdds a"), false, "dont palindrom 1");
	AssertEqual(IsPalindrom("asddsf"), false, "dont palindrom 2");
	AssertEqual(IsPalindrom(".,.."), false, "dont palindrom 3");
	AssertEqual(IsPalindrom("abhfjba"), false, "dont palindrom 4");
	AssertEqual(IsPalindrom("addv"), false, "dont palindrom 5");
	AssertEqual(IsPalindrom("njmn"), false, "dont palindrom 6");
	AssertEqual(IsPalindrom("abssbak"), false, "dont palindrom 7");
	AssertEqual(IsPalindrom("aa "), false, "dont palindrom 8");
	AssertEqual(IsPalindrom("a d"), false, "dont palindrom 9");
	AssertEqual(IsPalindrom("\n "), false, "dont palindrom 10");
	AssertEqual(IsPalindrom("\n\n\n\nd"), false, "dont palindrom 11");
	AssertEqual(IsPalindrom("Vddv"), false, "dont palindrom 12");
	AssertEqual(IsPalindrom("__asa___"), false, "dont palindrom 13");
	AssertEqual(IsPalindrom("aVDa"), false, "dont palindrom 14");
	AssertEqual(IsPalindrom("a s ds a"), false, "dont palindrom 15");
	AssertEqual(IsPalindrom("	dfd		"), false, "dont palindrom 16");
	AssertEqual(IsPalindrom(" asa"), false, "dont palindrom 17");
	AssertEqual(IsPalindrom("a sa"), false, "dont palindrom 18");
	AssertEqual(IsPalindrom("as a"), false, "dont palindrom 19");
	AssertEqual(IsPalindrom("asa "), false, "dont palindrom 20");
	AssertEqual(IsPalindrom("a s ds a"), false, "dont palindrom 15");
	AssertEqual(IsPalindrom("	dfd		"), false, "dont palindrom 16");
	AssertEqual(IsPalindrom(" asa"), false, "dont palindrom 17");
	AssertEqual(IsPalindrom("a sa"), false, "dont palindrom 18");
	AssertEqual(IsPalindrom("as a"), false, "dont palindrom 19");
	AssertEqual(IsPalindrom("   asa"), false, "dont palindrom 20");
	AssertEqual(IsPalindrom("a s ds a"), false, "dont palindrom 15");
	AssertEqual(IsPalindrom("	dfd		"), false, "dont palindrom 16");
	AssertEqual(IsPalindrom(" asa"), false, "dont palindrom 17");
	AssertEqual(IsPalindrom("a sa"), false, "dont palindrom 18");
	AssertEqual(IsPalindrom("as a"), false, "dont palindrom 19");
	AssertEqual(IsPalindrom("a   sa "), false, "dont palindrom 20");
	AssertEqual(IsPalindrom("a   sa "), false, "dont palindrom 21");
	AssertEqual(IsPalindrom("   asa "), false, "dont palindrom 22");
	AssertEqual(IsPalindrom("as   a"), false, "dont palindrom 23");
	AssertEqual(IsPalindrom("a  s   a"), false, "dont palindrom 24");
	AssertEqual(IsPalindrom("a   sa    "), false, "dont palindrom 25");
	AssertEqual(IsPalindrom("advggvda     "), false, "dont palindrom 26");
	AssertEqual(IsPalindrom("advggv d a"), false, "dont palindrom 27");
	AssertEqual(IsPalindrom("advg gv da"), false, "dont palindrom 28");
	AssertEqual(IsPalindrom("advggv d a"), false, "dont palindrom 29");
	AssertEqual(IsPalindrom("ad   vg gv da"), false, "dont palindrom 30");
	AssertEqual(IsPalindrom("adv g gvda"), false, "dont palindrom 31");
	AssertEqual(IsPalindrom("a dvg gv da"), false, "dont palindrom 32");
	AssertEqual(IsPalindrom("adv gg vda "), false, "dont palindrom 33");
	AssertEqual(IsPalindrom("adv g  gv da"), false, "dont palindrom 35");
	AssertEqual(IsPalindrom("adv ggv da"), false, "dont palindrom 36");
	AssertEqual(IsPalindrom("a dvgg vda"), false, "dont palindrom 37");

	AssertEqual(IsPalindrom("q weewq"), false, "dont palindrom 38");
	AssertEqual(IsPalindrom(" qweewq"), false, "dont palindrom 39");
	AssertEqual(IsPalindrom("qw eewq"), false, "dont palindrom 40");
	AssertEqual(IsPalindrom("qwee wq"), false, "dont palindrom 41");
	AssertEqual(IsPalindrom("qweew q"), false, "dont palindrom 42");
	AssertEqual(IsPalindrom("qweewq "), false, "dont palindrom 43");

	AssertEqual(IsPalindrom("q weewq"), false, "dont palindrom 44");
	AssertEqual(IsPalindrom("q w eewq"), false, "dont palindrom 45");
	AssertEqual(IsPalindrom("q we ewq"), false, "dont palindrom 46");
	AssertEqual(IsPalindrom("q wee wq"), false, "dont palindrom 47");
	AssertEqual(IsPalindrom("q  weew q"), false, "dont palindrom 48");
	AssertEqual(IsPalindrom("q weewq "), false, "dont palindrom 49");
	AssertEqual(IsPalindrom("q weew  q"), false, "dont palindrom 50");
	AssertEqual(IsPalindrom("qw eewq"), false, "dont palindrom 51");
	AssertEqual(IsPalindrom("qwee wq"), false, "dont palindrom 52");
	AssertEqual(IsPalindrom("qweew q"), false, "dont palindrom 53");
	AssertEqual(IsPalindrom("qweewq "), false, "dont palindrom 54");
	AssertEqual(IsPalindrom("qw ee   wq"), false, "dont palindrom 55");
	AssertEqual(IsPalindrom("qwe   e wq"), false, "dont palindrom 56");
	AssertEqual(IsPalindrom("  qweew q "), false, "dont palindrom 57");
	AssertEqual(IsPalindrom("fkfk"), false, "dont palindrom 58");
	AssertEqual(IsPalindrom("   fkfk"), false, "dont palindrom 59");
	AssertEqual(IsPalindrom("fkfk "), false, "dont palindrom 60");
	AssertEqual(IsPalindrom("olo" + '\n'), false, "dont palindrom 61");

	AssertEqual(IsPalindrom("AsDDSA"), false, "dont palindrom 62");
	AssertEqual(IsPalindrom("A           fA"), false, "dont palindrom 63");
	AssertEqual(IsPalindrom("A  R A"), false, "dont palindrom 64");
	AssertEqual(IsPalindrom("  b   "), false, "dont palindrom 65");
	AssertEqual(IsPalindrom("bbB"), false, "dont palindrom 66");

	AssertEqual(IsPalindrom("bb  "), false, "dont palindrom 67");
	AssertEqual(IsPalindrom("b b "), false, "dont palindrom 68");
	AssertEqual(IsPalindrom(" b b"), false, "dont palindrom 69");
	AssertEqual(IsPalindrom("  b b "), false, "dont palindrom 670");
	AssertEqual(IsPalindrom("bb   "), false, "dont palindrom 71");
	AssertEqual(IsPalindrom(" b  b"), false, "dont palindrom 72");
	AssertEqual(IsPalindrom(" BB  "), false, "dont palindrom 73");
	AssertEqual(IsPalindrom(" B B  "), false, "dont palindrom 74");
	AssertEqual(IsPalindrom("  ,"), false, "dont palindrom 75");

	AssertEqual(IsPalindrom("asddsa       "), false, "dont palindrom 76");
	AssertEqual(IsPalindrom("asdds       a"), false, "dont palindrom 77");
	AssertEqual(IsPalindrom("  asddsa        "), false, "dont palindrom 79");
	AssertEqual(IsPalindrom("a           sdds   a"), false, "dont palindrom 80");

	AssertEqual(IsPalindrom("a ssss  a"), false, "dont palindrom 80");
	AssertEqual(IsPalindrom("a ssss   a"), false, "dont palindrom 81");
	AssertEqual(IsPalindrom("a ssss    a"), false, "dont palindrom 82");
	AssertEqual(IsPalindrom("a  ssss a"), false, "dont palindrom 83");
	AssertEqual(IsPalindrom("a   ssss a"), false, "dont palindrom 84");
	AssertEqual(IsPalindrom("a    ssss a"), false, "dont palindrom 85");
	AssertEqual(IsPalindrom(" assssa"), false, "dont palindrom 86");
	AssertEqual(IsPalindrom("  assssa"), false, "dont palindrom 87");
	AssertEqual(IsPalindrom("   assssa"), false, "dont palindrom 88");
	AssertEqual(IsPalindrom("   assssa"), false, "dont palindrom 89");
	AssertEqual(IsPalindrom("   assssa "), false, "dont palindrom 90");
	AssertEqual(IsPalindrom("   assssa  "), false, "dont palindrom 91");
	AssertEqual(IsPalindrom("asdfghfdsa"), false, "dont palindrom 92");
	AssertEqual(IsPalindrom("    assssa  "), false, "dont palindrom 93");
	AssertEqual(IsPalindrom("asdfghdsa"), false, "dont palindrom 94");
	AssertEqual(IsPalindrom("zxcvbvgxz"), false, "dont palindrom 95");
	AssertEqual(IsPalindrom("zxcvbvcfz"), false, "dont palindrom 96");
	AssertEqual(IsPalindrom("zxcvbvcxd"), false, "dont palindrom 97");
	AssertEqual(IsPalindrom("zxcdbvcxz"), false, "dont palindrom 98");
	AssertEqual(IsPalindrom("zxdvbvcxz"), false, "dont palindrom 99");
	AssertEqual(IsPalindrom("zdcvbvcxz"), false, "dont palindrom 100");
	AssertEqual(IsPalindrom("axcvbvcxz"), false, "dont palindrom 101");
	AssertEqual(IsPalindrom("zxcvbvcxzn"), false, "dont palindrom 102");
	AssertEqual(IsPalindrom("12343215"), false, "dont palindrom 103");
	AssertEqual(IsPalindrom("12345432"), false, "dont palindrom 104");
	AssertEqual(IsPalindrom("   AsA    "), false, "dont palindrom 105");
	AssertEqual(IsPalindrom("  Asa  "), false, "dont palindrom 106");
	AssertEqual(IsPalindrom("   AsD    "), false, "dont palindrom 107");
	AssertEqual(IsPalindrom("  AsA         "), false, "dont palindrom 108");
	AssertEqual(IsPalindrom("         AsA    "), false, "dont palindrom 109");
	AssertEqual(IsPalindrom("As12sA"), false, "dont palindrom 110");
	AssertEqual(IsPalindrom(" asSa "), false, "dont palindrom 111");
	AssertEqual(IsPalindrom("0000 "), false, "dont palindrom 112");
	AssertEqual(IsPalindrom("0  00 0"), false, "dont palindrom 113");
	AssertEqual(IsPalindrom("   0000 "), false, "dont palindrom 114");
	AssertEqual(IsPalindrom("00   00 "), false, "dont palindrom 115");
	AssertEqual(IsPalindrom(" 0000  "), false, "dont palindrom 116");
	AssertEqual(IsPalindrom("1233214"), false, "dont palindrom 117");
	AssertEqual(IsPalindrom("123321/"), false, "dont palindrom 118");
	AssertEqual(IsPalindrom("123321+"), false, "dont palindrom 119");
	AssertEqual(IsPalindrom("123321A"), false, "dont palindrom 120");
	AssertEqual(IsPalindrom("123321a"), false, "dont palindrom 121");
	AssertEqual(IsPalindrom("123321  "), false, "dont palindrom 122");
	AssertEqual(IsPalindrom("+123321"), false, "dont palindrom 123");
	AssertEqual(IsPalindrom("/123321"), false, "dont palindrom 124");
	AssertEqual(IsPalindrom("4123321"), false, "dont palindrom 125");
	AssertEqual(IsPalindrom(" 123321"), false, "dont palindrom 126");
	AssertEqual(IsPalindrom("A123321"), false, "dont palindrom 127");
	AssertEqual(IsPalindrom("a123321"), false, "dont palindrom 128");
	AssertEqual(IsPalindrom("0030"), false, "dont palindrom 129");
	AssertEqual(IsPalindrom("00+0"), false, "dont palindrom 130");
	AssertEqual(IsPalindrom("0-00"), false, "dont palindrom 131");
	AssertEqual(IsPalindrom("0200"), false, "dont palindrom 132");
	AssertEqual(IsPalindrom("00 0"), false, "dont palindrom 133");
	AssertEqual(IsPalindrom("00D0"), false, "dont palindrom 134");
	AssertEqual(IsPalindrom("0F00"), false, "dont palindrom 135");
	AssertEqual(IsPalindrom("00s0"), false, "dont palindrom 136");
	AssertEqual(IsPalindrom("0d00"), false, "dont palindrom 137");
	AssertEqual(IsPalindrom("0 00"), false, "dont palindrom 138");

	AssertEqual(IsPalindrom("0 0 0 0 "), false, "dont palindrom 139");
	AssertEqual(IsPalindrom(" 00 0 0 "), false, "dont palindrom 140");
	AssertEqual(IsPalindrom(" 0 00 0 "), true, "dont palindrom 141");
	AssertEqual(IsPalindrom(" 0 0 00 "), false, "dont palindrom 142");
	AssertEqual(IsPalindrom(" 0 0 0 0"), false, "dont palindrom 143");

	AssertEqual(IsPalindrom(" 0 0 0 0  "), false, "dont palindrom 144");
	AssertEqual(IsPalindrom(" 0 0 0  0 "), false, "dont palindrom 145");
	AssertEqual(IsPalindrom(" 0 0  0 0 "), true, "dont palindrom 146");
	AssertEqual(IsPalindrom(" 0  0 0 0 "), false, "dont palindrom 147");
	AssertEqual(IsPalindrom("  0 0 0 0 "), false, "dont palindrom 148");

	AssertEqual(IsPalindrom(" 0 0 0  0  "), false, "dont palindrom 149");
	AssertEqual(IsPalindrom(" 0 0  0 0  "), false, "dont palindrom 150");
	AssertEqual(IsPalindrom(" 0  0 0 0  "), false, "dont palindrom 151");
	AssertEqual(IsPalindrom("  0 0 0 0  "), true, "dont palindrom 152");
	AssertEqual(IsPalindrom(" 0 0 0 0   "), false, "dont palindrom 153");
	AssertEqual(IsPalindrom(" 0 0 0   0 "), false, "dont palindrom 154");
	AssertEqual(IsPalindrom(" 0 0 0  0  "), false, "dont palindrom 155");
	AssertEqual(IsPalindrom(" 0 0  0  0 "), false, "dont palindrom 156");
	AssertEqual(IsPalindrom(" 0  0 0  0 "), true, "dont palindrom 157");
	AssertEqual(IsPalindrom("  0 0 0  0 "), false, "dont palindrom 158");
	AssertEqual(IsPalindrom(" 0 0  0 0  "), false, "dont palindrom 159");
	AssertEqual(IsPalindrom(" 0 0  0  0 "), false, "dont palindrom 160");
	AssertEqual(IsPalindrom(" 0 0   0 0 "), true, "dont palindrom 161");
	AssertEqual(IsPalindrom(" 0  0  0 0 "), false, "dont palindrom 162");
	AssertEqual(IsPalindrom("  0 0  0 0 "), false, "dont palindrom 163");

	AssertEqual(IsPalindrom(" 0  0 0 0  "), false, "dont palindrom 164");
	AssertEqual(IsPalindrom(" 0  0 0  0 "), true, "dont palindrom 165");
	AssertEqual(IsPalindrom(" 0  0  0 0 "), false, "dont palindrom 166");
	AssertEqual(IsPalindrom(" 0   0 0 0 "), false, "dont palindrom 167");
	AssertEqual(IsPalindrom("  0  0 0 0 "), false, "dont palindrom 168");
	AssertEqual(IsPalindrom("  0 0 0 0  "), true, "dont palindrom 169");
	AssertEqual(IsPalindrom("  0 0 0  0 "), false, "dont palindrom 170");
	AssertEqual(IsPalindrom("  0 0  0 0 "), false, "dont palindrom 171");
	AssertEqual(IsPalindrom("  0  0 0 0 "), false, "dont palindrom 172");
	AssertEqual(IsPalindrom("   0 0 0 0 "), false, "dont palindrom 173");


		AssertEqual(IsPalindrom(""), true, "Empty string is palindrome");
		AssertEqual(IsPalindrom(" "), true, "Space string is palindrome");
		AssertEqual(IsPalindrom("           "), true, "Space string is palindrome");

		AssertEqual(IsPalindrom("a"), true, "One symbol string is palindrome");
		AssertEqual(IsPalindrom("v"), true, "One symbol string is palindrome");
		AssertEqual(IsPalindrom("1"), true, "One symbol string is palindrome");
		AssertEqual(IsPalindrom("-"), true, "One symbol string is palindrome");
		AssertEqual(IsPalindrom("&"), true, "One symbol string is palindrome");

		AssertEqual(IsPalindrom("level"), true, "This string is a palindrome");
		AssertEqual(IsPalindrom("madam"), true, "This string is a palindrome");
		AssertEqual(IsPalindrom("aba"), true, "This string is a palindrome");
		AssertEqual(IsPalindrom("aaaaaaaaaaaaaaaaaaaaaaaa"), true, "This string is a palindrome");
		AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "This string is a palindrome");

		AssertEqual(IsPalindrom("MaaaaaaaaaaadAsadfsadasdsadsam"), false, "This string is not a palindrome");
		AssertEqual(IsPalindrom("abdgdsgdsgsb"), false, "This string is not a palindrome");
		AssertEqual(IsPalindrom("LEVaFSfasFSADfAFsafel"), false, "This string is not a palindrome");

		AssertEqual(IsPalindrom("leveL"), false, "This string is palindrome because of L and l are different symbols");
		AssertEqual(IsPalindrom("Level"), false, "This string is palindrome because of L and l are different symbols");
		AssertEqual(IsPalindrom("level "), false, "This string is palindrome because of space at the end");
		AssertEqual(IsPalindrom(" level"), false, "This string is palindrome because of space at the end");
		AssertEqual(IsPalindrom(" level "), true, "This string is palindrome because of spaces");
		AssertEqual(IsPalindrom("madaM"), false, "Not a palindrome");

		AssertEqual(IsPalindrom("l e v e l"), true, "Is palindrome");
		AssertEqual(IsPalindrom("l  e  v  e  l"), true, "Is palindrome");
		AssertEqual(IsPalindrom(" lev e  l   "), false, "Is not palindrome");
		AssertEqual(IsPalindrom("mada m"), false, "Is not palindrome");

}
void TestAll() {
    TestRunner r;
    //пустую строку считает палиндромом
    r.RunTest(EmptyString, "EmptyString");
    
    //строка из одного символа - палиндром
    r.RunTest(SingleToken, "SingleToken");

    //строки с пробелами
    r.RunTest(WithSpaces, "WithSpaces");

    r.RunTest(Simple, "SimpleTest");
    r.RunTest(Test1, "Test1");
	r.RunTest(Test2, "Test2");
}

int main() {
    // добавьте сюда свои тесты
    TestAll();
    return 0;
}
