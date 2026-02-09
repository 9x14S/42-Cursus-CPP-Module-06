#include <csignal>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cctype>

#include "ScalarConverter.hpp"

// Orthodox Canonical Form
/// Default Constructor
ScalarConverter::ScalarConverter( void )
{}

/// Copy Constructor
ScalarConverter::ScalarConverter( const ScalarConverter &copy )
{
	(void)copy;
}

/// Destructor
ScalarConverter::~ScalarConverter( void )
{}

/// Copy Assignment Operator
ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &assign )
{
	(void)assign;
	return *this;
}

bool isAllDigits(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool floatHasDecimals(float f)
{
	return (f - static_cast<int>(f) != 0);
}

bool doubleHasDecimals(double d)
{
	return (d - static_cast<int>(d) != 0);
}

void	ScalarConverter::_handleAsChar( const std::string scalar )
{
	char c = scalar[0];

	std::cout
		<< "As char  : " << (std::isprint(c) ? "'"+scalar+"'": "Not displayable") << std::endl;
	std::cout
		<< "As int   : " << static_cast<int>(c) << std::endl;
	std::cout
		<< "As float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout
		<< "As double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::_handleAsInt( const std::string scalar )
{
	int i = std::atoi(scalar.c_str());

	char c = static_cast<char>(i);
	std::stringstream ss;
	if (std::isprint(c))
		ss << '\'' << c << '\'';
	else
		ss << "Not displayable";
	std::cout
		<< "As char  : " << ss.str() << std::endl;
	std::cout
		<< "As int   : " << i << std::endl;
	std::cout
		<< "As float : " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout
		<< "As double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::_handleAsFloat( const std::string scalar )
{
	char *end;
	float f = strtof(scalar.c_str(), &end);
	if (*end != 'f')
	{
		std::cerr << "Error" << std::endl;
		return ; // Error happened
	}
	char c = static_cast<char>(f);
	std::stringstream ss;
	if (std::isprint(c))
		ss << '\'' << c << '\'';
	else
		ss << "Not displayable";
	std::cout
		<< "As char  : " << ss.str() << std::endl;
	std::cout
		<< "As int   : " << static_cast<int>(f) << std::endl;

	if (floatHasDecimals(f))
		std::cout
			<< "As float : " << f << "f" << std::endl;
	else
		std::cout
			<< "As float : " << f << ".0f" << std::endl;
	double d = static_cast<double>(f);
	if (doubleHasDecimals(d))
		std::cout
			<< "As double: " << d << std::endl;
	else
		std::cout
			<< "As double: " << d << ".0" << std::endl;
}

void	ScalarConverter::_handleAsDouble( const std::string scalar )
{
	char *end;
	double d = strtod(scalar.c_str(), &end);
	if (*end)
	{
		std::cerr << "Error" << std::endl;
		return ; // Error happened
	}
	char c = static_cast<char>(d);
	std::stringstream ss;
	if (std::isprint(c))
		ss << '\'' << c << '\'';
	else
		ss << "Not displayable";
	std::cout
		<< "As char  : " << ss.str() << std::endl;
	std::cout
		<< "As int   : " << static_cast<int>(d) << std::endl;

	float f = static_cast<float>(d);
	if (floatHasDecimals(f))
		std::cout
			<< "As float : " << f << "f" << std::endl;
	else
		std::cout
			<< "As float : " << f << ".0f" << std::endl;

	if (doubleHasDecimals(d))
		std::cout
			<< "As double: " << d << std::endl;
	else
		std::cout
			<< "As double: " << d << ".0" << std::endl;
}

void	ScalarConverter::convert( const std::string scalar )
{
	// No error handling specified or required by the subject, so I'm not
	// adding any of it other than a simple "Error\n" on stderr
	// I'm aware of the following issues that might arise:
	//// scalar is an empty iterator (scalar.empty())
	//// scalar doesn't fit into any of the four types
	//// scalar is any of the types but overflows
	//// string methods might throw an exception, which is unhandled here and in main
	if (scalar.length() == 1 && !std::isdigit(scalar[0]))
		_handleAsChar(scalar);
	else if (isAllDigits(scalar))
		_handleAsInt(scalar);
	else if (scalar.at(scalar.length() - 1) == 'f')
		_handleAsFloat(scalar);
	else // Assume any other case is double
		_handleAsDouble(scalar);
}
