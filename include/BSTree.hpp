#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>

namespace BSTree {
	struct Student {
		std::string name;
		const bool operator < (const Student &s2) {
			return this->name < s2.name;
		}
		const bool operator > (const Student &s2) {
			return this->name > s2.name;
		}
	};

	template <typename T>
	struct Node {
		T data;
		Node<T>* left;
		Node<T>* right;
		Node<T>* parent;
	};

	enum class traversal_order { direct = 'a', symmetric = 'b', reverse = 'c' };


	template<typename T>
	class Iterator: public std::iterator<std::bidirectional_iterator_tag, Node<T>> {
    private:
		Node<T>* ptr;
		Node<T>* next(Node<T>* node);
		Node<T>* prev(Node<T>* node);
		auto min(Node<T>* node) const->Node<T>*;
		auto max(Node<T>* node) const->Node<T>*;
	public:
		Iterator(Node<T>* p) : ptr{ p } {};
		Iterator(const Iterator<T>& it) : ptr{ it.ptr } {};
		Iterator<T>& operator=(const Iterator<T>& it);
		Iterator<T>& operator++();
		Iterator<T> operator++(int);
		Iterator<T>& operator--();
		Iterator<T> operator--(int);
		bool operator==(const Iterator<T>& it) const;
		bool operator!=(const Iterator<T>& it) const;
		T& operator*() const;
		T* operator->() const;
};

	template<typename T>
	auto Iterator<T>::min(Node<T>* node) const -> Node<T>* {
		while (node->left != nullptr)
			node = node->left;
		return node;
	}

	template<typename T>
	auto Iterator<T>::max(Node<T>* node) const -> Node<T>* {
		while (node->right != nullptr)
			node = node->right;
		return node;
	}

	template<typename T>
	Node<T>* Iterator<T>::next(Node<T>* node) {
		if (node->right != nullptr) {
			return min(node->right);
		}
		Node<T>* par = node->parent;
		while (par != nullptr && node == par->right) {
			node = par;
			par = par->parent;
		}
		return par;
	}

	template<typename T>
	Node<T>* Iterator<T>::prev(Node<T>* node) {
		if (node->left != nullptr) {
			return max(node->left);
		}
		Node<T>* par = node->parent;
		while (par != nullptr && node == par->left) {
			node = par;
			par = par->parent;
		}
		return par;
	}

	template<typename T>
	Iterator<T>& Iterator<T>::operator=(const Iterator<T>& it) {
		ptr = it.ptr;
		return *this;
	}

	template<typename T>
	Iterator<T>& Iterator<T>::operator++() {
		ptr = next(ptr);
		return *this;
	}

	template<typename T>
	Iterator<T> Iterator<T>::operator++(int value) {
		Iterator<T> t(*this);
		for (unsigned i = 0; i < value; i++) 
			++(*this);
		return t;
	}

	template<typename T>
	Iterator<T>& Iterator<T>::operator--() {
		ptr = prev(ptr);
		return *this;
	}

	template<typename T>
	Iterator<T> Iterator<T>::operator--(int value) {
		Iterator<T> t(*this);
		for (unsigned i = 0; i < value; i++) 
			--(*this);
		return t;
	}

	template<typename T>
	bool Iterator<T>::operator==(const Iterator<T>& it) const {
		return ptr == it.ptr;
	}

	template<typename T>
	bool Iterator<T>::operator!=(const Iterator<T>& it) const {
		return ptr != it.ptr;
	}

	template<typename T>
	T& Iterator<T>::operator*() const {
		return ptr->data;
	}

	template<typename T>
	T* Iterator<T>::operator->() const {
		return &(ptr->data);
	}





	template <typename T>
	class Tree {
		Node<T>* root;
		auto clean(Node<T>* node) -> void {  //обратный обход для удаления
			if (node != nullptr) {
				clean(node->left);
				clean(node->right);
			}
			delete node;

		};
		auto print(Node<T>*, unsigned) const -> void;  //перегрузка print от корня второй
													//параметр - кол-во нулей для
													//текущего узла

		auto print_direct(std::ostream& out, const BSTree::Node<T>* node) const->std::ostream&;  //вывод 3-х обходов
		auto print_symmetric(std::ostream& out, const BSTree::Node<T>* node) const->std::ostream&;
		auto print_reverse(std::ostream& out, const BSTree::Node<T>* node) const->std::ostream&;
		auto save(std::ostream&, Node<T>*) const -> void;  //перегрузка сохранения для рекурсии
		//auto balance(unsigned);

	public:
		Tree() : root{ nullptr } {};  //конструктор по умолчанию
		Tree(std::initializer_list<T> list) :Tree() {  //конструктор от 
			for (auto i : list)
				insert(i);
		};
		Tree(const Tree<T>& tree) {  // конструктор копирования
			std::string str;
			std::stringstream out(str);
			out << tree;
			T value;
			while (out) {
				out >> value;
				insert(value);
			}
		};

		auto balance(const Tree<T>& tree,int) -> void;
		auto swap(Tree<T>& tree) -> void;   //меняем деревья
		auto insert(T value) -> bool;  //добавление узла
		auto print() const -> void;  //начальный print вызывает print от корня
		auto value_length(T) const -> unsigned;  // длина числа
		auto empty_tree() const -> bool;  //проверка на пустоту
		auto print_units(std::ostream&, traversal_order) const->std::ostream&;  //вывод узлов вызывает один из 3-х вариантов
		auto delete_unit(T) -> bool;  //удаление
		auto exists(T)->bool;     //поиск узла
		auto save(const std::string&) const -> bool;
		auto load(const std::string&) -> bool;

		Iterator<T> begin() const{                         //итератор от min и max значений дерева
			Node<T>* p = root;
			while (p->left != nullptr)
				p = p->left;
			return Iterator<T>(p);
		}

		Iterator<T> end() const{
			Node<T>* p = root;
			while (p != nullptr)
				p = p->right;
			return Iterator<T>(p);
		}



		friend auto operator<<(std::ostream& stream, const Tree<T>& tree)
			-> std::ostream & {  //перегрузка загрузки
			tree.save(stream, tree.root);
			return stream;
		}

		auto operator=(const Tree<T>&)->Tree<T>&;

		~Tree() {  //деструктор с рекурсией
			clean(root);
			root = nullptr;
		}
	};
}


using namespace BSTree;

template <typename T>
auto Tree<T>::value_length(T n) const -> unsigned {
	T k = 1;
	if (n < 0)
		k++;
	while (n != 0) {
		n = n / 10;
		k++;
	}
	return k;
}

template <typename T>
auto BSTree::Tree<T>::swap(Tree<T>& tree) -> void {
	std::swap(root, tree.root);
}

template <typename T>
auto Tree<T>::insert(T value) -> bool {
	Node<T>* p = root;
	if (p == nullptr) {
		root = new Node<T>{ value, nullptr, nullptr, nullptr };
		return true;
	}
	else
		for (;;) {
			if (p->data > value)
				if (p->left == nullptr) {
					p->left = new Node<T>{ value, nullptr, nullptr, p };
					return true;
				}
				else
					p = p->left;
			else if (p->data < value)
				if (p->right == nullptr) {
					p->right = new Node<T>{ value, nullptr, nullptr, p };
					return true;
				}
				else
					p = p->right;
			else {
				// std::cout << "узел уже существет" << std::endl;
				return false;
			}
		}
}

template <typename T>
auto Tree<T>::print() const -> void {
	unsigned n = 1;
	print(root, n);
}

template <typename T>
auto Tree<T>::empty_tree() const -> bool {
	if (root == nullptr)
		return true;
	else
		return false;
}

template <typename T>
auto BSTree::Tree<T>::print_units(std::ostream& stream, traversal_order c) const -> std::ostream& {
	Node<T>* p = root;
	switch (c) {
	case traversal_order::direct:
		print_direct(stream, p);
		std::cout << std::endl;
		break;
	case traversal_order::symmetric:
		print_symmetric(stream, p);
		std::cout << std::endl;
		break;
	case traversal_order::reverse:
		print_reverse(stream, p);
		std::cout << std::endl;
		break;
	default:
		std::cout << "Введен некорректный параметр" << std::endl;
	}
	return stream;
}

template <typename T>
auto BSTree::Tree<T>::delete_unit(T value) -> bool {
	Node<T>* q = root;
	while ((q != nullptr) && (q->data != value)) {
		if (value > q->data)
			q = q->right;
		else if (value < q->data)
			q = q->left;
	}
	if (q == nullptr) 
		return false;
	Node<T>* p = q->parent;  //приписывание узла со значением value к q
	if ((q->right == nullptr) && (q->left == nullptr)) {
		if (p == nullptr)
			root = nullptr;
		else {
			if (p->right == q)
				p->right = nullptr;
			else
				p->left = nullptr;
			delete q;
		}
	}
	else if ((q->right != nullptr) && (q->left != nullptr)) {
		if (q->right->left == nullptr) {
			if (p == nullptr) {
				q->right->left = q->left;
				q->left->parent = q->right;
				root = q->right;
				delete q;
				root->parent = nullptr;
			}
			else {
				q->right->left = q->left;
				q->left->parent = q->right;
				if (p->right == q) {
					p->right = q->right;
				}
				else {
					p->left = q->right;
				}
				q->right->parent = p;
				delete q;
			}
		}
		else {
			Node<T>* r = q->right;  //поиск наименьшего в правом поддереве
			while (r->left->left != nullptr)
				r = r->left;
			q->data = r->left->data;
			Node<T>* t = r->left->right;
			delete r->left;
			r->left = t;
			if (t != nullptr)
				t->parent = r->left;
		}
	}
	else if (q->right == nullptr)
		if (p == nullptr) {
			root = q->left;
			delete q;
			root->parent = nullptr;
		}
		else {
			if (p->right == q) {
				p->right = q->left;
				q->left->parent = p;
			}
			else {
				p->left = q->left;
				q->left->parent = p;
			}
			delete q;
		}
	else if (p == nullptr) {
		root = q->right;
		delete p;
		root->parent = nullptr;
	}
	else {
		if (p->right == q) {
			p->right = q->right;
			q->right->parent = p;
		}
		else {
			p->left = q->right;
			q->right->parent = p;
		}
		delete q;
	}
	return true;
}

template <typename T>
auto BSTree::Tree<T>::exists(T value) -> bool {
	Node<T>* p = root;
	while ((p != nullptr) && (p->data != value)) {
		if (value > p->data)
			p = p->right;
		else if (value < p->data)
			p = p->left;
	}
	if (p != nullptr)
		return true;
	else
		return false;
}

template <typename T>
auto Tree<T>::operator=(const Tree<T>& tree) -> Tree<T> & {
	Tree{ tree }.swap(*this);
	// this->copy(tree.root);
	return *this;
}

template <typename T>
auto Tree<T>::print(Node<T>* p, unsigned n) const
-> void {  //Функция рекурсивно обходит все дерево в глубину
	if ((p->right != nullptr) || (p->left != nullptr)) {
		if (p->right != nullptr)
			print(p->right, n + value_length(p->data) + 1);
		else
			std::cout << std::endl;
	}
	for (unsigned i = 0; i < n; i++)
		std::cout << ' ';
	if (p != root)
		std::cout << "--" << p->data << std::endl;
	else
		std::cout << p->data << std::endl;
	if ((p->right != nullptr) || (p->left != nullptr)) {
		if (p->left != nullptr)
			print(p->left, n + value_length(p->data) + 1);
		else
			std::cout << std::endl;
	}
}

template <typename T>
auto BSTree::Tree<T>::print_direct(std::ostream& output, const Node<T>* p) const -> std::ostream& {
	if (p != nullptr) {
		output << p->data << "  ";
		print_direct(output, p->left);
		print_direct(output, p->right);
	}
	return output;
}

template <typename T>
auto BSTree::Tree<T>::print_symmetric(std::ostream& output, const Node<T>* p) const -> std::ostream& {
	if (p != nullptr) {
		print_symmetric(output, p->left);
		output << p->data << "  ";
		print_symmetric(output, p->right);
	}
	return output;
}

template <typename T>
auto BSTree::Tree<T>::print_reverse(std::ostream& output, const Node<T>* p) const -> std::ostream& {
	if (p != nullptr) {
		print_reverse(output, p->left);
		print_reverse(output, p->right);
		output << p->data << "  ";
	}
	return output;
}

template <typename T>
auto Tree<T>::save(const std::string& way) const -> bool {
	std::ifstream output(way);
	bool flag = output.is_open();
	output.close();
	if (flag) {
		std::cout << "Файл уже существует, перезаписать ? (Yes|No): ";
		std::string ans;
		std::cin >> ans;
		if (ans == "y" || ans == "Y" || ans == "yes" || ans == "Yes" ||
			ans == "YES") {
			std::ofstream input(way);
			input << *this;
			input.close();
			return true;
		}
		return false;
	}
	std::ofstream input(way);
	input << *this;
	input.close();
	return true;
}

template <typename T>
auto Tree<T>::save(std::ostream& stream, Node<T>* node) const -> void {
	if (node != nullptr) {
		stream << node->data << " ";
		save(stream, node->left);
		save(stream, node->right);
	}
}

template <typename T>
auto Tree<T>::load(const std::string& way) -> bool {
	std::ifstream output(way);
	if (!output.is_open()) {
		return false;
	}
	this->~Tree();
	T t;
	while (!output.eof()) {
		output >> t;
		this->insert(t);
	}
	return true;

}

template <typename T>
auto Tree<T>::balance(const Tree<T>& tree,int n) -> void {
	auto it = tree.begin();
	auto it1 = tree.begin();
	Tree<T> tree1;
	Tree<T> tree2;
	for (unsigned i = 0; i < n/2; i++)
		++it;
	auto it2 = it;
	++it2;
	for (; it != it1; ++it1)
		tree1.insert(*it1);
	for (; it2 != tree.end(); ++it2)
		tree2.insert(*it2);
	this->insert(*it);
	if (n > 1) {
		if (tree1.root!= nullptr)
			balance(tree1, n/2);
		if (tree2.root!= nullptr) 
			if (n % 2 == 0)
				balance(tree2, n / 2 - 1);
			else
				balance(tree2, n / 2);
	}
}

void show_menu() {
	std::cout << "1. Вывести дерево на экран" << std::endl
		<< "2. Вывести список узлов дерева" << std::endl
		<< "3. Добавить узел в дерево" << std::endl
		<< "4. Удалить узел из дерева" << std::endl
		<< "5. Сохранить дерево в файл" << std::endl
		<< "6. Загрузить дерево из файла" << std::endl
		<< "7. Проверить наличие узла" << std::endl
		<< "8. Завершить работу программы" << std::endl;
}
