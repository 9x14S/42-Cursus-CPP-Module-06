#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
	static void convert( const std::string scalar );
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &assign);
	~ScalarConverter();

	static void _handleAsChar(const std::string scalar );
	static void _handleAsInt(const std::string scalar );
	static void _handleAsFloat(const std::string scalar );
	static void _handleAsDouble(const std::string scalar );
};

#endif /* SCALARCONVERTER_HPP */
