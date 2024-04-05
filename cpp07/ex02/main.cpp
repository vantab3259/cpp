#include "Array.hpp"

int main() {

	Array<unsigned int> arr(5);
	for (unsigned int i = 0; i < arr.size(); ++i) {
		arr[i] = i * 10;
	}

	std::cout << "Array contents:" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << "Attempting to access index 10: " << arr[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}