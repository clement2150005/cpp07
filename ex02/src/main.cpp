#include <iostream>
#include "Array.hpp"

int main() {
	try {
		std::cout << "=== Empty Array ===\n";
		Array<int> a;
		std::cout << "a.size() = " << a.size() << " (expected 0)\n";

		std::cout << "\n=== Construct with size ===\n";
		Array<int> b(5);
		std::cout << "b.size() = " << b.size() << " (expected 5)\n";
		for (size_t i = 0; i < b.size(); i++) {
			b[i] = static_cast<int>(i * 10);
			std::cout << "b[" << i << "] = " << b[i] << '\n';
		}

		std::cout << "\n=== Copy constructor ===\n";
		Array<int> c(b);
		std::cout << "c.size() = " << c.size() << " (expected 5)\n";
		for (size_t i = 0; i < c.size(); i++)
			std::cout << "c[" << i << "] = " << c[i] << '\n';

		std::cout << "\n=== Assignment operator ===\n";
		Array<int> d;
		d = b;
		std::cout << "d.size() = " << d.size() << " (expected 5)\n";
		for (size_t i = 0; i < d.size(); i++)
			std::cout << "d[" << i << "] = " << d[i] << '\n';

		std::cout << "\n=== Self-assignment ===\n";
		Array<int> &ref = b;
		b = ref; // should not crash, no leak
		std::cout << "b.size() = " << b.size() << " (expected 5)\n";

		std::cout << "\n=== Out of range access ===\n";
		std::cout << b[10] << '\n'; // should throw
	}
	catch (const std::out_of_range &e) {
		std::cout << "Exception caught: " << e.what() << '\n';
	}

	std::cout << "\n=== String Array ===\n";
	Array<std::string> s(3);
	s[0] = "Hello";
	s[1] = "World";
	s[2] = "!";
	for (size_t i = 0; i < s.size(); i++)
		std::cout << "s[" << i << "] = " << s[i] << '\n';

	return 0;
}
