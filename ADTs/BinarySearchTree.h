//
// Created by straydragon on 18-10-15.
//
// TODO:等待实现BinarySearchTree 1/2
#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYSEARCHTREE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYSEARCHTREE_H

#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "exceptions/NotFoundException.h"
#include "exceptions/PreconditionFailedException.h"
#include "interfaces/BinaryTree.h"

template <typename E>
class BinarySearchTree : public BinaryNodeTree<E> {
 private:
  BinaryNode<E>* _rootPtr;

 protected:
  BinaryNode<E>* _insertInOrder(BinaryNode<E>* subTreePtr,
                                BinaryNode<E>* newNode);

  BinaryNode<E>* _removeElement(BinaryNode<E>* subTreePtr,
                                const E& target,
                                bool& success);

  BinaryNode<E>* _removeNode(BinaryNode<E>* nodePtr);

  BinaryNode<E>* _removeLeftLeafNode(BinaryNode<E>* subTreePtr,
                                     E& inorderSuccessor);

  BinaryNode<E>* _findNode(BinaryNode<E>* treePtr,
                           const E& target,
                           bool& success);

 public:
  BinarySearchTree();
  BinarySearchTree(const E& rootElement);
  BinarySearchTree(const BinarySearchTree<E>& binarySearchTree);
  virtual ~BinarySearchTree();

  BinarySearchTree<E>& operator=(const BinarySearchTree<E>& binarySearchTree);

  bool isEmpty() const override;

  int getHeight() const override;

  int getNumberOfNodes() const override;

  E getRootElement() const override;

  void setRootElement(const E& element) override;

  bool add(const E& element) override;

  bool remove(const E& element) override;

  void clear() override;

  E getElement(const E& element) const override;

  bool contains(const E& element) const override;

  void preorderTraverse(void (*visit)(E&)) const override;

  void inorderTraverse(void (*visit)(E&)) const override;

  void postorderTraverse(void (*visit)(E&)) const override;
};

#include "BinarySearchTree.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYSEARCHTREE_H
