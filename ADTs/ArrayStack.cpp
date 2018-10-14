//
// Created by straydragon on 18-10-13.
//

#include "ArrayStack.h"

template <typename E>
ArrayStack<E>::ArrayStack() : _top(-1) {}

template <typename E>
bool ArrayStack<E>::isEmpty() const {
  return _top < 0;
}

template <typename E>
bool ArrayStack<E>::push(const E &element) {
  bool canPushed = false;
  if (_top < MAX_STACK_CAPACITY - 1) {
    _top++;
    _elements[_top] = element;
    canPushed = true;
  }
  return canPushed;
}

template <typename E>
bool ArrayStack<E>::pop() {
  bool wasPopped = false;
  if (!isEmpty()) {
    _top--;
    wasPopped = true;
  }
  return wasPopped;
}

template <typename E>
E ArrayStack<E>::top() const {
  assert(!isEmpty());

  return _elements[_top];
}
