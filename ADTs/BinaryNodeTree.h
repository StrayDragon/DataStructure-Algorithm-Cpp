//
// Created by straydragon on 18-10-15.
//
#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYNODETREE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYNODETREE_H

#include <functional>
#include "BinaryNode.h"
#include "exceptions/NotFoundException.h"
#include "exceptions/PreconditionFailedException.h"
#include "interfaces/BinaryTree.h"
template <typename E>
class BinaryNodeTree : public BinaryTree<E> {
 private:
  BinaryNode<E>* _rootPtr;

 protected:
  /**
   * @brief getHeigh()方法的辅助函数,递归求解
   *
   */
  int _getHeightHelper(BinaryNode<E>* subTreePtr) const;

  /**
   * @brief getNumberOfNodes()方法的辅助函数,递归求解
   *
   */
  int _getNumberOfNodesHelper(BinaryNode<E>* subTreePtr) const;

  /**
   * @brief 递归的删除树中所有节点
   *
   */
  void _destroyTree(BinaryNode<E>* subTreePtr);

  /**
   * @brief add()方法的辅助函数
   * 这个方法将尽可能保持插入后节点高度平衡
   *
   */
  BinaryNode<E>* _balancedAdd(BinaryNode<E>* subTreePtr,
                              BinaryNode<E>* newNodePtr);
  /**
   * @brief '删除'指定元素的节点
   *
   * @param subTreePtr 目标子树
   * @param target 目标变量
   * @param success callback变量
   * @return BinaryNode<E>*
   */
  BinaryNode<E>* _removeValue(BinaryNode<E>* subTreePtr,
                              const E& target,
                              bool& success);

  /**
   * @brief _removeValue()方法的辅助函数
   * 用来把待删除节点的某个符合条件子节点移动到待删除节点上,并删除子节点<br>
   * 这个函数将尽可能保持树的平衡
   *
   * @param subTreePtr 待删除节点
   * @post
   * 若成功,待删除节点已经被'删除',此时元素已经被替换为其子树的某个合适节点值,<br>
   * 并且该子树节点已经被删除
   * @return BinaryNode<E>*
   */
  BinaryNode<E>* _moveValueUpTree(BinaryNode<E>* subTreePtr);

  /**
   * @brief 寻找指定元素的节点值
   *
   * @param treePtr (暂时没有用)
   * @param target 目标元素
   * @param success callback变量,用来表示成功与否
   * @return BinaryNode<E>* 若查询成功,则返回找到的节点,否则,返回nullptr
   */
  BinaryNode<E>* _findNode(BinaryNode<E>* treePtr,
                           const E& target,
                           bool& success);
  /**
   * @brief 复制指定树的所有节点(深拷贝)
   *
   * @param treePtr 待拷贝的树
   * @return BinaryNode<E>* 返回新的根节点
   */
  BinaryNode<E>* _copyTree(const BinaryNode<E>* treePtr) const;

  /**
   * @brief preorderTraverse()方法的辅助函数,(递归)
   *
   * @param visit 访问函数 签名为 void(E&)
   * @param treePtr 待遍历的树
   */
  void _preorderTraverseHelper(
      std::function<void(E&)> visit /* void (*visit)(E&)*/,
      BinaryNode<E>* treePtr) const;

  /**
   * @brief preorderTraverse()方法的辅助函数(重载),(递归)
   *
   * @param visit 访问函数 签名为 void(BinaryNode<E>*)
   * @param treePtr 待遍历的树
   */
  void _preorderTraverseHelper(std::function<void(BinaryNode<E>*)>
                                   visit /*void (*visit)(BinaryTree<E>*)*/,
                               BinaryNode<E>* treePtr) const;
  /**
   * @brief inorderTraverse()方法的辅助函数
   *
   * @param visit
   * @param treePtr
   */
  void _inorderTraverseHelper(void visit(E&), BinaryNode<E>* treePtr) const;

  /**
   * @brief postorderTraverse()方法的辅助函数
   *
   * @param visit
   * @param treePtr
   */
  void _postorderTraverseHelper(void visit(E&), BinaryNode<E>* treePtr) const;

 public:
  BinaryNodeTree();

  explicit BinaryNodeTree(const E& rootElement);

  BinaryNodeTree(const E& rootElement,
                 const BinaryNode<E>* leftTreePtr,
                 const BinaryNode<E>* rightTreePtr);

  BinaryNodeTree(const BinaryNodeTree<E>& binaryNodeTree);

  BinaryNodeTree<E>& operator=(const BinaryNodeTree<E>& binaryNodeTree);

  virtual ~BinaryNodeTree();

  bool isEmpty() const override;

  int getHeight() const override;

  int getNumberOfNodes() const override;

  /// @throw PreconditionFailedException
  E getRootElement() const noexcept(false) override;

  /// @throw PreconditionFailedException
  void setRootElement(const E& element) noexcept(false) override;

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
