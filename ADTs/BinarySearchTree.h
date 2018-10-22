//
// Created by straydragon on 18-10-15.
//
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
  /**
   * @brief (辅助函数) 递归的找到合适的位置,并将newNode插入进去,
   */
  BinaryNode<E>* _insertInOrder(BinaryNode<E>* subTreePtr,
                                BinaryNode<E>* newNodePtr);

  /**
   * @brief (辅助函数) 移除树中存在的指定元素(target)
   * P.S.该函数遮盖掉了protected继承的同名函数
   */
  BinaryNode<E>* _removeValue(BinaryNode<E>* subTreePtr,
                              const E& target,
                              bool& success);

  /**
   * @brief (辅助函数) 从树中移除指定的节点
   */
  BinaryNode<E>* _removeNode(BinaryNode<E>* nodePtr);

  /**
   * @brief (辅助函数) 从树中移除二叉搜索树中最左面的叶子(权值最低节点)
   */
  BinaryNode<E>* _removeLeftMostNode(BinaryNode<E>* subTreePtr,
                                     E& inorderSuccessor);

  /**
   * @brief (辅助函数)
   * 丛二叉树的查找指定元素,若查找成功,返回该节点;否则为nullptr
   * P.S.该函数遮盖掉了protected继承的同名函数
   */
  BinaryNode<E>* _findNode(BinaryNode<E>* treePtr,
                           const E& target,
                           bool& success);

 public:
  BinarySearchTree();

  explicit BinarySearchTree(const E& rootElement);

  BinarySearchTree(const BinarySearchTree<E>& binarySearchTree);

  virtual ~BinarySearchTree();

  BinarySearchTree<E>& operator=(const BinarySearchTree<E>& binarySearchTree);

//  bool isEmpty() const override;

//  int getHeight() const override;
//
//  int getNumberOfNodes() const override;
//
//  E getRootElement() const override;
//
//  void setRootElement(const E& element) override;

  bool add(const E& element) override;

  bool remove(const E& element) override;

//  void clear() override;
//
//  E getElement(const E& element) const override;
//
//  bool contains(const E& element) const override;
//
//  void preorderTraverse(void (*visit)(E&)) const override;
//
//  void inorderTraverse(void (*visit)(E&)) const override;
//
//  void postorderTraverse(void (*visit)(E&)) const override;
};

#include "BinarySearchTree.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYSEARCHTREE_H
