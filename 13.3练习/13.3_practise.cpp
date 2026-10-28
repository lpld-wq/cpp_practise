#include <iostream>
#include <string_view> // C++17

enum class Animal
{
	duck,
	chicken,
	goat,
	cat,
	dog,
    pig,
};

std::string_view getAnimalName(Animal animal)
{
	switch (animal)
	{
    case Animal::chicken:
        return "chicken";
    case Animal::duck:
        return "duck";
    case Animal::pig:
        return "pig";
    case Animal::goat:
        return "goat";
    case Animal::cat:
        return "cat";
    case Animal::dog:
        return "dog";

    default:
        return "???";
	}
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";
    switch (animal)
    {
    case Animal::chicken:
    case Animal::duck:
        std::cout << 2;
        break;
    case Animal::pig:
    case Animal::goat:
    case Animal::cat:
    case Animal::dog:
        std::cout << 4;
        break;
    default:
        std::cout << "???";
        break;
    }
    std::cout << " legs.\n";
}

int main()
{
    printNumberOfLegs(Animal::cat);
    printNumberOfLegs(Animal::chicken);

    return 0;
}