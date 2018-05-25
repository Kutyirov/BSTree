#include <iostream>
#include <locale>
#include "BSTree"

int main{
  setlocale(LC_ALL, "RUS");
  BSTree::Tree tree = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15}; //создание дерева с элеменатми
  BSTree::Tree empty_tree; //создание пустого дерева
  
  tree.print(); //вывод дерева в нормальном виде
  
   std::cout<<"Выведем дерево 1 прямым обходом: "<<std::endl;
    tree.print_units(std::cout, BSTree::traversal_order::direct);
    std::cout<<std::endl;
    std::cout<<"Выведем дерево 2  обходом : "<<std::endl;
    tree.print_units(std::cout, BSTree::traversal_order::symmetric);
    std::cout<<std::endl;
    std::cout<<"Выведем дерево 3  обходом :"<<std::endl;
    tree.print_units(std::cout, BSTree::traversal_order::reverse);
    std::cout<<std::endl;
    
     if(!tree.insert(1)) //попытка вставить уже существующего узла
        std::cout<<"Узел не найден!" <<std::endl;
    tree.insert(20); //вставка узла
    
    if(!tree.remove(100)) //попытка удалить узла
        std::cout<<"Узел не существует!" <<std::endl;
    tree.remove(1); //удаление узла
    
    if (tree.exists(3))
				std::cout << "Узел найден" << std::endl;
			else
				std::cout << "Узел не найден" << std::endl;
  
    if (tree.exists(100))
				std::cout << "Узел найден" << std::endl;
			else
				std::cout << "Узел не найден" << std::endl;
}
