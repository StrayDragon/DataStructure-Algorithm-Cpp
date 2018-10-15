//
// Created by straydragon on 18-10-13.
//

#include "LinkedList.h"

template <typename E>
Node<E> *LinkedList<E>::_getNodeAt(int position) const {
  assert((position >= 1) && (position <= _length));

  Node<E> *curNode = _elementsHeadPtr;
  for (int i = 1; i < position; i++) curNode = curNode->getNext();

  return curNode;
}

template <typename E>
LinkedList<E>::LinkedList() : _elementsHeadPtr(nullptr), _length(0) {}

template <typename E>
LinkedList<E>::LinkedList(const LinkedList<E> &linkedList) {
  for (int i = 1; i < linkedList._length; ++i) {
    insert(i,(linkedList._elementsHeadPtr)->getElement());
  }
}

template <typename E>
LinkedList<E>::~LinkedList() {
  clear();
}

template <typename E>
bool LinkedList<E>::isEmpty() const {
  return _length == 0;
}

template <typename E>
int LinkedList<E>::getLength() const {
  return _length;
}

template <typename E>
bool LinkedList<E>::insert(int newPosition, const E &element) {
  bool canInsert = 1 <= newPosition && newPosition <= _length + 1;
  if (canInsert) {
    auto *node = new Node<E>(element);
    if (newPosition == 1) {
      //插入节点到链表头
      node->setNext(_elementsHeadPtr);
      _elementsHeadPtr = node;
    } else {
      Node<E> *prevNode = _getNodeAt(newPosition - 1);
      node->setNext(prevNode->getNext());
      prevNode->setNext(node);
    }
    _length++;
  }

  return canInsert;
}

template <typename E>
bool LinkedList<E>::remove(int position) {
  bool canRemove = (1 <= position && position <= _length);
  if (canRemove) {
    Node<E> *curNode = nullptr;
    if (position == 1) {
      curNode = _elementsHeadPtr;
      _elementsHeadPtr = _elementsHeadPtr->getNext();
    } else {
      Node<E> *prevNode = _getNodeAt(position - 1);
      curNode = prevNode->getNext();
      prevNode->setNext(curNode->getNext());
    }
    curNode->setNext(nullptr);
    delete curNode;
    _length--;
  }
  return canRemove;
}

template <typename E>
void LinkedList<E>::clear() {
  if (_length != 0) {
    for (int i = _length; i >= 1; i--) {
      remove(i);
    }
    _length = 0;
  }
}

template <typename E>
E LinkedList<E>::getElementAt(int position) noexcept(false) {
  if (1 <= position && position <= _length) {
    Node<E> *targetNode = _getNodeAt(position);
    return targetNode->getElement();
  } else {
    std::string msg = std::string(typeid(this).name()) +
                      " 目标位置(position = " + std::to_string(position);
    msg += ")不符合条件,检查是否在区间[1,getLength()]中!";
    throw PreconditionFailedException(msg);
  }
}

template <typename E>
void LinkedList<E>::setElementAt(int position, E &&element) noexcept(false) {
  if (1 <= position && position <= _length) {
    Node<E> *targetNode = _getNodeAt(position);
    return targetNode->setElement(element);
  } else {
    std::string msg = std::string(typeid(this).name()) +
                      " 目标位置(position = " + std::to_string(position);
    msg += ")不符合条件,检查是否在区间[1,getLength()]中!";
    throw PreconditionFailedException(msg);
  }
}
