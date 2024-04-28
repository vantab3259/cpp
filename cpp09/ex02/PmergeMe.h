#ifndef PMERGEME_H
#define PMERGEME_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>
#include <deque>
#include <list>
#include <ctime>



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
	template <typename v_d>
	void				insert(v_d & v, size_t step);
	template <typename v_d>
    void				sort(v_d&v, size_t step);
    std::vector<int> 	check_arg(char** arg);

private:
    PmergeMe() { return; } // norme cop

};

#endif
