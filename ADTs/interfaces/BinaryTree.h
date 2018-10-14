//
// Created by straydragon on 18-10-14.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H

#include "../exceptions/NotFoundException.h"

template <typename E>
class BinaryTree {
 public:
  virtual bool isEmpty() const = 0;
  virtual int getHeight() const = 0;
  virtual int getNumberOfNodes() const = 0;
  virtual E getRootElement() const = 0;
  virtual void setRootElement(const E& element) = 0;
  virtual bool add(const E& element) = 0;
  virtual bool remove(const E& element) = 0;
  virtual void clear() = 0;
  virtual E getElement(const E& element) const noexcept(false) = 0;
  virtual bool contains(const E& element) const = 0;
  virtual void preorderTraverse(void visit(E&)) const = 0;
  virtual void inorderTraverse(void visit(E&)) const = 0;
  virtual void postorderTraverse(void visit(E&)) const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H
