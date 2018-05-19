#include <iostream>
#include <string>
#include "BSTree.hpp"
using namespace BSTree;

auto Tree::value_length(int n) const -> unsigned {
  int k = 1;
  if (n < 0)
    k++;
  while (n != 0) {
    n = n / 10;
    k++;
  }
  return k;
}

auto BSTree::Tree::swap(Tree& tree) -> void {
  std::swap(root, tree.root);
}

auto Tree::insert(int value) -> bool {
  Node* p = root;
  if (p == nullptr)
    root = new Node{value, nullptr, nullptr};
  else
    for (;;) {
      if (p->data > value)
        if (p->left == nullptr) {
          p->left = new Node{value, nullptr, nullptr};
          return true;
        } else
          p = p->left;
      else if (p->data < value)
        if (p->right == nullptr) {
          p->right = new Node{value, nullptr, nullptr};
          return true;
        } else
          p = p->right;
      else {
        // std::cout << "узел уже существет" << std::endl;
        return false;
      }
    }
}

auto Tree::print() const -> void {
  unsigned n = 1;
  print(root, n);
}

auto Tree::empty_tree() const -> bool {
  if (root == nullptr)
    return true;
  else
    return false;
}

auto BSTree::Tree::print_units(traversal_order c) const -> void {
  Node* p = root;
  switch (c) {
    case traversal_order::direct:
      print_direct(p);
      std::cout << std::endl;
      break;
    case traversal_order::symmetric:
      print_symmetric(p);
      std::cout << std::endl;
      break;
    case traversal_order::reverse:
      print_reverse(p);
      std::cout << std::endl;
      break;
    default:
      std::cout << "Введен некорректный параметр" << std::endl;
  }
}

auto BSTree::Tree::delete_unit(int value) -> bool {
  Node* p = root;
  if ((p->data != value) &&
          ((p->right != nullptr) && (p->right->data != value)) &&
          ((p->left != nullptr) && (p->left->data != value)) ||
      (p->left == nullptr) || (p->right == nullptr))
    if ((p->data != value) &&
        (((p->right != nullptr) && (p->right->data != value)) ||
         ((p->left != nullptr) && (p->left->data != value))))

      for (;;) {  //поиск предка узла со значением value - p
        if (value > p->data)
          p = p->right;
        else if (value < p->data)
          p = p->left;
        while ((p->left == nullptr) || (p->right == nullptr)) {
          if ((p->right != nullptr) && (p->right->data == value))
            break;
          if ((p->left != nullptr) && (p->left->data == value))
            break;
          if (p->left == nullptr)
            p = p->right;
          else if (p->right == nullptr)
            p = p->left;
          if (p == nullptr)
            break;
        }
        if (p == nullptr)
          return false;
        if ((p->right != nullptr) && (p->right->data == value))
          break;
        if ((p->left != nullptr) && (p->left->data == value))
          break;
      }

  Node* q = p;  //приписывание узла со значением value к q
  if (p->right != nullptr)
    if (p->right->data == value)
      q = p->right;
  if (p->left != nullptr)
    if (p->left->data == value)
      q = p->left;
  if ((q->right == nullptr) && (q->left == nullptr)) {
    if (p == q)
      root = nullptr;
    else {
      if (p->right == q)
        p->right = nullptr;
      else
        p->left = nullptr;
      delete q;
    }
  } else if ((q->right != nullptr) && (q->left != nullptr)) {
    if (q->right->left == nullptr) {
      if (p == q) {
        p->right->left = p->left;
        root = p->right;
        delete p;
      } else {
        q->right->left = q->left;
        if (p->right == q) {
          p->right = q->right;
        } else {
          p->left = q->right;
        }
        delete q;
      }
    } else {
      Node* r = q->right;  //поиск наименьшего в правом поддереве
      while (r->left->left != nullptr)
        r = r->left;
      q->data = r->left->data;
      Node* t = r->left->right;
      delete r->left;
      r->left = t;
    }
  } else if (q->right == nullptr)
    if (p == q) {
      root = q->left;
      delete p;
    } else {
      if (p->right == q)
        p->right = q->left;
      else
        p->left = q->left;
      delete q;
    }
  else if (p == q) {
    root = q->right;
    delete p;
  } else {
    if (p->right == q)
      p->right = q->right;
    else
      p->left = q->right;
    delete q;
  }
  return true;
}

auto BSTree::Tree::exists(int value) -> Node* & {
  Node* p = root;
  while ((p != nullptr) && (p->data != value)) {
    if (value > p->data)
      p = p->right;
    else if (value < p->data)
      p = p->left;
  }
  return p;
}

auto Tree::operator=(const Tree& tree) -> Tree & {
  this->~Tree();
  Tree t1(tree);
  this->root = t1.root;
  // this->copy(tree.root);
  return *this;
}

auto Tree::print(Node* p, unsigned n) const
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

auto BSTree::Tree::print_direct(std::ostream& output, Node* p) const -> std::ostream& {
   if(p != nullptr) {
        output << p->data<<"  ";
        print_pre(output, p->left);
        print_pre(output, p->right);
    }
    return output;
}

auto BSTree::Tree::print_symmetric(std::ostream& output, Node* p) const -> std::ostream& {
   if(p != nullptr) {
        print_pre(output, p->left);
        output << p->data<<"  ";
        print_pre(output, p->right);
    }
    return output;
}

auto BSTree::Tree::print_reverse(std::ostream& output, Node* p) const -> std::ostream& {
  if(p != nullptr) {
        print_pre(output, p->left);
        print_pre(output, p->right);
        output << p->data<<"  ";
    }
    return output;
}

auto Tree::save(const std::string& way) const -> bool {
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

auto Tree::save(std::ostream& stream, Node* node) const -> void {
  if (node != nullptr) {
    stream << node->data << " ";
    save(stream, node->left);
    save(stream, node->right);
  }
}

auto Tree::load(const std::string& way) -> bool {
  std::ifstream output(way);
  if (!output.is_open()) {
    return false;
  }
  this->~Tree();
  int t;
  while (!output.eof()) {
    output >> t;
    this->insert(t);
  }
  return true;
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
