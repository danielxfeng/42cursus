
#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
	const Animal *animals[6];
	for (int i = 0; i < 3; i++) {
		animals[i] = new Dog();
	}
	for (int i = 3; i < 6; i++) {
		animals[i] = new Cat();
	}
	for (int i = 0; i < 6; i++) {
		animals[i]->makeSound();
	}
	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}
	return 0;
}
