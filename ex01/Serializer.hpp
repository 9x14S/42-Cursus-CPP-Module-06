#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

# include "Data.hpp"

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
private:
	// Orthodox Canonical Form
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &assign);
	~Serializer();

};

#endif /* SERIALIZER_HPP */
