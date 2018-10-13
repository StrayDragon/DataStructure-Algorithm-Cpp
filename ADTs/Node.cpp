//
// Created by straydragon on 18-10-13.
//

#include "Node.h"

template <typename E>
Node<E>::Node() : _next(nullptr) {}

template <typename E>
Node<E>::Node(const E &element) : _element(element), _next(nullptr) {}

template <typename E>
Node<E>::Node(const E &elememt, Node<E> *next)
    : _element(elememt), _next(next) {}

template <typename E>
void Node<E>::setElement(E element) {
  _element = element;
}

template <typename E>
void Node<E>::setNext(const Node<E> &next) {
  _next = next;
}

template <typename E>
E Node<E>::getElement() const {
  return _element;
}

template <typename E>
Node<E> &Node<E>::getNext() const {
  return _next;
}
