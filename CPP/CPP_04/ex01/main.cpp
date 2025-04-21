#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() 
{
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    for (int i = 0; i < arraySize / 2; i++)
        animals[i] = new Dog();
    for (int i = arraySize / 2; i < arraySize; i++) 
        animals[i] = new Cat();
    for (int i = 0; i < arraySize; i++) 
        animals[i]->makeSound();
    for (int i = 0; i < arraySize; i++) 
        delete animals[i];
    
    return 0;
}