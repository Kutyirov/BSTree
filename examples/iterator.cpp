#include <iostream>
#include <string>
#include "BSTree.hpp"
using BSTree::Tree;



int main(int argc, char* argv[])
{
	Tree<int> tree{ 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	Tree<Student> tree2;
	Student s1, s2, s3;
	s1.name = "Sasha";
	s2.name = "Pasha";
	s3.name = "Yasha";
	tree2.insert(s1);
	tree2.insert(s2);
	tree2.insert(s3);


	auto it1 = tree.begin();
	auto it2 = tree2.begin();

	for (; it1 != tree.end(); ++it1) {
		std::cout << *it1 << ' ';
	}
	std::cout << std::endl;
	for (; it2 != tree2.end(); ++it2) {
		std::cout << it2->name << ' ';
	}
	std::cout << std::endl;
	for (auto& item : tree)
		std::cout << item << " ";
	std::cin.get();
}
