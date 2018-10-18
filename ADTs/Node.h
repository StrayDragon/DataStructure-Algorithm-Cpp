//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_NODE_H
#define DATASTRUCTURE_ALGORITHM_CPP_NODE_H

/**
 * @brief 结点POCO(Plain Ordinary Cpp Object)类
 *
 * @tparam E 元素类型
 */
template <typename E>
class Node {
 private:
  E _element;
  Node<E>* _next;

 public:
  Node() : _next(nullptr){};

  explicit Node(const E& element) : _element(element), _next(nullptr) {}

  Node(const E& element, Node<E>* next) : _element(element), _next(next) {}

  void setElement(const E& element) { _element = element; }

  void setNext(Node<E>* next) { _next = next; }

  E getElement() const { return _element; }

  Node<E>* getNext() const { return _next; }
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_NODE_H
