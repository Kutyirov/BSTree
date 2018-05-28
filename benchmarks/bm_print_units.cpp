#include <iostream>
#include <locale>
#include <ctime>
#include <cmath>
#include <fstream>
#include "BSTree.hpp"


int main() {
    setlocale(LC_ALL, "RUS");
    clock_t  t_start;
    clock_t  t_end;
    BSTree::Tree<int> tree;
    std::freopen("tree_bench.txt", "w", stdout);
    for (size_t exp = 1; exp < 9;  exp ++ ) {
        int value;
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.insert(value);
        }
        std::ofstream fout("bench4.txt");
        fout<<"Print direct order:"<<std::endl;
        t_start = clock();
        tree.print_units(std::cout, BSTree::traversal_order::direct);
        t_end= clock() - t_start;
        std::cout<<std::endl;
        fout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;

        fout<<"Print symmetric order:"<<std::endl;
        t_start = clock();
        tree.print_units(std::cout, BSTree::traversal_order::symmetric);
        t_end = clock() - t_start;
        std::cout<<std::endl;
        fout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;

        fout<<"Print reverse order:"<<std::endl;
        t_start = clock();
        tree.print_units(std::cout, BSTree::traversal_order::reverse);
        std::cout<<std::endl;
        t_end = clock() - t_start;
        fout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
        fout.close();
    }
}
