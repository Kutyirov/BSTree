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
