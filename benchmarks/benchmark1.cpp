#include <iostream>
#include <ctime>
#include <cmath>
#include "BSTree.hpp"

int main() {
    clock_t  begin;
    clock_t  end;
    BStree::Tree<int> tree;
    for (size_t exp = 1; exp < 9;  exp ++ ) {
        int value;
        std::cout<<"Adding:"<<std::endl;
        begin = clock();
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.add(value);
        }
        end= clock() - begin;
        std::cout<<"10^"<<exp<<" : "<<(float)end/CLOCKS_PER_SEC<<std::endl;
        std::cout<<"Removing:"<<std::endl;
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.remove(value);
        }
        end= clock() - begin;
        std::cout<<"10^"<<exp<<" : "<<(float)end/CLOCKS_PER_SEC<<std::endl;
    }
}
