//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_STACK_H
#define DATASTRUCTURE_ALGORITHM_CPP_STACK_H

/**
 * @brief 栈(Stack) 接口声明
 *
 * @tparam E 元素声明
 */
template <typename E>
class Stack {
 public:
  /**
   * @brief 判断栈是否为空
   *
   * @return true 栈为空
   * @return false 栈不为空
   */
  virtual bool isEmpty() const = 0;
  /**
   * @brief 将元素 e 推进堆栈
   *
   * @param e 待推入元素
   * @post 如果成功,元素 e 位于栈顶
   * @return true 推入成功
   * @return false 推入失败
   */
  virtual bool push(const E& e) = 0;
  /**
   * @brief 将栈顶元素弹出(删除)
   *
   * @post 如果成功,栈顶元素已经被移除
   * @return true 移除成功
   * @return false 移除失败
   */
  virtual bool pop() = 0;
  /**
   * @brief  返回栈顶元素
   * @pre isEmpty() == false
   * @post 栈顶元素已经返回,但栈内部状态不改变
   * @return E 栈顶元素
   */
  virtual E top() const = 0;
};

#endif  // DATASTRUCTURE_ALGORITHM_CPP_STACK_H
