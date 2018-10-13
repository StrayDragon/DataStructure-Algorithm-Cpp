//
// Created by straydragon on 18-10-13.
//

#include "Node.h"

template <typename E>
Node<E>::Node() {}

template <typename E>
Node<E>::Node(const E &element) {}

template <typename E>
Node<E>::Node(const E &elememt, Node<E> *next) {}

template <typename E>
void Node<E>::setElement(E element) {}

template <typename E>
void Node<E>::setNext(const Node<E> &next) {}

template <typename E>
E Node<E>::getElement() const {
  return nullptr;
}

template <typename E>
Node<E> &Node<E>::getNext() const {
  return Node<E>();
}
