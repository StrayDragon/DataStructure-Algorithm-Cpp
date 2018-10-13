//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYSTACK_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYSTACK_H

#include "interfaces/Stack.h"

const int MAX_CAPACITY = 10;

template <typename E>
class ArrayStack : public Stack<E> {
 private:
  E _e[MAX_CAPACITY];
  int _top;

 public:
  ArrayStack();

  bool isEmpty() const override;

  bool push(const E &e) override;

  bool pop() override;

  E top() const override;
};

#include "ArrayBag.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ARRAYSTACK_H
