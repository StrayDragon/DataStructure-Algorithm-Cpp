//
// Created by straydragon on 18-10-21.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_HEAP_H
#define DATASTRUCTURE_ALGORITHM_CPP_HEAP_H

/**
 * @brief 堆(Heap) 接口声明
 *
 * @tparam E 元素类型
 */
template <typename E>
class Heap {
 public:
  /**
   * @brief 判断堆是否为空
   *
   * @return true 堆为空
   * @return false 堆不空
   */
  virtual bool isEmpty() const = 0;

  /**
   * @brief 获取堆内部持有元素个数
   *
   * @return int 元素个数
   */
  virtual int getNumberOfElements() const = 0;

  /**
   * @brief 获取堆的高度
   * 这里的**堆高(Heap
   * Height)**定义为:从根到叶子的最长路径上的节点数,根的高度为0
   * @return int
   */
  virtual int getHeight() const = 0;

  /**
   * @brief 获取堆顶元素
   *
   * @pre 堆不空
   * @post 堆顶元素被返回,但不改变内部状态
   * @throw PreconditionFailedException 堆为空抛出此异常
   * @return E 堆顶元素
   */
  virtual E top() const = 0;

  /**
   * @brief 向堆中加入指定元素
   * 
   * @param element 指定元素
   * @post 堆持有指定元素
   * @return true 添加成功
   * @return false 添加失败
   */
  virtual bool add(const E& element) = 0;

  /**
   * @brief 移除堆顶元素
   * 
   * @return true 移除成功
   * @return false 移除成功
   */
  virtual bool remove() = 0;

  /**
   * @brief 清空所有结点
   * 
   */
  virtual void clear() = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_HEAP_H
