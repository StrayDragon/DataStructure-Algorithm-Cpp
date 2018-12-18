//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYLIST_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYLIST_H

#include "exceptions/PreconditionFailedException.h"
#include "interfaces/List.h"

template <typename E>
class ArrayList : public List<E> {
  static const int DEFAULT_CAPACITY = 10;

 private:
  E _elements[DEFAULT_CAPACITY];
  int _length;
  int _maxCapacity;

 public:
  ArrayList();

  bool isEmpty() const override;
  int getLength() const override;
  bool insert(int newPosition, const E& element) override;

  bool remove(int position) override;

  void clear() override;

  // TODO:这俩货的命名改成get/setElementLogicallyAt会不会更好些2333333
  E getElementAt(int position) noexcept(false) override;

  void setElementAt(int position, E&& element) noexcept(false) override;
};

#include "ArrayList.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ARRAYLIST_H
