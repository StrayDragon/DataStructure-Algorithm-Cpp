//
// Created by straydragon on 18-10-13.
//

#include "Node.h"

template <typename E>
Node<E>::Node() : _next(nullptr) {}

template <typename E>
Node<E>::Node(const E &element) : _element(element), _next(nullptr) {}

template <typename E>
Node<E>::Node(const E &element, Node<E> *next)
    : _element(element), _next(next) {}

template <typename E>
void Node<E>::setElement(const E& element) {
  _element = element;
}

template <typename E>
void Node<E>::setNext(Node<E>* next) {//TODO:原来参数为(const Node<E>* next)
  _next = next;
}

template <typename E>
E Node<E>::getElement() const {
  return _element;
}

template <typename E>
Node<E>* Node<E>::getNext() const {
  return _next;
}
