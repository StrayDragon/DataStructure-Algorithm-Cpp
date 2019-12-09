//
// Created by straydragon on 18-10-21.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_DICTIONARY_H
#define DATASTRUCTURE_ALGORITHM_CPP_DICTIONARY_H

#include "../exceptions/NotFoundException.h"

/**
 * @brief 字典(Dictionary) 接口声明
 *
 * @tparam E 元素类型
 */
template <typename K, typename V>
class Dictionary {
 public:
  virtual bool isEmpty() const = 0;
  virtual int getNumberOfPairs() const = 0;
  virtual bool add(const K& key, const V& value) = 0;
  virtual bool remove(const K& key) = 0;
  virtual void clear() = 0;
  virtual V getValueByKey(const K& key) const throw(NotFoundException) = 0;
  virtual bool contain(const K& key) const = 0;
  virtual void traverse(void (*visit)(V&)) const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_DICTIONARY_H
