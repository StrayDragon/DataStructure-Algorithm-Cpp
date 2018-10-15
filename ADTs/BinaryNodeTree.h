//
// Created by straydragon on 18-10-15.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYNODETREE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYNODETREE_H

#include "BinaryNode.h"
#include "exceptions/NotFoundException.h"
#include "exceptions/PreconditionFailedException.h"
#include "interfaces/BinaryTree.h"

template <typename E>
class BinaryNodeTree : public BinaryTree<E> {
 private:
  BinaryNode<E>* _rootPtr;

 protected:
  int _getHeightHelper(BinaryNode<E>* subTreePtr) const;
  int _getNumberOfNodesHelper(BinaryNode<E>* subTreePtr) const;

  void _destoryTree(BinaryNode<E>* subTreePtr);

  BinaryNode<E>* _balancedAdd(BinaryNode<E>* subTreePtr,
                              BinaryNode<E>* newNodePtr);

  BinaryNode<E>* _removeElement(BinaryNode<E>* subTreePtr, const E& target,
                                bool& success);

  BinaryNode<E>* _moveElementUpTree(BinaryNode<E>* subTreePtr);

  BinaryNode<E>* _findNode(BinaryNode<E>* treePtr, const E& target,
                           bool& success);

  BinaryNode<E>* _copyTree(const BinaryNode<E>* treePtr) const;

  void _preorderTraverseHelper(void visit(E&), BinaryNode<E>* treePtr) const;

  void _inorderTraverseHelper(void visit(E&), BinaryNode<E>* treePtr) const;

  void _postorderTraverseHelper(void visit(E&), BinaryNode<E>* treePtr) const;

 public:
  BinaryNodeTree();
  BinaryNodeTree(const E& rootElement);
  BinaryNodeTree(const E& rootElement, const BinaryNode<E>* leftTreePtr,
                 const BinaryNode<E>* rightTreePtr);
  BinaryNodeTree(const BinaryNodeTree<E>& binaryNodeTree);

  BinaryNodeTree<E>& operator=(const BinaryNodeTree<E>& binaryNodeTree);

  virtual ~BinaryNodeTree();

  bool isEmpty() const override;

  int getHeight() const override;

  int getNumberOfNodes() const override;

  E getRootElement() const
      noexcept(false) override;  // throw PreconditionFailedException

  void setRootElement(const E& element) override;

  bool add(const E& element) override;

  bool remove(const E& element) override;

  void clear() override;

  E getElement(const E& element) const
      noexcept(false) override;  // throw NotFoundException

  bool contains(const E& element) const override;

  void preorderTraverse(void (*visit)(E&)) const override;

  void inorderTraverse(void (*visit)(E&)) const override;

  void postorderTraverse(void (*visit)(E&)) const override;
};

#include "BinaryNodeTree.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYNODETREE_H
