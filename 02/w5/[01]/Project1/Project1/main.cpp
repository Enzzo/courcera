#include <iostream>
#include <string>

class Animal {
public:
    // ваш код
    Animal(const std::string& name) : Name(name) {};
    const std::string Name;
};


class Dog : public Animal {
public:
    // ваш код
    Dog(const std::string& name) : Animal(name) {};

    void Bark() {
        std::cout << Name << " barks: woof!" << std::endl;
    }
};

int main() {
    Dog d("ddd");
    d.Bark();
	return 0;
}