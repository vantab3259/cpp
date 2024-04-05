#include "Serializer.h"


static void print_data(Data* data) {
	if (!data) {
		std::cout << "Null pointer" << std::endl;
		return;
	}
	std::cout << "Data (" << data << ")" << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Age : " << data->age << std::endl;
}


int main()
{
	Data test_data = {"mona", 21};

	std::cout << "Before serialization" << std::endl;
	print_data(&test_data);

	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(&test_data);
	std::cout << "Serialized: " << serialized << std::endl;
	
	std::cout << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "After deserialization" << std::endl;
	print_data(deserialized);

	return 0;
}