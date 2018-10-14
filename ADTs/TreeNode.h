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

  E get_element() const { return _element; }

  void set_element(E _element) { TreeNode::_element = _element; }

  int get_leftChild() const { return _leftChild; }

  void set_leftChild(int _leftChild) { TreeNode::_leftChild = _leftChild; }

  int get_rightChild() const { return _rightChild; }

  void set_rightChild(int _rightChild) { TreeNode::_rightChild = _rightChild; }
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_TREENODEC_H
