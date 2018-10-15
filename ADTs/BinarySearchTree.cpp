//
// Created by straydragon on 18-10-15.
//

#include "BinarySearchTree.h"

template <typename E>
BinaryNode<E> *BinarySearchTree<E>::_insertInOrder(BinaryNode<E> *subTreePtr,
                                                   BinaryNode<E> *newNode) {
  return BinaryNode<E>();
}

template <typename E>
BinaryNode<E> *BinarySearchTree<E>::_removeElement(BinaryNode<E> *subTreePtr,
                                                   const E &target,
                                                   bool &success) {
  return BinaryNode<E>();
}

template <typename E>
BinaryNode<E> *BinarySearchTree<E>::_removeNode(BinaryNode<E> *nodePtr) {
  return BinaryNode<E>();
}

template <typename E>
BinaryNode<E> *BinarySearchTree<E>::_removeLeftLeafNode(
    BinaryNode<E> *subTreePtr, E &inorderSuccessor) {
  return BinaryNode<E>();
}

template <typename E>
BinaryNode<E> *BinarySearchTree<E>::_findNode(BinaryNode<E> *treePtr,
                                              const E &target, bool &success) {
  return BinaryNode<E>();
}

template <typename E>
BinarySearchTree<E>::BinarySearchTree() {}

template <typename E>
BinarySearchTree<E>::BinarySearchTree(const E &rootElement) {}

template <typename E>
BinarySearchTree<E>::BinarySearchTree(
    const BinarySearchTree<E> &binarySearchTree) {}

template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {}

template <typename E>
BinarySearchTree<E> &BinarySearchTree<E>::operator=(
    const BinarySearchTree<E> &binarySearchTree) {
  return BinaryNode<E>();
}

template <typename E>
bool BinarySearchTree<E>::isEmpty() const {
  return false;
}

template <typename E>
int BinarySearchTree<E>::getHeight() const {
  return 0;
}

template <typename E>
int BinarySearchTree<E>::getNumberOfNodes() const {
  return 0;
}

template <typename E>
E BinarySearchTree<E>::getRootElement() const {
  return E();
}

template <typename E>
void BinarySearchTree<E>::setRootElement(const E &element) {}

template <typename E>
bool BinarySearchTree<E>::add(const E &element) {
  return false;
}

template <typename E>
bool BinarySearchTree<E>::remove(const E &element) {
  return false;
}

template <typename E>
void BinarySearchTree<E>::clear() {}

template <typename E>
E BinarySearchTree<E>::getElement(const E &element) const {
  return E();
}

template <typename E>
bool BinarySearchTree<E>::contains(const E &element) const {
  return false;
}

template <typename E>
void BinarySearchTree<E>::preorderTraverse(void (*visit)(E &)) const {}

template <typename E>
void BinarySearchTree<E>::inorderTraverse(void (*visit)(E &)) const {}

template <typename E>
void BinarySearchTree<E>::postorderTraverse(void (*visit)(E &)) const {}
