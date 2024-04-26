#include "PmergeMe.h"

void	PmergeMe::insert(std::vector<int> & v, size_t range) {
	for(size_t i = range*2-1; i < v.size(); i += range)
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
		for (size_t j = 0; j < range; j++)
		{
			v.insert(v.begin() + right, v[i]);
			v.erase(v.begin() + i + 1);
		}	
	}
}

void	PmergeMe::sort(std::vector<int> & v, size_t range) {
	for (size_t i = range*2-1; i < v.size(); i += range*2)
	{
		if(v[i] < v[i - range])
		{
			for (size_t j = 0; j < range; j++){
				std::swap(v[i-j], v[i-range-j]);
			}
		}
	}
	std::cout << "IN recursion Merge: " << range << std::endl;
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
    std::cout << std::endl;

	if(range * 2 < v.size())
		sort(v, range*2);

	insert(v, range);
	std::cout << "OUT recursion Insersion: " << range<<  std::endl;
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
    std::cout << std::endl;
	
	return;
}


// void	PmergeMe::insert(std::vector<int> & v, size_t range) {
// 	for(size_t i = range*2-1; i+range <= v.size(); i += range)
// 	{
// 		int left = 0;
// 		int right = i;
// 		int mid;
// 		while(left < right)
// 		{
// 			mid = left + (right - left) / 2;
// 			if(v[i] <= v[mid])
// 				right = mid;
// 			else
// 				left = mid + 1;
// 		}
// 		for (size_t j = 0; j < range; j++)
// 		{
// 			v.insert(v.begin() + right, v[i]);
// 			v.erase(v.begin() + i + 1);
// 		}	
// 	}
// }
// void	PmergeMe::sort(std::vector<int> & v, size_t range) {

// 	for (size_t i = range*2-1; i +range*2 <= v.size(); i += range*2)
// 	{
// 		if(v[i] < v[i - range])
// 		{
// 			for (size_t j = 0; j < range; j++)
// 				std::swap(v[i-j], v[i-range-j]);
// 		}
// 	}
// 	if(range * 2 < v.size())
// 		sort(v, range*2);
// 	insert(v, range);
	
// 	return;
// }


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
	// for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
    std::cout << std::endl;
}
