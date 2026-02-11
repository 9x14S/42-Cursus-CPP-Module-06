#include <ctime>
#include <cstdlib>
#include <iostream>

# include "Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	Base *random = generate();

	std::cout << "Pointer   ID: ";
	identify(random);
	std::cout << "Reference ID: ";
	identify(*random);

	delete random;
	return 0;
}
