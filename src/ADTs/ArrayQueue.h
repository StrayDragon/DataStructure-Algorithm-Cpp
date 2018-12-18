//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYQUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYQUEUE_H

#include "exceptions/PreconditionFailedException.h"
#include "interfaces/Queue.h"

const int MAX_QUEUE_CAPACITY = 10;

template <typename E>
class ArrayQueue : public Queue<E> {
 private:
  E _elements[MAX_QUEUE_CAPACITY];
  int _head;
  int _rear;
  int _count;

 public:
  ArrayQueue();

  bool isEmpty() const override;

  bool enqueue(const E& element) override;

  bool dequeue() override;

  E front() const noexcept(false) override;
};

#include "ArrayQueue.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ARRAYQUEUE_H
