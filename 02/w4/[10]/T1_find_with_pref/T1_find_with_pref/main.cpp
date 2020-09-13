#include <iostream>
#include <vector>
#include <string>

//принимает отсортированный набор строк в виде итераторов range_begin, range_end и один символ prefix;
//возвращает диапазон строк, начинающихся с символа prefix, в виде пары итераторов.
template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt, RandomIt, const char);

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt, RandomIt, const std::string&);

bool string_part(const std::string&, const std::string&);

int main() {

    /*
    const std::vector<std::string> sorted_strings = { "moscow", "murmansk", "vologda" };

    const auto m_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'm');
    std::cout << *m_result.first << " "<<*m_result.second << std::endl;
    const auto p_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'p');
    std::cout << (p_result.first  - sorted_strings.begin()) << " " <<
                 (p_result.second - sorted_strings.begin()) << std::endl;                   //2 2

    const auto z_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'z');
    std::cout << (z_result.first  - sorted_strings.begin()) << " " <<
                 (z_result.second - sorted_strings.begin()) << std::endl;                   //3 3

    const std::vector<std::string> my_strings = { "four", "one", "three", "two" };
    const auto my_result = FindStartsWith(my_strings.begin(), my_strings.end(), 't');
    std::cout << *my_result.first << " " << *my_result.second;          //four 
    */

    const std::vector<std::string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

    const auto mo_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    const auto mt_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
        (mt_result.second - begin(sorted_strings)) << std::endl;

    const auto na_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    std::cout << (na_result.first - begin(sorted_strings)) << " " <<
        (na_result.second - begin(sorted_strings)) << std::endl;

    return 0;
}

template<typename RandomIt>
std::pair<RandomIt, RandomIt>FindStartsWith(RandomIt range_begin, RandomIt range_end, const char prefix) {

    //ИЩЕМ LOWER_BOUND
    RandomIt i1 = std::lower_bound(range_begin, range_end, prefix, [](const std::string& it, const char& v) {
        return it[0] < v;
        });
    RandomIt i2 = i1;
    //СВЕРЯЕМ, ЧТОБЫ НУЛЕВОЙ ЭЛЕМЕНТ ИТЕРАТОРА БЫЛ РАВЕН ПРЕФИКСУ
    if (i1 != range_end) {
        if (!i1->empty())
            if ((*i1)[0] == prefix)
                i2++;
    }
    return { i1, i2 };
};

template<typename RandomIt>
std::pair<RandomIt, RandomIt>FindStartsWith(RandomIt range_begin, RandomIt range_end, const std::string& prefix) {
    //ИЩЕМ LOWER_BOUND
    RandomIt i1 = std::lower_bound(range_begin, range_end, prefix, [](const std::string& it, const std::string& v) {
        std::string s = it;
        return !string_part(s, v);
        });
    RandomIt i2 = i1;
    //СВЕРЯЕМ, ЧТОБЫ НУЛЕВОЙ ЭЛЕМЕНТ ИТЕРАТОРА БЫЛ РАВЕН ПРЕФИКСУ
    if (i1 != range_end) {
        if (!i1->empty()) {
            std::string s = *i1;
            if (string_part(s, prefix))
                i2++;
        }
    }
    return { i1, i2 };
}

bool string_part(const std::string& line, const std::string& part) {
    if (line.empty() || part.empty()) return false;
    if (part.size() > line.size()) return false;
    
    for (size_t i = 0; i < part.size(); i++) {
        if (line[i] != part[i]) return false;
    }
    return true;
}