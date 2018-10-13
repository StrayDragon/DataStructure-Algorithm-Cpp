//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LINKEDQUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_LINKEDQUEUE_H

#include "LinkedList.h"
#include "interfaces/Queue.h"

template <typename E>
class LinkedQueue : public Queue<E> {
 private:
  LinkedList<E>* elememtsListPtr;

 public:
  LinkedQueue();

  LinkedQueue(const E& elememtsListPtr);

  virtual ~LinkedQueue();

  bool isEmpty() const override;

  bool enqueue(const E& element) override;

  bool dequeue() override;

  E front() const throw(PreconditionFailedException) override;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_LINKEDQUEUE_H
