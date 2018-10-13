//
// Created by straydragon on 18-10-13.
//

#include "LinkedList.h"

template <typename E>
Node<E> *LinkedList<E>::_getNodeAt(int Position) const {
  return nullptr;
}

template <typename E>
LinkedList<E>::LinkedList() {}

template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E> &aLinkedList) {}

template <typename E>
LinkedList<E>::~LinkedList() {}

template <typename E>
bool LinkedList<E>::isEmpty() const {
  return false;
}

template <typename E>
int LinkedList<E>::getLength() const {
  return 0;
}

template <typename E>
bool LinkedList<E>::insert(int newPosition, const E &element) {
  return false;
}

template <typename E>
bool LinkedList<E>::remove(int position) {
  return false;
}

template <typename E>
void LinkedList<E>::clear() {}

template <typename E>
E LinkedList<E>::getElementAt(int position) throw(PreconditionFailedException) {
  return nullptr;
}

template <typename E>
void LinkedList<E>::setElementAt(int position, E &element) throw(
    PreconditionFailedException) {}
