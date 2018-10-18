//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LINKEDQUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_LINKEDQUEUE_H

#include "Node.h"
#include "exceptions/PreconditionFailedException.h"
#include "interfaces/Queue.h"
template <typename E>
class LinkedQueue : public Queue<E> {
 private:
  Node<E>* _headPtr;
  Node<E>* _rearPtr;

 public:
  LinkedQueue();

  explicit LinkedQueue(const E& linkedQueue);

  virtual ~LinkedQueue();

  bool isEmpty() const override;

  bool enqueue(const E& element) override;

  bool dequeue() override;

  E front() const noexcept(false) override;  // throw
                                             // PreconditionFailedException
};

#include "LinkedQueue.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_LINKEDQUEUE_H
