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
##Benchmark
Number|Print,s|Print direct,s|Print symmetric,s|Print reverse,s|Insert,s|Delete_units,s|Exists,s|Saving,s|Loading,s
:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:
10|0.000092|0.000043|0.000001|0.000003|0.000027|0.000057|0.000003|0.000062|0.000014
10^2|0.000293|0.000012|0.000012|0.000015|0.000053|0.000084|0.000033|0.000007|0.000015
10^3|0.002745|0.000102|0.000113|0.000157|0.000832|0.001354|0.000627|0.000823|0.001745
10^4|0.019561|0.001175|0.001175|0.001321|0.007592|0.012841|0.002376|0.001395|0.002823
10^5|0.164573|0.013841|0.013124|0.013116|0.054621|0.097542|0.035215|0.031436|0.037453
10^6|1.845327|0.195313|0.195311|0.182342|0.856317|1.636328|0.832145|0.164242|0.495632
10^7|24.05323|1.896423|2.004243|2.125393|14.14836|29.84973|16.01535|1.924242|5.525631
10^8|291.6173|25.34802|25.34821|25.13783|247.4724|497.4218|243.4813|23.74687|71.58343
