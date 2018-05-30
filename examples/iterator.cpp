#include <iostream>
#include "BSTree.hpp"
using BSTree::Tree;

int main(int argc, char* argv[])
{
	Tree<int> tree{ 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	auto it1 = tree.begin();
	auto it2 = tree.begin();

	for (; it1 != tree.end(); ++it1) { //первый способ вывода
		std::cout << *it1 << ' ';
	}
	std::cout << std::endl;
	for (; it2 != tree.end(); ++it2) { //второй способ вывода
		std::cout << *it2.operator->() << ' ';
	}
	std::cout << std::endl;
	for (auto& item : tree) {         //третий способ вывода
		std::cout << item << " ";
  }
	std::cin.get();
}
