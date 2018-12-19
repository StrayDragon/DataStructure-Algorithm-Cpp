//
// Created by straydragon on 18-12-18.
//
#include "gtest/gtest.h"

#include "../src/ADTs/ArrayQueue.h"
#include "../src/ADTs/LinkedQueue.h"
#include "../src/ADTs/ListQueue.h"
#include "../src/ADTs/interfaces/Queue.h"

template<typename E>
void QueueInterfaceTestSuit(Queue<E>* queue) {
  // if (typeid(*queue) == typeid(LinkedQueue<E>)) {
  //   LinkedQueue<E> linkedQueue;
  //   linkedQueue.enqueue(1);
  //   queue = new LinkedQueue<E>(linkedQueue);
  //   EXPECT_TRUE(queue->dequeue());
  // }  // FIXME:LinkedQueue<E>拷贝构造函数有点问题,见定义处注释

  EXPECT_TRUE(queue->isEmpty());

  for (int i = 0; i < MAX_QUEUE_CAPACITY; i++) {
    EXPECT_TRUE(queue->enqueue(i));
  }

  if (typeid(*queue) == typeid(ArrayQueue<E>)) {
    EXPECT_TRUE(!queue->enqueue(-1));
  }

  for (int i = 0; i < MAX_QUEUE_CAPACITY; i++) {
    EXPECT_TRUE(queue->front() == i);
    EXPECT_TRUE(queue->dequeue());
  }
  EXPECT_TRUE(!queue->dequeue());

}

TEST(ADTs_Queue_Interface, impl_ArrayQueue_int) { // NOLINT(cert-err58-cpp)
  auto* arrayQueue = new ArrayQueue<int>();
  QueueInterfaceTestSuit(arrayQueue);
  delete arrayQueue;
}

TEST(ADTs_Queue_Interface, impl_LinkedQueue_int) { // NOLINT(cert-err58-cpp)
  auto* linkedQueue = new LinkedQueue<int>();
  QueueInterfaceTestSuit(linkedQueue);
  delete linkedQueue;
}

TEST(ADTs_Queue_Interface, impl_ListQueue_int) { // NOLINT(cert-err58-cpp)
  auto* listQueue = new ListQueue<int>();
  QueueInterfaceTestSuit(listQueue);
  delete listQueue;
}


