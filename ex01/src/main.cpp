#include <iostream>
#include "iter.hpp"

void printInt(const int &x) {
	std::cout << x << " ";
}

void doubleInt(int &x) {
	x *= 2;
}

void printString(const std::string &s) {
	std::cout << s << " ";
}

int main() {
	int arr[5] = {1, 2, 3, 4, 5};

	iter(arr, 5, printInt);
	std::cout << std::endl;

	iter(arr, 5, doubleInt);
	iter(arr, 5, printInt);
	std::cout << std::endl;

	std::string words[3] = {"hello", "world!"};
	iter(words, 3, printString);
	std::cout << std::endl;

	return 0;
}
