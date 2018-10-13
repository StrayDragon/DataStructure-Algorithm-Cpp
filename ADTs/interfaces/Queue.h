//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_QUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_QUEUE_H

template <typename E>
class Queue {
 public:
  virtual bool isEmpty() const = 0;

  virtual bool enqueue(const E& element) = 0;

  virtual bool dequeue() = 0;
  virtual E front() const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_QUEUE_H
