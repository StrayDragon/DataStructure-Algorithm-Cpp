//
// Created by straydragon on 18-10-15.
//

#include "BinaryNodeTree.h"

template <typename E>
int BinaryNodeTree<E>::_getHeightHelper(BinaryNode<E>* subTreePtr) const {
  return 0;
}

template <typename E>
int BinaryNodeTree<E>::_getNumberOfNodesHelper(
    BinaryNode<E>* subTreePtr) const {
  return 0;
}

template <typename E>
void BinaryNodeTree<E>::_destoryTree(BinaryNode<E>* subTreePtr) {}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_balancedAdd(BinaryNode<E>* subTreePtr,
                                               BinaryNode<E>* newNodePtr) {
  return nullptr;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_removeElement(BinaryNode<E>* subTreePtr,
                                                 const E& target,
                                                 bool& success) {
  return nullptr;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_moveElementUpTree(
    BinaryNode<E>* subTreePtr) {
  return nullptr;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_findNode(BinaryNode<E>* treePtr,
                                            const E& target,
                                            bool& success) {
  return nullptr;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_copyTree(
    const BinaryNode<E>* treePtr) const {
  return nullptr;
}

template <typename E>
void BinaryNodeTree<E>::_preorderTraverseHelper(void (*visit)(E&),
                                                BinaryNode<E>* treePtr) const {}

template <typename E>
void BinaryNodeTree<E>::_inorderTraverseHelper(void (*visit)(E&),
                                               BinaryNode<E>* treePtr) const {}

template <typename E>
void BinaryNodeTree<E>::_postorderTraverseHelper(void (*visit)(E&),
                                                 BinaryNode<E>* treePtr) const {
}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree() {}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree(const E& rootElement) {}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree(const E& rootElement,
                                  const BinaryNode<E>* leftTreePtr,
                                  const BinaryNode<E>* rightTreePtr) {}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree(const BinaryNodeTree<E>& binaryNodeTree) {}

template <typename E>
BinaryNodeTree<E>& BinaryNodeTree<E>::operator=(
    const BinaryNodeTree<E>& binaryNodeTree) {
  return BinaryNodeTree<E>();
}

template <typename E>
BinaryNodeTree<E>::~BinaryNodeTree() {}

template <typename E>
bool BinaryNodeTree<E>::isEmpty() const {
  return false;
}

template <typename E>
int BinaryNodeTree<E>::getHeight() const {
  return 0;
}

template <typename E>
int BinaryNodeTree<E>::getNumberOfNodes() const {
  return 0;
}

template <typename E>
E BinaryNodeTree<E>::getRootElement() const noexcept(false) {
  return E();
}

template <typename E>
void BinaryNodeTree<E>::setRootElement(const E& element) {}

template <typename E>
bool BinaryNodeTree<E>::add(const E& element) {
  return false;
}

template <typename E>
bool BinaryNodeTree<E>::remove(const E& element) {
  return false;
}

template <typename E>
void BinaryNodeTree<E>::clear() {}

template <typename E>
E BinaryNodeTree<E>::getElement(const E& element) const noexcept(false) {
  return E();
}

template <typename E>
bool BinaryNodeTree<E>::contains(const E& element) const {
  return false;
}

template <typename E>
void BinaryNodeTree<E>::preorderTraverse(void (*visit)(E&)) const {}

template <typename E>
void BinaryNodeTree<E>::inorderTraverse(void (*visit)(E&)) const {}

template <typename E>
void BinaryNodeTree<E>::postorderTraverse(void (*visit)(E&)) const {}
