#include <iostream>
#include <vector>
#include <string>

//принимает отсортированный набор строк в виде итераторов range_begin, range_end и один символ prefix;
//возвращает диапазон строк, начинающихся с символа prefix, в виде пары итераторов.
template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(RandomIt, RandomIt, char);

int main() {
    const std::vector<std::string> sorted_strings = { "moscow", "murmansk", "vologda" };

    const auto m_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        std::cout << *it << " "; 
    }                                                                                       
    std::cout << std::endl;

    const auto p_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'p');
    std::cout << (p_result.first  - sorted_strings.begin()) << " " <<
                 (p_result.second - sorted_strings.begin()) << std::endl;                   //2 2

    const auto z_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'z');
    std::cout << (z_result.first  - sorted_strings.begin()) << " " <<
                 (z_result.second - sorted_strings.begin()) << std::endl;                   //3 3

    const std::vector<std::string> my_strings = { "one", "two", "three", "four" };
    const auto my_result = FindStartsWith(my_strings.begin(), my_strings.end(), 'f');
    std::cout << *my_result.first << " " << my_result.second - my_strings.begin();          //four 

    return 0;
}

template<typename RandomIt>
std::pair<RandomIt, RandomIt>FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    RandomIt i1 = range_begin;
    RandomIt i2;



    return { i1, i2 };
};