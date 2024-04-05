#include "easyfind.hpp"


template <typename T>
void display_container(const T& container, const std::string& container_type) {
	std::cout << PURPLE << container_type << " content : [";
	for (typename T::const_iterator it = container.begin();
		it != container.end(); ++it) {
		if (it != container.begin()) {
			std::cout << ", ";
		}
		std::cout << *it;
	}
	std::cout << "]" << RESET << std::endl;
}

template <typename T>
void display_find(const T& container, int data,
				const std::string& container_type) {
	std::cout << LILAC << "Searching " << data << " in " << container_type
			<< RESET << std::endl;
	typename T::const_iterator it = easyfind(container, data);
	if (it != container.end()) {
		std::cout << BLUE << *it << " is in the " << container_type << RESET
				<< std::endl;
	} else {
		std::cout << BOLD_RED << data << " is NOT in the " << container_type
				<< RESET << std::endl;
	}
}

int main() {
	std::vector<int> vector;
	std::list<int> list;
	std::srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		vector.push_back(std::rand() % 10);
		list.push_back(std::rand() % 10);
	}

	display_container(vector, "Vector");
	display_container(list, "List");

	display_find(vector, rand() % 10, "vector");
	display_find(vector, rand() % 10, "vector");
	display_find(vector, rand() % 10, "vector");

	display_find(list, rand() % 10, "list");
	display_find(list, rand() % 10, "list");
	display_find(list, rand() % 10, "list");

	return 0;
}