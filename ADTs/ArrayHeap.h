//
// Created by straydragon on 18-10-25.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYHEAP_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYHEAP_H

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include "exceptions/PreconditionFailedException.h"
#include "interfaces/Heap.h"

/**
 * @brief 基于数组实现的堆
 *
 * 默认是最大堆,可向泛型的第二个参数,传入返回一个bool值的用于比较可调用对象,<br>
 * 实现最小堆,建议使用std::less<E>这个泛型对象
 * @tparam E 元素类型
 * @tparam Compare 默认为std::greater<E>,即最大堆;
 */
template <typename E, typename Compare = std::greater<E>>
class ArrayHeap : public Heap<E> {
  /**
   * @brief 默认为std::greater<E>
   * 即 _comp(a,b) -> bool { return a > b;}
   */
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

  /**
   * @brief 用于将半堆转换为堆
   *
   * @param subTreeRootIndex 子堆(树)的根节点
   */
  void _heapRebuild(int subTreeRootIndex);

  /**
   * @brief 用于从无序数组或初始化列表创建堆
   */
  void _heapCreate();

 public:
  //方便debug打印堆内部维护的数组的元素顺序
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
