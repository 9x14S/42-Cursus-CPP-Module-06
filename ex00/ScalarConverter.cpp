#include <limits>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <cmath>

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

bool isAllDigits(std::string str)
{
	if (str.length() > 0 && (str[0] == '-' || str[0] == '+'))
		str[0] = '0';
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
		<< "char  : " << (std::isprint(c) ? "'"+scalar+"'": "Not displayable") << std::endl;
	std::cout
		<< "int   : " << static_cast<int>(c) << std::endl;
	std::cout
		<< "float : " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout
		<< "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::_handleAsInt( const std::string scalar )
{
	char *end = NULL;
	long l = std::strtol(scalar.c_str(), &end, 10);
	if (*end)
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	int i = static_cast<int>(l);
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char  : impossible" << std::endl;
	else if (std::isprint(i))
		std::cout << "char  : '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char  : Non displayable" << std::endl;
	std::cout
		<< "int   : " << i << std::endl;
	std::cout
		<< "float : " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout
		<< "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::_handleAsFloat( const std::string scalar )
{
	char *end;
	float f = static_cast<float>(strtod(scalar.c_str(), &end));
	if (*end != '\0' && (*end != 'f' || end[1] != '\0'))
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "char  : impossible" << std::endl;
	else if (std::isprint(static_cast<char>(f)))
		std::cout << "char  : '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char  : Non displayable" << std::endl;

	if (std::isnan(f) || std::isinf(f) || static_cast<long>(f) < std::numeric_limits<int>::min() || static_cast<long>(f) > std::numeric_limits<int>::max())
		std::cout << "int   : impossible" << std::endl;
	else
		std::cout << "int   : " << static_cast<int>(f) << std::endl;
	std::cout << "float : " << f;

	if (!std::isnan(f) && !std::isinf(f) && (f - static_cast<int>(f) == 0))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (!std::isnan(f) && !std::isinf(f) && (f - static_cast<int>(f) == 0))
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::_handleAsDouble( const std::string scalar )
{
	char *end;
	double d = strtod(scalar.c_str(), &end);
	if (*end)
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "char  : impossible" << std::endl;
	else if (std::isprint(static_cast<char>(d)))
		std::cout << "char  : '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char  : Non displayable" << std::endl;
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int   : impossible" << std::endl;
	else
		std::cout << "int   : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << static_cast<float>(d);
	if (!std::isnan(d) && !std::isinf(d) && (d - static_cast<int>(d) == 0))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (!std::isnan(d) && !std::isinf(d) && (d - static_cast<int>(d) == 0))
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert( const std::string scalar )
{
	if (scalar.length() == 1 && !std::isdigit(scalar[0]))
		_handleAsChar(scalar);
	else if (isAllDigits(scalar))
		_handleAsInt(scalar);
	else if (scalar.at(scalar.length() - 1) == 'f')
		_handleAsFloat(scalar);
	else // Assume any other case is double
		_handleAsDouble(scalar);
}
