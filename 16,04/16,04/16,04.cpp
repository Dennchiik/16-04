#include <iostream>
#include <string>

class Animal {
public:
    virtual void speak() const = 0;
};

class Frog : public Animal {
public:
    void speak() const override {
        std::cout << "Ribbit!" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }

    void scratch(bool homeworkDone) const {
        if (homeworkDone) {
            std::cout << "Cat doesn't scratch because homework is done." << std::endl;
        }
        else {
            std::cout << "Cat scratches!" << std::endl;
        }
        std::cout << "Cat purrs!" << std::endl;
    }
};

int main() {
    const int numAnimals = 3;
    Animal* animals[numAnimals] = { new Frog(), new Dog(), new Cat() };

    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->speak();
    }

    Cat* cat = dynamic_cast<Cat*>(animals[2]);
    if (cat) {
        cat->scratch(false);
    }
    else {
        std::cout << "Error: Failed to cast to Cat." << std::endl;
    }

    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}
