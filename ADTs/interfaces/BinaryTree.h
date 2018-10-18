//
// Created by straydragon on 18-10-14.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H

#include "../exceptions/NotFoundException.h"

/**
 * @brief 树-二叉树(Binary Tree) 接口声明
 *
 * @tparam E 元素类型
 */
template <typename E>
class BinaryTree {
 public:
  /**
   * @brief 判断二叉树是否为空
   *
   * @return true 二叉树为空
   * @return false 二叉树不为空
   */
  virtual bool isEmpty() const = 0;

  /**
   * @brief 返回树的高度
   * 这里的**树高(Tree
   * Height)**定义为:从根到叶子的最长路径上的节点数,根的高度为0
   *
   * @return int 树的高度
   */
  virtual int getHeight() const = 0;

  /**
   * @brief 返回二叉树的有效节点数
   *
   * @return int 有效节点数
   */
  virtual int getNumberOfNodes() const = 0;

  /**
   * @brief 返回二叉树根节点的元素
   *
   * @pre isEmpty() == false
   * @post 返回根节点元素,但不改变二叉树状态
   * @return E 根节点的元素
   */
  virtual E getRootElement() const = 0;

  /**
   * @brief 覆盖二叉树根节点元素为指定元素
   * 如果树为空,将会插入一个新的根节点,并赋予指定元素
   *
   * @param element 指定元素
   */
  virtual void setRootElement(const E& element) = 0;

  /**
   * @brief 向二叉树插入指定元素节点
   *
   * @param element 指定元素
   * @return true 插入成功
   * @return false 插入失败
   */
  virtual bool add(const E& element) = 0;

  /**
   * @brief 从二叉树中移除指定元素节点
   *
   * @param element 指定元素
   * @return true 移除成功
   * @return false 移除失败
   */
  virtual bool remove(const E& element) = 0;

  /**
   * @brief 移除二叉树所有节点
   *
   */
  virtual void clear() = 0;

  /**
   * @brief 判断指定元素是否存在,若存在,返回该指定元素;若不存在,将引发异常
   *
   * @param element 指定元素
   * @return E 和指定元素一样的值
   * @throw NotFoundException 当找不到指定元素时,引发该异常
   */
  virtual E getElement(const E& element) const noexcept(false) = 0;

  /**
   * @brief 判断指定元素是否存在二叉树中
   *
   * @post 不改变树的状态
   * @param element 指定元素
   * @return true 二叉树节点中包含此元素
   * @return false 二叉树节点中不包含此元素
   */
  virtual bool contains(const E& element) const = 0;

  /**
   * @brief 前序遍历
   *
   * @param visit 由用户定义的一个函数,用于在遍历的节点上执行相对应的操作
   */
  virtual void preorderTraverse(void visit(E&)) const = 0;

  /**
   * @brief 中序遍历
   *
   * @param visit 由用户定义的一个函数,用于在遍历的节点上执行相对应的操作
   */
  virtual void inorderTraverse(void visit(E&)) const = 0;

  /**
   * @brief 后序遍历
   *
   * @param visit 由用户定义的一个函数,用于在遍历的节点上执行相对应的操作
   */
  virtual void postorderTraverse(void visit(E&)) const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H
