#ifndef PMERGEME_H
#define PMERGEME_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include <list>



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
	void				insert(std::vector<int> & v, size_t step);
    void				sort(std::vector<int>&v, size_t step);
    std::vector<int> 	check_arg(char** arg);

private:
    PmergeMe() { return; } // norme cop

};

#endif
