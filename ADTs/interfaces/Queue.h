//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_QUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_QUEUE_H

/**
 * @brief 队列(Queue) 接口声明
 *
 * @tparam E 元素声明
 */
template <typename E>
class Queue {
 public:
  /**
   * @brief 判断队列是否为空
   *
   * @return true 队列为空
   * @return false 队列不为空
   */
  virtual bool isEmpty() const = 0;

  /**
   * @brief 入队
   * 添加指定元素到队列
   *
   * @post 如果入队成功,新元素将在队列尾
   * @param element
   * @return true 入队成功
   * @return false 入队失败
   */
  virtual bool enqueue(const E& element) = 0;

  /**
   * @brief 出队
   * 移除队首元素
   *
   * @post 如果出队成功,将移除队首元素
   * @return true 出队成功
   * @return false 出队失败
   */
  virtual bool dequeue() = 0;

  /**
   * @brief 返回队首元素
   *
   * @pre isEmpty() 为 false
   * @post 队首元素已经被返回,但不改变队列状态
   * @return E
   */
  virtual E front() const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_QUEUE_H
