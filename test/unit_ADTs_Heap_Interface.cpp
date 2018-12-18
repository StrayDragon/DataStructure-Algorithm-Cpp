//
// Created by straydragon on 18-12-18.
//
#include "gtest/gtest.h"

#include "../src/ADTs/ArrayHeap.h"
#include "../src/ADTs/interfaces/Heap.h"

template<typename E, typename Comp = std::greater<E>>
void HeapInterfaceTestSuit(Heap<E>* heap) {
#ifdef DEBUG
  auto downCastClass = [](Heap<E>* h) -> ArrayHeap<E>* {
    return dynamic_cast<ArrayHeap<E, Comp>*>(h);
  };

  cout << "\n" << downCastClass(heap) << endl;
#endif
  EXPECT_TRUE(not heap->isEmpty());
  EXPECT_TRUE(heap->getNumberOfElements() == 6);
  EXPECT_TRUE(heap->getHeight() == 3);
  // while (!heap->isEmpty())
  //   EXPECT_TRUE(heap->remove());

  heap->clear();

  EXPECT_TRUE(heap->isEmpty());
  EXPECT_TRUE(heap->add(7));
  EXPECT_TRUE(heap->add(3));
  EXPECT_TRUE(heap->add(5));
  EXPECT_TRUE(heap->add(2));
  EXPECT_TRUE(heap->add(11));

  int previous = heap->top();
  EXPECT_TRUE(heap->remove());
  int current = heap->top();
  while (true) {
    if (typeid(*heap) == typeid(ArrayHeap<E, std::greater<E>>)) {
      EXPECT_TRUE(previous > current);
    } else {
      EXPECT_TRUE(previous < current);
    }
    previous = current;
    EXPECT_TRUE(heap->remove());
    if (heap->isEmpty())
      break;
    else
      current = heap->top();
  }
  heap->clear();
  EXPECT_TRUE(heap->isEmpty());
}

TEST(ADTs_Heap_Interface, impl_ArrayHeap_int_std$greater) { // NOLINT(cert-err58-cpp)
  auto* maxHeap = new ArrayHeap<int>({6, 3, 5, 9, 2, 10});  //最大堆
  HeapInterfaceTestSuit(maxHeap);
}

TEST(ADTs_Heap_Interface, impl_ArrayHeap_int_std$less) { // NOLINT(cert-err58-cpp)
  auto* minHeap = new ArrayHeap<int, std::less<int>>({6, 3, 5, 9, 2, 10});  //最小堆
  HeapInterfaceTestSuit(minHeap);
}

