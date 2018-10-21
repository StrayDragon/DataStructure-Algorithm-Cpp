//
// Created by straydragon on 18-10-21.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_HEAP_H
#define DATASTRUCTURE_ALGORITHM_CPP_HEAP_H

/**
 * @brief 堆(Heap) 接口声明
 *
 * @tparam E 元素类型
 */
template <typename E>
class Heap {
 public:
  virtual bool isEmpty() const = 0;
  virtual int getNumberOfElements() const = 0;
  virtual int getHeight() const = 0;
  virtual E top() const = 0;
  virtual bool add(const E& element) = 0;
  virtual bool remove() = 0;
  virtual void clear() = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_HEAP_H
