#include <iostream>
#include <stdint.h>

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data t = {42, "Forty-Two", 42424242};
	Data *test_ptr = &t;

	uintptr_t serialized = Serializer::serialize(test_ptr);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Data (before):" << t.id << ", " << t.name << ", " << t.value << std::endl;
	std::cout << "test_ptr     :" << test_ptr << std::endl;
	std::cout << "deserialized :" << deserialized << std::endl;
	std::cout << "Equal?       :" << (test_ptr == deserialized ? "True" : "False") << std::endl;
	std::cout << "Data (after) :" << t.id << ", " << t.name << ", " << t.value << std::endl;
	return 0;
}
