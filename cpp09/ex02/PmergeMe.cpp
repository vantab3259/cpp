#include "PmergeMe.h"

void	PmergeMe::sort(std::vector<int> & v, size_t step) {


	for (size_t i = step*2-1; i +step*2 <= v.size(); i += step*2)
	{
		if(v[i] < v[i - step])
		{
			for (size_t j = 0; j < step; j++)
				std::swap(v[i-j], v[i-step-j]);
		}
	}


	if(step * 2 < v.size())
		sort(v, step*2);

	for(size_t i = step*2-1; i+step <= v.size(); i += step)
	{
		int left = 0;
		int right = i;
		int mid;
		while(left < right)
		{
			mid = left + (right - left) / 2;
			if(v[i] <= v[mid])
				right = mid;
			else
				left = mid + 1;
		}
		for (size_t j = 0; j < step; j++)
		{
			v.insert(v.begin() + right, v[i]);
			v.erase(v.begin() + i + 1);
		}
			
	}
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
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
    std::cout << std::endl;
}
