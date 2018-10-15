//
// Created by straydragon on 18-10-15.
//

#include "ListQueue.h"

template <typename E>
ListQueue<E>::ListQueue() {
  _elementsPtr = new LinkedList<E>();
}

template <typename E>
ListQueue<E>::ListQueue(const ListQueue &listQueue)
    : _elementsPtr(listQueue._elementsPtr) {}

template <typename E>
ListQueue<E>::~ListQueue() {}

template <typename E>
bool ListQueue<E>::isEmpty() const {
  return _elementsPtr->isEmpty();
}

template <typename E>
bool ListQueue<E>::enqueue(const E &element) {
  return _elementsPtr->insert(_elementsPtr->getLength() + 1, element);
}

template <typename E>
bool ListQueue<E>::dequeue() {
  return _elementsPtr->remove(1);
}

template <typename E>
E ListQueue<E>::front() const noexcept(false) {
  if (isEmpty())
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " front():队列为空\n");

  return _elementsPtr->getElementAt(1);
}
