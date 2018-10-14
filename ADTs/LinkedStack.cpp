//
// Created by straydragon on 18-10-13.
//

#include "LinkedStack.h"

template <typename E>
LinkedStack<E>::LinkedStack() : _elementsTopPtr(nullptr) {}

template <typename E>
LinkedStack<E>::LinkedStack(const LinkedStack<E> &linkedStack) {
  Node<E> *oldStackChainsPtr = linkedStack._elementsTopPtr;
  if (oldStackChainsPtr == nullptr) {
    _elementsTopPtr = nullptr;
  } else {  //深拷贝元素
    //获取旧栈的栈顶元素
    _elementsTopPtr = new Node<E>(oldStackChainsPtr->getElement(), nullptr);

    //依次复制其他元素
    Node<E> *newStackChainsPtr = _elementsTopPtr;
    while (oldStackChainsPtr->getNext() != nullptr) {
      oldStackChainsPtr = oldStackChainsPtr->getNext();
      E nextElement = oldStackChainsPtr->getElement();

      auto *node = new Node<E>(nextElement);
      newStackChainsPtr->setNext(node);
      newStackChainsPtr = newStackChainsPtr->getNext();
    }
    newStackChainsPtr->setNext(nullptr);
  }
}

template <typename E>
LinkedStack<E>::~LinkedStack() {
  while (!isEmpty()) pop();
};

template <typename E>
bool LinkedStack<E>::isEmpty() const {
  return _elementsTopPtr == nullptr;
}

template <typename E>
bool LinkedStack<E>::push(const E &element) {
  auto *node = new Node<E>(element, _elementsTopPtr);
  _elementsTopPtr = node;
  return true;
  //暂不考虑new失败情况
}

template <typename E>
bool LinkedStack<E>::pop() {
  bool wasPoped = false;
  if (!isEmpty()) {
    auto *willDeleteNode = _elementsTopPtr;
    _elementsTopPtr = _elementsTopPtr->getNext();

    delete willDeleteNode;

    wasPoped = true;
  }

  return wasPoped;
}

template <typename E>
E LinkedStack<E>::top() const {
  assert(!isEmpty());

  return _elementsTopPtr->getElement();
}
