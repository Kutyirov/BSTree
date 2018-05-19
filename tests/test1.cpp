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
	BSTree::Tree tree2{ 1 };
	REQUIRE(tree2.empty_tree() == false);
}

TEST_CASE("Creating tree2") {
	  BSTree::Tree tree{ 1 };
	  REQUIRE(tree.empty_tree() == false);
}
