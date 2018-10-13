//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_ARRAYLIST_H
#define DATASTRUCTURE_ALGORITHM_CPP_ARRAYLIST_H

#include "interfaces/List.h"

template <typename E>
class ArrayList : public List<E> {
  static const int DEFAULT_CAPACITY = 100;

 private:
  E elements[DEFAULT_CAPACITY];
  int _length;
  int _max_capacity;

 public:
  ArrayList();

  bool isEmpty() const override;
  int getLength() const override;

  bool insert(int newPosition, const E &element) override;

  bool remove(int position) override;

  void clear() override;

  E getElementAt(int position) override;

  E setElementAt(int position, E &element)  throw(PreconditionFailedException) override; //TODO:Exceptions headers implementation;
};

#include "ArrayList.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_ARRAYLIST_H
