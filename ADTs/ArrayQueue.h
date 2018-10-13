//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYQUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYQUEUE_H

#include "interfaces/Queue.h"

const int MAX_CAPACITY = 10;

template <typename E>
class ArrayQueue : public Queue<E> {
 private:
	E elements[MAX_CAPACITY];
	int head;
	int rear;

 public:
  bool isEmpty() const override;

  bool enqueue(const E &element) override;

  bool dequeue() override;

  E front() const override;
};

#include "ArrayQueue.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ARRAYQUEUE_H
