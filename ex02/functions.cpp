#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int selector = std::rand() % 3;
	switch (selector)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base *c)
{
	if (dynamic_cast<A*>(c))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(c))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(c))
		std::cout << "C" << std::endl;
	else
		std::cerr << "Unknown class type" << std::endl;
}

void identify(Base &c)
{
	try
	{
		(void)dynamic_cast<A&>(c);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{}
	try
	{
		(void)dynamic_cast<B&>(c);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...)
	{}
	try
	{
		(void)dynamic_cast<C&>(c);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...)
	{}
	std::cerr << "Unknown class type" << std::endl;
}
