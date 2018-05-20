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
    	BSTree::Tree tree = { 10, 4, 3, 9, 15, 6, 12, 1, 11, 8, 2, 14, 7, 5, 13};
    	std::string dir = "10 4 3 1 2 9 6 5 8 7 15 12 11 14 13 ";
    	std::string str;
    	std::stringstream out(str);
    	tree.print_units(out, BSTree::traversal_order::direct);
   	out<<std::endl;
    	std::string result_dir;
    	getline(out, result_dir);
    	REQUIRE(dir == result_dir);
}

TEST_CASE("TRAVERSAL ORDER SYMMETRIC") {
	BSTree::Tree tree = { 10, 4, 3, 9, 15, 6, 12, 1, 11, 8, 2, 14, 7, 5, 13};
	std::string sym = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ";
	std::string str;
    	std::stringstream out(str);
	tree.print_units(out, BSTree::traversal_order::symmetric);
    	out<<std::endl;
	std::string result_sym;
	getline(out, result_sym);
	REQUIRE(sym == result_sym);
}

TEST_CASE("TRAVERSAL ORDER REVERSE") {
	BSTree::Tree tree = { 10, 4, 3, 9, 15, 6, 12, 1, 11, 8, 2, 14, 7, 5, 13};
	std::string rev = "2 1 3 5 7 8 6 9 4 11 13 14 12 15 10 ";
	std::string str;
    	std::stringstream out(str);
     	tree.print_units(out, BSTree::traversal_order::reverse);
    	out<<std::endl;
	std::string result_rev;
	getline(out, result_rev);
	REQUIRE(rev == result_rev);
}

TEST_CASE("ADDING NODE") {
    BSTree::Tree tree = { 51, 93, 71, 16, 4, 53, 11, 32};
    tree.insert(80);
    tree.insert(25);
    tree.insert(1);
    std::string str;
    std::stringstream out(str);
    tree.print_units(out, BSTree::traversal_order::direct);
    std::string result = "51 16 4 1 11 32 25 93 71 53 80 ";
    std::string result_of_adding;
    getline(out, result_of_adding);
    REQUIRE(result == result_of_adding);
}

TEST_CASE("DELETING NODE") {
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
