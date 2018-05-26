[![Build Status](https://travis-ci.org/Kutyirov/BSTree.svg?branch=master)](https://travis-ci.org/Kutyirov/BSTree)

This is a project of realization Binary Search tree

In this project are realized the following opportunities:

displaying the tree on the screen
displaying the list of tree nodes (3 orders: pre, in, post)
adding a node to the tree
removing the node from the tree
saving the tree to the file
loading the tree from the file
existing of node
Building of a project:
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=install
$ cmake --build _build --target install
Run the test:

$ cmake -H. -B_build -DBUILD_TESTS=ON
$ cmake --build _build --target install
$ cmake --build _build --target test -- ARGS=--verbose
Run the examples:

$ cmake -H. -B_build -DBUILD_EXAMPLES=ON
$ cmake --build _build --target install
$ cd _build
$ ./example<number>
