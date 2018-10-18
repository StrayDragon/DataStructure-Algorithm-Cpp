//
// Created by straydragon on 18-10-13.
//

#include "ArrayQueue.h"

template <typename E>
ArrayQueue<E>::ArrayQueue()
    : _head(0), _rear(MAX_QUEUE_CAPACITY - 1), _count(0) {}

template <typename E>
bool ArrayQueue<E>::isEmpty() const {
  return _count == 0;
}

template <typename E>
bool ArrayQueue<E>::enqueue(const E& element) {
  bool canEnqueue = false;

  if (_count < MAX_QUEUE_CAPACITY) {
    _rear = (_rear + 1) % MAX_QUEUE_CAPACITY;
    _elements[_rear] = element;
    _count++;
    canEnqueue = true;
  }

  return canEnqueue;
}

template <typename E>
bool ArrayQueue<E>::dequeue() {
  bool canDequeue = false;

  if (!isEmpty()) {
    _head = (_head + 1) % MAX_QUEUE_CAPACITY;
    _count--;
    canDequeue = true;
  }

  return canDequeue;
}

template <typename E>
E ArrayQueue<E>::front() const noexcept(false) {
  if (isEmpty())
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " front():队列为空\n");

  return _elements[_head];
}
