//
// Created by straydragon on 18-10-14.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_TREENODEC_H
#define DATASTRUCTURE_ALGORITHM_CPP_TREENODEC_H

template <typename E>
class TreeNode {
 private:
  E _element;
  int _leftChild;
  int _rightChild;

 public:
  TreeNode() : _leftChild(0), _rightChild(0){};
  
  TreeNode(const E& element, int left, int right)
      : _element(element), _leftChild(left), _rightChild(right);

  E getElement() const { return _element; }

  void setElement(E element) { _element = element; }

  int getLeftChild() const { return _leftChild; }

  void setLeftChild(int leftChild) { _leftChild = leftChild; }

  int getRightChild() const { return _rightChild; }

  void setRightChild(int rightChild) { _rightChild = rightChild; }
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_TREENODEC_H
