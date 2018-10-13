//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LIST_H
#define DATASTRUCTURE_ALGORITHM_CPP_LIST_H

template <typename E>
class List {
 public:
  virtual bool isEmpty() const = 0;
  virtual int getLength() const = 0;
  virtual bool insert(int newPosition, const E& element) = 0;
  virtual bool remove(int position) = 0;
  virtual void clear() = 0;
  virtual E getElementAt(int position) = 0;
  virtual E setElementAt(int position, E& element) = 0;
};
#endif  // DATASTRUCTURE_ALGORITHM_CPP_LIST_H
