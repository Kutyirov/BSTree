#include <iostream>
#include <ctime>
#include <cmath>
#include "BSTree.hpp"

int main() {
	clock_t  begin;
	clock_t  end;
	BSTree::Tree<int> tree;
	for (size_t exp = 1; exp < 7; exp++) {
		int value;
		std::cout << "Adding:" << std::endl;
		begin = clock();
		for (size_t num_el = 1; num_el <= pow(10, exp); num_el++) {
			value = rand();
			tree.insert(value);
		}
		end = clock() - begin;
		std::cout << "10^" << exp << " : " << (float)end / CLOCKS_PER_SEC << std::endl;
		std::cout << "Removing:" << std::endl;
		for (size_t num_el = 1; num_el <= pow(10, exp); num_el++) {
			value = rand();
			tree.delete_unit(value);
		}
		end = clock() - begin;
		std::cout << "10^" << exp << " : " << (float)end / CLOCKS_PER_SEC << std::endl;
	}
	std::cin.get();
}
