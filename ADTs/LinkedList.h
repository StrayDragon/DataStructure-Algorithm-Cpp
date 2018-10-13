//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LINKEDLIST_H
#define DATASTRUCTURE_ALGORITHM_CPP_LINKEDLIST_H

#include "Node.h"
#include "interfaces/List.h"

template <typename E>
class LinkedList : public List<E> {
 private:
  Node<E>* _elementsHeadPtr;
  int _length;
  Node<E>* _getNodeAt(int Position) const;

 public:
  LinkedList();
  LinkedList(const LinkedList<E>& aLinkedList);
  virtual ~LinkedList();

  bool isEmpty() const override;

  int getLength() const override;

  bool insert(int newPosition, const E& element) override;

  bool remove(int position) override;

  void clear() override;

  E getElementAt(int position) throw(PreconditionFailedException) override ;//TODO:Exceptions headers implementation;

  E setElementAt (int position, E& element) throw(PreconditionFailedException) override ;//TODO:Exceptions headers implementation;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_LINKEDLIST_H
