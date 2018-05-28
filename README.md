[![Build Status](https://travis-ci.org/Kutyirov/BSTree.svg?branch=master)](https://travis-ci.org/Kutyirov/BSTree)

This is a project of realization Binary Search tree

This project implements the following methods

 -tree output in the correct form
 
 -the output of the nodes of the tree in three ways
 
 -adding a node to the tree
 
 -removing the node from the tree
 
 -saving the tree to the file
 
 -loading the tree from the file
 
 -existing of node
 
 
 
 
 
## Building of a project:
 
```
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=install

$ cmake --build _build --target install
```



**Run the test:**

```
$ cmake -H. -B_build -DBUILD_TESTS=ON

$ cmake --build _build --target install

$ cmake --build _build --target test -- ARGS=--verbose
```



**Run the examples:**

```
$ cmake -H. -B_build -DBUILD_EXAMPLES=ON

$cmake --build _build --target install

$ cd _build

$ ./example
```
Number|Print,s|Print direct,s|Print symmetric,s|Print reverse,s|Insert,s|Delete_units,s|Exists,s|Saving,s|Loading,s
:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:
10|0.000092|0.000043|0.000001|0.000003|0.000027|0.000057|0.000003|0.000062|0.000014
10^2|
10^3|
10^4|
10^5|
10^6|
10^7|
10^8|291.617|25.348|25.348|25.137|247.472|497.421|243.481|23.746|71.583
