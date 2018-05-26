#include <iostream>
#include <vector>
#include <string>
#include "BSTree.hpp"
using BSTree::Tree;
using BSTree::traversal_order;

int main(int argc, char* argv[])
{
	int value = 0;
	std::string way;
	setlocale(LC_ALL, "RUS");
	std::initializer_list<int> list;

	Tree<int> tree(list);
	for (unsigned i = 1; i < argc; i++) {
		tree.insert(atoi(argv[i]));
	}

	int ex = 0;

	while (ex != 1) {
		show_menu();
		int num_menu = 0;
		std::string menu, count, sym_menu;
		while (num_menu == 0) {
			getline(std::cin, menu);
			if (atoi(menu.c_str()))
				num_menu = atoi(menu.c_str());
			if (!(atoi(menu.c_str())) && (menu != ""))
				show_menu();
		}
		switch (num_menu) {
		case 1:
			if (tree.empty_tree())
				std::cout << "дерево пустое" << std::endl;
			else
				tree.print();
			break;
		case 2:
			if (tree.empty_tree()) {
				std::cout << "дерево пустое" << std::endl;
				break;
			}
			std::cout << "   а.Прямой обход\n   b.Поперечный обход\n   c.Обратный "
				"обход\n";
			char c;
			std::cin >> c;
			tree.print_units(std::cout, (traversal_order)c);
			break;
		case 3:
			std::cout << "Введите значение для нового узла:";
			std::cin >> value;
			while (!std::cin) {
				std::cin.clear();
				std::cin.get();
				std::cout << "Введено не число" << std::endl
					<< "Введите значение для нового узла:";
				std::cin >> value;
			}
			if (!tree.insert(value))
				std::cerr << "узел уже существует в дереве" << std::endl;
			break;
		case 4:
			if (tree.empty_tree()) {
				std::cout << "Дерево пусто" << std::endl;
				break;
			}
			std::cout << "Введите значение удаляемого узла:";
			std::cin >> value;
			while (!std::cin) {
				std::cin.clear();
				std::cin.get();
				std::cout << "Введено не число" << std::endl
					<< "Введите значение удаляемого узла:";
				std::cin >> value;
			}
			if (!tree.delete_unit(value))
				std::cout << "Узел не найден" << std::endl;
			break;
		case 5:
			std::cout << "Введите путь до файла" << std::endl;
			std::cin >> way;
			tree.save(way);
			break;
		case 6:
			std::cout << "Введите путь до файла" << std::endl;
			std::cin >> way;
			if (!tree.load(way))
				std::cout << "файл не существует" << std::endl;
			break;
		case 7:
			if (tree.empty_tree()) {
				std::cout << "Дерево пусто" << std::endl;
				break;
			}
			std::cout << "Введите значение для поиска:";
			std::cin >> value;
			while (!std::cin) {
				std::cin.clear();
				std::cin.get();
				std::cout << "Введено не число" << std::endl
					<< "Введите значение для поиска:";
				std::cin >> value;
			}
			if (tree.exists(value))
				std::cout << "Узел найден" << std::endl;
			else
				std::cout << "Узел не найден" << std::endl;
			break;
		case 8:
			std::cout << "Вы точно хотите выйти? (y/n): ";
			std::cin >> sym_menu;
			if ((sym_menu == "y") || (sym_menu == "Y") || (sym_menu == "yes") || (sym_menu == "YES") || (sym_menu == "Yes")) {
				ex = 1;
				std::cout << "До свидания!" << std::endl;
			}
			break;
		}
	}

	std::cin.get();
	std::cin.get();
}
