#include "PmergeMe.h"

void	PmergeMe::sort(std::vector<int> & v, size_t step) {

	std::cout << "recurtion IN with step" << step  <<std::endl;

	for (size_t i = step*2-1; i <= v.size(); i += step*2)
	{
		if(v[i] < v[i - step])
		{
			for (size_t j = 0; j < step; j++)
				std::swap(v[i-j], v[i-step-j]);
		}
	}
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
    std::cout << std::endl;

	if(step * 2 < v.size())
		sort(v, step*2);
	std::cout << "recurtion OUT with step" << step  <<std::endl;
	
	for(size_t i = step*2-1; i <= v.size(); i += step)
	{
		for(size_t z = step-1; z <= i; z+= step)
		{
			if(v[i] < v[z])
			{
				for (size_t j = 0; j < step; j++)
				{

					v.insert(v.begin() + z-step+1, v[i]);
					v.erase(v.begin() + i + 1);
				}
				z+= step;
			}
		}
	}
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
    std::cout << std::endl;
	return;
}

std::vector<int> PmergeMe::check_arg(char** arg) {
    int i = 1;
    long val;
    std::vector<int> v;
    char* endptr;
    while (arg[i]) {
        val = std::strtol(arg[i], &endptr, 10);
        if (*endptr == '\0' && val <= std::numeric_limits<int>::max() &&
            val >= std::numeric_limits<int>::min()) {
            v.push_back(static_cast<int>(val));
        } else {
            std::cout << "Error : incorrect argument" << std::endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return v;
}

PmergeMe::PmergeMe(char** arg) {
    std::vector<int> v = check_arg(arg);
    sort(v, 1);
}
