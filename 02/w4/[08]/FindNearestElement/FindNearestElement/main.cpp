/*
1 4 4 6 6
1
*/
#include <iostream>
#include <set>
#include <iterator>
#include <math.h>

//Напишите функцию FindNearestElement, для множества целых чисел numbers и данного числа border возвращающую итератор на элемент множества, ближайший к border.
//Если ближайших элементов несколько, верните итератор на наименьший из них.
std::set<int>::const_iterator FindNearestElement(const std::set<int>& n, const int b) {
    
    std::set<int>::const_iterator it = n.lower_bound(b);
    
    if (it == n.end()) {
        if (it != n.begin()) it--;
    }
    else {
        if (abs(*it) > abs(b) && std::prev(it) != n.end() && abs(b) - abs(*std::prev(it)) <= abs(*it) - b)
            it--;
    }

    return it;
}

int main() {
    std::set<int> numbers = {-1, -4, -6 };
    std::cout <<
        *FindNearestElement(numbers, -2) << " " << //1
        *FindNearestElement(numbers, -3) << " " << //4
        *FindNearestElement(numbers, -5) << " " << //4
        *FindNearestElement(numbers, -6) << " " << //6
        *FindNearestElement(numbers, -100) << std::endl;
    
    std::set<int> empty_set;
    std::cout << (FindNearestElement(empty_set, 8) == empty_set.end()) << std::endl;

    return 0;
}