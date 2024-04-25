#ifndef PMERGEME_H
#define PMERGEME_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

struct _pair{
	int a;
	int b;
} _pair;

class PmergeMe {
public:
    // norme cop
    PmergeMe(char** arg);
    ~PmergeMe() {}
    PmergeMe(PmergeMe const& copy) { *this = copy; }
    PmergeMe& operator=(PmergeMe const& copy) {
        (void)copy;
        return (*this);
    }
    // fin norme cop
    void				binary_insert(std::vector<int>&v, int elem);

    void				sort(std::vector<int>&v, size_t step);
    std::vector<int> 	fordJ(std::vector<int>& vector);
    std::vector<int> 	check_arg(char** arg);

private:
    PmergeMe() { return; } // norme cop

};

#endif
