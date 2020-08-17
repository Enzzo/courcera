#include <iostream>
#include <vector>
#include <map>
#include <utility>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vt);

template<typename L, typename R>
std::ostream& operator<<(std::ostream& os, const std::pair<L, R>& p);

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, const std::map<Key, Value>& m);

template<typename T>
std::vector<T> operator*(const std::vector<T>& l, const std::vector<T>& r);

template<typename L, typename R>
std::pair<L, R> operator*(const std::pair<L, R>& l, const std::pair<L, R>& r);

template<typename Key, typename Value>
std::map<Key, Value> operator*(const std::map<Key, Value>& l, const std::map<Key, Value>& r);

template<typename T>
T Sqr(const T& t) {
	return t * t;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vt) {
	bool first = true;
	for (const T& i : vt) {
		if (!first) os << ' ';
		os << i;
		first = false;
	}
	return os;
}

template<typename L, typename R>
std::ostream& operator<<(std::ostream& os, const std::pair<L, R>& p){	
	return os << p.first<< ' ' << p.second;	
}

template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os, const std::map<Key, Value>& m) {
	bool first = true;
	for (const std::pair<Key, Value>& p : m) {
		if (!first)std::cout << std::endl;
		os << p.first << ' ' << p.second;
		first = false;
	}
	return os;
}
////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
std::vector<T> operator*(const std::vector<T>& l, const std::vector<T>& r) {
	std::vector<T> v;
	for (size_t i = 0; i < l.size(); i++) {
		v.push_back(l[i] * r[i]);
	}
	return v;
}

template<typename L, typename R>
std::pair<L, R> operator*(const std::pair<L, R>& l, const std::pair<L, R>& r) {
	return std::make_pair(l.first * r.first, l.second * r.second);
}

template<typename Key, typename Value>
std::map<Key, Value> operator*(const std::map<Key, Value>& l, const std::map<Key, Value>& r) {
	std::map<Key, Value> m;
	for (const std::pair<Key, Value> p : l) {
		m[p.first] = l.at(p.first) * r.at(p.first);
	}
	return m;
}