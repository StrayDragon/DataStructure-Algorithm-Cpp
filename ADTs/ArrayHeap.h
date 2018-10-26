//
// Created by straydragon on 18-10-25.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYHEAP_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYHEAP_H

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include "interfaces/Heap.h"
#include "exceptions/PreconditionFailedException.h"

template <typename E, typename Compare = std::greater<E>>
class ArrayHeap : public Heap<E> {
  // 默认 _comp( lhs , rhs ):  lhs > rhs ? true : false;
  Compare _comp;

 private:
  static const int ROOT_INDEX = 0;  //可读性
  static const int DEFAULT_CAPACITY = 31;
  E* _elements;
  int _countOfElements;
  int _maxCapacity;

  int _getHeightHelper(int index) const;
  int _getLeftChildIndex(int nodeIndex) const;
  int _getRightChildIndex(int nodeIndex) const;
  int _getParentIndex(int nodeIndex) const;
  int _isLeaf(int nodeIndex) const;
  void _heapRebuild(int subTreeRootIndex);
  void _heapCreate();

 public:
  friend std::ostream& operator<<(std::ostream& out,
                                  const ArrayHeap<E, Compare>* arrayHeapPtr) {
    for (int i = 0; i < arrayHeapPtr->_countOfElements; ++i) {
      out << arrayHeapPtr->_elements[i] << " ";
    }
    return out;
  }

 public:
  ArrayHeap();

  ArrayHeap(const E elements[], int length);

  ArrayHeap(std::initializer_list<E> elements);

  virtual ~ArrayHeap();

  bool isEmpty() const override;

  int getNumberOfElements() const override;

  int getHeight() const override;

  E top() const noexcept(false) override;

  bool add(const E& element) override;

  bool remove() override;

  void clear() override;
};

#include "ArrayHeap.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ARRAYHEAP_H
