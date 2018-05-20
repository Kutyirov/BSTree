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
}

TEST_CASE("Creating tree2") {
	  BSTree::Tree tree{ 1 };
	  REQUIRE(tree.empty_tree() == false);
}
TEST_CASE("TRAVERSAL ORDER DIRECT") {
    	Tree tree = { 10, 4, 3, 9, 15, 6, 12, 1, 11, 8, 2, 14, 7, 5, 13};
    	std::string dir = "10 4 3 1 2 9 6 5 8 7 15 12 11 14 13 ";
    	std::string str;
    	std::stringstream out(str);
    	tree.print_units(out, direct);
   	out<<std::endl;
    	std::string result_dir;
    	getline(out, result_dir);
    	REQUIRE(dir == result_dir);
}
TEST_CASE("TRAVERSAL ORDER SYMMETRIC") {
	Tree tree = { 10, 4, 3, 9, 15, 6, 12, 1, 11, 8, 2, 14, 7, 5, 13};
	std::string sym = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ";
	std::string str;
    	std::stringstream out(str);
	tree.print_units(out, symmetric);
    	out<<std::endl;
	std::string result_sym;
	getline(out, result_sym);
	REQUIRE(sym == result_sym);
}
TEST_CASE("TRAVERSAL ORDER REVERSE") {
	Tree tree = { 10, 4, 3, 9, 15, 6, 12, 1, 11, 8, 2, 14, 7, 5, 13};
	std::string rev = "2 1 3 5 7 8 6 9 4 11 13 14 12 15 10 ";
	std::string str;
    	std::stringstream out(str);
     	tree.print_units(out, reverse);
    	out<<std::endl;
	std::string result_rev;
	getline(out, result_rev);
	REQUIRE(rev == result_rev);
}
