//
// Created by straydragon on 18-10-15.
//
#include "BinarySearchTree.h"

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_insertInOrder(BinaryNode<E>* subTreePtr,
                                                   BinaryNode<E>* newNodePtr) {
  if (subTreePtr == nullptr) {
    return newNodePtr;
  } else if (newNodePtr->getElement() < subTreePtr->getElement()) {
    auto* tmp = _insertInOrder(subTreePtr->getLeft(), newNodePtr);
    subTreePtr->setLeft(tmp);
  } else {
    auto* tmp = _insertInOrder(subTreePtr->getRight(), newNodePtr);
    subTreePtr->setRight(tmp);
  }
}

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_removeValue(BinaryNode<E>* subTreePtr,
                                                 const E& target,
                                                 bool& success) {
  if (subTreePtr == nullptr)
    success = false;
  else if (subTreePtr->getElement() == target) {
    subTreePtr = _removeNode(subTreePtr);
    success = true;
  } else if (subTreePtr->getElement() > target) {
    auto* tmp = _removeValue(subTreePtr->getLeft(), target, success);
    subTreePtr->setLeft(tmp);
  } else {
    auto* tmp = _removeValue(subTreePtr->getRight(), target, success);
    subTreePtr->setRight(tmp);
  }
  return subTreePtr;
}

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_removeNode(BinaryNode<E>* nodePtr) {
  if (nodePtr->isLeaf()) {
    // 没儿子
    delete nodePtr;
    nodePtr = nullptr;
    return nodePtr;
  } else if (nodePtr->getLeft() && !nodePtr->getRight()) {
    // 只有左儿子
    auto* tmp = nodePtr->getLeft();
    delete nodePtr;
    nodePtr = nullptr;
    return tmp;
  } else if (!nodePtr->getLeft() && nodePtr->getRight()) {
    // 只有右儿子
    auto* tmp = nodePtr->getRight();
    delete nodePtr;
    nodePtr = nullptr;
    return tmp;
  } else {
    // 有两个儿子
    E properNodeElement;
    auto getProperNodeElement = [&](E& e) -> void { properNodeElement = e; };
    BinaryNodeTree<E>::_inorderTraverseHelper(getProperNodeElement, nodePtr);
    auto* tmp = _removeLeftMostNode(nodePtr->getRight(), properNodeElement);
    nodePtr->setRight(tmp);
    nodePtr->setElement(properNodeElement);
    return nodePtr;
  }
}

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_removeLeftMostNode(
    BinaryNode<E>* subTreePtr,
    E& inorderSuccessor) {
  if (subTreePtr->getLeft() == nullptr) {
    inorderSuccessor = subTreePtr->getElement();
    return _removeNode(subTreePtr);
  } else
    return _removeLeftMostNode(subTreePtr->getLeft(), inorderSuccessor);
}

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_findNode(BinaryNode<E>* treePtr,
                                              const E& target,
                                              bool& success) {
  if (treePtr == nullptr)
    return nullptr;  //没找到 QwQ
  else if (treePtr->getElement() == target) {
    success = true;
    return treePtr;  //找到了 ^_^
  } else if (treePtr->getElement() < target)
    return _findNode(treePtr->getRight(), target,
                     success);  //目标好像在左面 (-;
  else
    return _findNode(treePtr->getLeft(), target, success);  //目标好像在右面 ;-)
}

template <typename E>
BinarySearchTree<E>::BinarySearchTree() : BinaryNodeTree<E>() {}

template <typename E>
BinarySearchTree<E>::BinarySearchTree(const E& rootElement)
    : BinaryNodeTree<E>(rootElement) {}

template <typename E>
BinarySearchTree<E>::BinarySearchTree(
    const BinarySearchTree<E>& binarySearchTree)
    : BinaryNodeTree<E>(binarySearchTree) {}

template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {
  BinaryNodeTree<E>::_destroyTree(_rootPtr);
}

template <typename E>
BinarySearchTree<E>& BinarySearchTree<E>::operator=(
    const BinarySearchTree<E>& binarySearchTree) {
  if (this != &binarySearchTree) {
    this->clear();
    this = _copyTree(binarySearchTree._rootPtr);
  }
  return *this;
}

// template <typename E>
// bool BinarySearchTree<E>::isEmpty() const {
//  return BinaryNodeTree<E>::isEmpty();
//}

// template <typename E>
// int BinarySearchTree<E>::getHeight() const {
//  return BinaryNodeTree<E>::_getHeightHelper(_rootPtr);
//}
//
// template <typename E>
// int BinarySearchTree<E>::getNumberOfNodes() const {
//  return BinaryNodeTree<E>::_getNumberOfNodesHelper(_rootPtr);
//}
//
// template <typename E>
// E BinarySearchTree<E>::getRootElement() const {
//  return BinaryNodeTree<E>::getRootElement();
//}
//
// template <typename E>
// void BinarySearchTree<E>::setRootElement(const E& element) {
//  BinaryNodeTree<E>::setRootElement(element);
//}

template <typename E>
bool BinarySearchTree<E>::add(const E& element) {
  auto* newNodePtr = new BinaryNode<E>(element);
  _rootPtr = _insertInOrder(_rootPtr, newNodePtr);
  return true;
}

template <typename E>
bool BinarySearchTree<E>::remove(const E& element) {
  bool removed = false;
  _removeValue(_rootPtr, element, removed);
  return removed;
}

// template <typename E>
// void BinarySearchTree<E>::clear() {
//  BinaryNodeTree<E>::clear();
//}
//
// template <typename E>
// E BinarySearchTree<E>::getElement(const E& element) const {
//  return BinaryNodeTree<E>::getElement(element);
//}

// template <typename E>
// bool BinarySearchTree<E>::contains(const E& element) const {
//  return BinaryNodeTree<E>::contains(element);
//}
//
// template <typename E>
// void BinarySearchTree<E>::preorderTraverse(void (*visit)(E&)) const {
//  BinaryNodeTree<E>::preorderTraverse(visit);
//}

// template <typename E>
// void BinarySearchTree<E>::inorderTraverse(void (*visit)(E&)) const {
//  BinaryNodeTree<E>::inorderTraverse(visit);
//}
//
// template <typename E>
// void BinarySearchTree<E>::postorderTraverse(void (*visit)(E&)) const {
//  BinaryNodeTree<E>::postorderTraverse(visit);
//}
