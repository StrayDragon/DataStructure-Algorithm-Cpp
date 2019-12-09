//
// Created by straydragon on 18-10-14.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYNODE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYNODE_H

/**
 * @brief 二叉树基于链表(自引用)形式的树结点实现
 *
 * @tparam E 元素类型
 */
template <typename E>
class BinaryNode {
 private:
  E _element;
  BinaryNode<E>* _left;
  BinaryNode<E>* _right;

 public:
  BinaryNode() : _left(nullptr), _right(nullptr) {}

  BinaryNode(const E& element)
      : _element(element), _left(nullptr), _right(nullptr) {}

  BinaryNode(const E& element, BinaryNode<E>* left, BinaryNode<E>* right)
      : _element(element), _left(left), _right(right) {}

  bool isLeaf() const { return (_left == nullptr && _right == nullptr); }

  E getElement() const { return _element; }

  void setElement(E element) { _element = element; }

  BinaryNode<E>* getLeft() const { return _left; }

  void setLeft(BinaryNode<E>* left) { _left = left; }

  BinaryNode<E>* getRight() const { return _right; }

  void setRight(BinaryNode<E>* right) { _right = right; }
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYNODE_H
