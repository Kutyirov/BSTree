#include "catch.hpp"
#include "BSTree.hpp"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>


TEST_CASE("Creating tree") {
	BSTree::Tree tree;
	REQUIRE(tree.empty_tree() == true);
	//BSTree::Tree tree_{ 1 };
	//REQUIRE(tree_.empty_tree() == false);
}

TEST_CASE("Printing of tree by various traversal order") {
	BSTree::Tree tree = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	std::string direct = "8  4  2  1  3  6  5  7  12  10  9  11  14  13  15  ";
	std::string symmetric = "1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  ";
	std::string reverse = "1  3  2  5  7  6  4  9  11  10  13  15  14  12  8  ";

	std::string str;
	std::stringstream out(str);

	tree.print_units(out, BSTree::traversal_order::direct);
	out << std::endl;
	tree.print_units(out, BSTree::traversal_order::symmetric);
	out << std::endl;
	tree.print_units(out, BSTree::traversal_order::reverse);
	out << std::endl;

	std::string result_direct;
	std::string result_symmetric;
	std::string result_reverse;

	getline(out, result_direct);
	getline(out, result_symmetric);
	getline(out, result_reverse);

	REQUIRE(direct == result_direct);
	REQUIRE(symmetric == result_symmetric);
	REQUIRE(reverse == result_reverse);
}

TEST_CASE("Addig node") {
	BSTree::Tree tree = { 25, 34, 12, 4, 7, 67, 78, 9, 0 };

	tree.insert(1);
	tree.insert(20);
	tree.insert(5);


	std::string str;
	std::stringstream out(str);

	tree.print_units(out, BSTree::traversal_order::direct);

	std::string result = "25  12  4  0  1  7  5  9  20  34  67  78  ";
	std::string result_of_adding;
	getline(out, result_of_adding);

	REQUIRE(result == result_of_adding);
}

TEST_CASE("Deleting node") {
	BSTree::Tree tree = { 25, 34, 12, 4, 7, 67, 78, 9, 0 };

	tree.delete_unit(25);
	tree.delete_unit(0);
	tree.delete_unit(12);

	std::string result = "34  4  7  9  67  78  ";

	std::string str;
	std::stringstream out(str);

	tree.print_units(out, BSTree::traversal_order::direct);

	std::string result_of_deleting;
	getline(out, result_of_deleting);

	REQUIRE(result == result_of_deleting);
}

TEST_CASE("Inputsymmetric file") {
	BSTree::Tree tree = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };

	std::string text = "8  4  2  1  3  6  5  7  12  10  9  11  14  13  15  ";
	std::string buffer;
	std::stringstream out(buffer);

	out << tree;

	std::string result;
	getline(out, result);

	REQUIRE(result == text);
}

TEST_CASE("Existence of node") {
	BSTree::Tree tree = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	REQUIRE(tree.exists(8) == true);
	REQUIRE(tree.exists(100) == false);
}

TEST_CASE("Saving in and loading from file") {
	BSTree::Tree tree = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	BSTree::Tree tree1;

	std::ofstream fout("answer.txt");
	fout << "Да";
	fout.close();

	std::freopen("answer.txt", "r", stdin);

	tree.save("BSTree.txt");
	tree1.load("BSTree.txt");

	std::string text = "8  4  2  1  3  6  5  7  12  10  9  11  14  13  15  ";
	std::string buffer;
	std::stringstream out(buffer);

	out << tree1;

	std::string result;
	getline(out, result);


	REQUIRE(result == text);
}
