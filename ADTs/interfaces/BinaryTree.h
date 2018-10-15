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
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isEmpty() const = 0;

  /**
   * @brief Get the Height object
   * 
   * @return int 
   */
  virtual int getHeight() const = 0;

  /**
   * @brief Get the Number Of Nodes object
   * 
   * @return int 
   */
  virtual int getNumberOfNodes() const = 0;

  /**
   * @brief Get the Root Element object
   * 
   * @return E 
   */
  virtual E getRootElement() const = 0;

  /**
   * @brief Set the Root Element object
   * 
   * @param element 
   */
  virtual void setRootElement(const E& element) = 0;

  /**
   * @brief 
   * 
   * @param element 
   * @return true 
   * @return false 
   */
  virtual bool add(const E& element) = 0;

  /**
   * @brief 
   * 
   * @param element 
   * @return true 
   * @return false 
   */
  virtual bool remove(const E& element) = 0;

  /**
   * @brief 
   * 
   */
  virtual void clear() = 0;

  /**
   * @brief Get the Element object
   * 
   * @param element 
   * @return E 
   */
  virtual E getElement(const E& element) const noexcept(false) = 0;

  /**
   * @brief 
   * 
   * @param element 
   * @return true 
   * @return false 
   */
  virtual bool contains(const E& element) const = 0;

  /**
   * @brief 
   * 
   * @param visit 
   */
  virtual void preorderTraverse(void visit(E&)) const = 0;

  /**
   * @brief 
   * 
   * @param visit 
   */
  virtual void inorderTraverse(void visit(E&)) const = 0;

  /**
   * @brief 
   * 
   * @param visit 
   */
  virtual void postorderTraverse(void visit(E&)) const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_BINARYTREE_H
