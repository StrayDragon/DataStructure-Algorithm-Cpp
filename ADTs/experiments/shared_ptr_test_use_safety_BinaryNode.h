//
// Created by straydragon on 18-10-19.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_SHARED_PTR_TEST_USE_SAFETY_BINARYNODE_H
#define DATASTRUCTURE_ALGORITHM_CPP_SHARED_PTR_TEST_USE_SAFETY_BINARYNODE_H

#include <iostream>
#include <memory>

template <class E>
class BinaryNode {
 private:
  E _element;
  std::shared_ptr<BinaryNode<E>> _left;
  std::shared_ptr<BinaryNode<E>> _right;

 public:
  BinaryNode() = default;

  explicit BinaryNode(const E& element) : _element(element) {}

  BinaryNode(const E& element,
             std::shared_ptr<BinaryNode<E>> leftPtr,
             std::shared_ptr<BinaryNode<E>> rightPtr)
      : _element(element), _left(leftPtr), _right(rightPtr) {}

  bool isLeaf() const { return (_left == nullptr && _right == nullptr); }

  E getElement() const { return _element; }

  void setElement(E element) { _element = element; }

  BinaryNode<E>* getLeft() const { return _left; }

  void setLeft(std::shared_ptr<BinaryNode<E>> left) {
    std::cout << "临时的shared_ptr对象计数 : \t\t" << left.use_count()
              << std::endl;
    std::cout << "BinaryNode内部的shared_ptr对象计数 : \t" << left.use_count()
              << std::endl;
    _left = left;
  }

  BinaryNode<E>* getRight() const { return _right; }

  void setRight(std::shared_ptr<BinaryNode<E>> right) { _right = right; }

};      // end BinaryNode
#endif  // DATASTRUCTURE_ALGORITHM_CPP_SHARED_PTR_TEST_USE_SAFETY_TREENODE_H
