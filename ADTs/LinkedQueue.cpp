//
// Created by straydragon on 18-10-13.
//

#include "LinkedQueue.h"

template <typename E>
LinkedQueue<E>::LinkedQueue() : _headPtr(nullptr), _rearPtr(nullptr) {}

// template <typename E>
// LinkedQueue<E>::LinkedQueue(const E &linkedQueue) {
//   if (linkedQueue.isEmpty()) {
//     _headPtr = _rearPtr = nullptr;
//   } else {
//     auto *oldChainsPtr = linkedQueue._headPtr;
//     while (oldChainsPtr != linkedQueue._rearPtr) {
//       enqueue(oldChainsPtr->getElement());
//       oldChainsPtr = oldChainsPtr->getNext();
//     }
//     enqueue(oldChainsPtr->getElement());
//   }
// }  // FIXME:有点问题,关联enqueue()::中在new一个Node<E>对象时报SF...

template <typename E>
LinkedQueue<E>::LinkedQueue(const E &linkedQueue)
    : _headPtr(linkedQueue._headPtr),
      _rearPtr(linkedQueue._rearPtr) {}  //浅拷贝

template <typename E>
LinkedQueue<E>::~LinkedQueue() {
  while (!isEmpty()) dequeue();
}

template <typename E>
bool LinkedQueue<E>::isEmpty() const {
  return (_headPtr == nullptr && _rearPtr == nullptr);
}

template <typename E>
bool LinkedQueue<E>::enqueue(const E &element) {
  auto *node = new Node<E>(element);
  if (isEmpty())
    _headPtr = node;
  else {
    _rearPtr->setNext(node);  // 保持_headPtr->getNext()有效
  }

  _rearPtr = node;
  return true;
}

template <typename E>
bool LinkedQueue<E>::dequeue() {
  bool canDequeue = false;
  if (!isEmpty()) {
    Node<E> *willDeleteNode = _headPtr;
    if (_headPtr == _rearPtr)
      _headPtr = _rearPtr = nullptr;
    else
      _headPtr = _headPtr->getNext();
    delete willDeleteNode;
    canDequeue = true;
  }
  return canDequeue;
}

template <typename E>
E LinkedQueue<E>::front() const noexcept(false) {
  if (isEmpty())
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " front():队列为空\n");
  return _headPtr->getElement();
}
