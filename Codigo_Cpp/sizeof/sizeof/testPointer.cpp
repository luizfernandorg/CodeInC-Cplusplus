#include <iostream>

void doubleIt(int* n) {
	std::cout << n << " " << *n << std::endl;
	*n = (*n) * (*n);
	std::cout << n << " " << *n << std::endl;
}