#include <iostream>
#include <locale>
#include <ctime>
#include <cmath>
#include <fstream>
#include "BSTree.hpp"


int main() {
	setlocale(LC_ALL, "RUS");
	clock_t  t_start;
	clock_t  t_end;
	BSTree::Tree<int> tree;
	for (size_t exp = 1; exp < 9; exp++) {
		int value;
		for (size_t num_el = 1; num_el <= pow(10, exp); num_el++) {
			value = rand();
			tree.insert(value);
		}
		t_start = clock();
		tree.print();
		t_end = clock() - t_start;
		std::cout << "10^" << exp << " : " << (float)t_end / CLOCKS_PER_SEC << std::endl;
	}
	std::cin.get();
}
