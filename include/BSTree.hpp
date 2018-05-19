#pragma once
#include <sstream>
#include <vector>
#include <fstream>
namespace BSTree {
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	enum class traversal_order { direct = 'a', symmetric = 'b', reverse = 'c' };

	class Tree {
		Node* root;
		auto clean(Node* node) -> void {  //обратный обход для удаления
			if (node != nullptr) {
				clean(node->left);
				clean(node->right);
			}
			delete node;
			root = nullptr;
		};

		auto print(Node*, unsigned) const -> void;  //перегрузка print от корня второй
													//параметр - кол-во нулей для
													//текущего узла

		auto print_direct(std::ostream& out, BSTree::Node* node) ->std::ostream&;  //вывод 3-х обходов
		auto print_symmetric(std::ostream& out, BSTree::Node* node) ->std::ostream&;
		auto print_reverse(std::ostream& out, BSTree::Node* node) ->std::ostream&;
		auto save(std::ostream&, Node*) const
			-> void;  //перегрузка сохранения для рекурсии

	public:
		Tree() : root{ nullptr } {};  //конструктор по умолчанию
		Tree(std::initializer_list<int> list) {  //конструктор от вектора
			for (auto i : list)
				insert(i);
		};
		Tree(const Tree& tree) {  // конструктор копирования
			std::string str;
			std::stringstream out(str);
			out << tree;
			int value;
			while (out) {
				out >> value;
				insert(value);
			}
		};

		auto swap(Tree& tree) -> void;   //меняем деревья
		auto insert(int value) -> bool;  //добавление узла
		auto print() const -> void;  //начальный print вызывает print от корня
		auto value_length(int) const -> unsigned;  // длина числа
		auto empty_tree() const -> bool;  //проверка на пустоту
		auto print_units(std::ostream&, traversal_order) const->std::ostream&;  //вывод узлов вызывает один из 3-х вариантов
		auto delete_unit(int) -> bool;  //удаление
		auto exists(int)->bool;     //поиск узла
		auto save(const std::string&) const -> bool;
		auto load(const std::string&) -> bool;

		friend auto operator<<(std::ostream& stream, const Tree& tree)
			-> std::ostream & {  //перегрузка загрузки
			tree.save(stream, tree.root);
			return stream;
		}

		auto operator=(const Tree&)->Tree&;

		~Tree() {  //деструктор с рекурсией
			clean(root);
		}
	};
}

void show_menu();
