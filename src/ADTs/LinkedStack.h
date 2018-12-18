//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LINKEDSTACK_H
#define DATASTRUCTURE_ALGORITHM_CPP_LINKEDSTACK_H

#include "Node.h"
#include "interfaces/Stack.h"

template <typename E>
class LinkedStack : public Stack<E> {
 private:
  Node<E>* _elementsTopPtr;

 public:
  LinkedStack();

  LinkedStack(const LinkedStack<E>& aStack);

  virtual ~LinkedStack();

  bool isEmpty() const override;

  bool push(const E& element) override;

  bool pop() override;

  E top() const override;
};

#include "LinkedStack.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_LINKEDSTACK_H
