#include "PmergeMe.h"
//easy implememtation

// template <typename v_d>
// void	PmergeMe::insert(v_d & v, size_t range) {
// 	for(size_t i = range*3-1; i < v.size(); i += range)
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
// template <typename v_d>
// void	PmergeMe::sort(v_d & v, size_t range) {

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

int pow_two(bool refresh)
{
	static int nbr = 4;

	if (refresh)
		nbr = 4;
	int	to_return = nbr - 1;
	nbr *= 2;
	return (to_return);
}
int jacobS(bool refresh)
{
	static int js = 1;
	static int js_last = 3;
	
	if (refresh)
	{
		js = 1;
		js_last = 3;
	}
	int	to_return = js_last - js;
	int	tmp = js;
	js = js_last;
	js_last = to_return + 2 * tmp;
	return (to_return);		
}
template <typename v_d>
void	upgrade_ind(size_t min, size_t max, v_d& vect, int range)
{
	size_t	size = vect.size();

	for (size_t i = 0; i < size; ++i)
	{
		if (vect[i] > max)
			return ;
		else if (vect[i] >= min)
			vect[i] += range;
	}
}

template <typename v_d>
size_t	where_i_have_to_go(v_d v, std::vector<size_t>&sorted, int to_insert, int index_max)
{
	int	index_min = 0;

	if (index_max + 1 > static_cast<int>(sorted.size()))
		index_max = sorted.size() - 1;
	

	while (index_min + 1 != index_max)
	{
		int index_mid = index_min + (index_max - index_min) / 2;
		if (v[sorted[index_mid]] < to_insert)
			index_min = index_mid;
		else
			index_max = index_mid;
	}
	if (v[sorted[index_min]] > to_insert)
		return (sorted[index_min]);
	if (v[sorted[index_max]] < to_insert)
		return (sorted[index_max] + sorted[0] + 1);
	if (sorted[index_max] - sorted[index_min] == sorted[0] + 1)
		return (sorted[index_max]);
	return (sorted[index_max] - sorted[0] - 1);
}

template <typename v_d>
void	PmergeMe::insert(v_d & v, size_t range) {
	
	std::vector<size_t> sorted_ind;
	std::vector<size_t> unsorted_ind;

	size_t	size = v.size();
	for (size_t i = range - 1; i < size; i += range)
	{
		if (i < 2 * range || i / range % 2)
			sorted_ind.push_back(i);
		else
			unsorted_ind.push_back(i);
	}

	int	js_nbr = jacobS(true);
	int	pow_two_nbr = pow_two(true);
	while (unsorted_ind.empty() == false)
	{
		for (int ind = std::min(js_nbr, static_cast<int>(unsorted_ind.size())) - 1; ind > -1; --ind)
		{
			size_t	where_insert = where_i_have_to_go(v, sorted_ind, v[unsorted_ind[ind]], pow_two_nbr);
			size_t	where_i_came = unsorted_ind[ind];

			for (size_t j = 0; j < range; j++)
			{
				v.insert(v.begin() + where_insert - range + 1, v[where_i_came]);
				v.erase(v.begin() + where_i_came + 1);
			}

			unsorted_ind.erase(unsorted_ind.begin() + ind);
			upgrade_ind(where_insert, where_i_came, sorted_ind, range);
			upgrade_ind(where_insert, where_i_came, unsorted_ind, range);
			sorted_ind.insert(std::lower_bound(sorted_ind.begin(), sorted_ind.end(), where_insert), where_insert);
		}
		js_nbr = jacobS(false);
		pow_two_nbr = pow_two(false);
	}
}

template <typename v_d>
void	PmergeMe::sort(v_d & v, size_t range) {
	for (size_t i = range*2-1; i < v.size(); i += range*2)
	{
		if(v[i] < v[i - range])
		{
			for (size_t j = 0; j < range; j++){
				std::swap(v[i-j], v[i-range-j]);
			}
		}
	}
	if(range * 2 < v.size())
		sort(v, range*2);
	insert(v, range);
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
	std::deque<int> d(v.begin(), v.end());
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout <<"before :";
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
	std::cout << std::endl;

	clock_t start_vector = clock();
	sort(v, 1);
	clock_t end_vector = clock();

	clock_t start_deque = clock();
	sort(d, 1);
	clock_t end_deque = clock();
	std::cout <<"after :";
	for (size_t i = 0; i < v.size(); ++i) { std::cout << v[i] << " "; }
	std::cout << std::endl;
	std::cout << std::endl;

	double duration_vector = (double)(end_vector - start_vector) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << v.size() << " with std::vector<int>: " << duration_vector * 1000000 << " microseconds." << std::endl;
	double duration_deque = (double)(end_deque - start_deque) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << d.size() << " with std::deque<int>: " << duration_deque * 1000000 << " microseconds." << std::endl;
}
