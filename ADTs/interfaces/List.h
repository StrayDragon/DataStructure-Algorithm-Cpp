//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LIST_H
#define DATASTRUCTURE_ALGORITHM_CPP_LIST_H

/**
 * @brief 列表(List) 接口声明
 *
 * @tparam E 元素类型
 */
template <typename E>
class List {
 public:
  /**
   * @brief 判断列表是否为空
   *
   * @return true 列表为空
   * @return false 列表不为空
   */
  virtual bool isEmpty() const = 0;

  /**
   * @brief 返回列表中元素数量
   *
   * @return int 持有元素数量
   */
  virtual int getLength() const = 0;

  /**
   * @brief 向指定位置插入元素
   * 指定位置的最大有效值定义为:元素数量+1
   * 若指定位置有效
   *    若此位置不存在元素,将会在此位置插入元素
   *    若此位置存在元素,将会在此位置之前插入元素,维持逻辑位置与指定位置相同
   * 成功插入后,列表中的内容将重新排号.
   *
   * 例:
   * ```cpp
   * //... Initialize aList
   * //aList.insert(0,"");      // Violated by post condition
   * aList.insert(1,"Cpp");     // ["Cpp"]
   * aList.insert(1,"Modern")   // ["Modern","Cpp"]
   * aList.insert(3,"!")        // ["Modern","Cpp","!"]
   * ```
   * @post 1 <= newPosition <= getLength() + 1
   * @param newPosition 插入的位置,这里从列表的第一项开始计数
   * @param element 待插入元素
   * @return true 插入成功
   * @return false 插入失败
   */
  virtual bool insert(int newPosition, const E& element) = 0;

  /**
   * @brief 移除指定位置元素
   * 删除后列表中的内容将重新排号.
   * @post 1 <= position <= getLength()
   * @param position 目标位置
   * @return true 删除成功
   * @return false 删除失败
   */
  virtual bool remove(int position) = 0;

  /**
   * @brief 移除所有元素
   *
   * @post 列表现在为空,getLength()为 0
   */
  virtual void clear() = 0;

  /**
   * @brief 获取指定位置的元素
   *
   * @pre 1 <= position <= getLength()
   * @param position 指定位置
   * @return E 目标元素
   */
  virtual E getElementAt(int position) = 0;

  /**
   * @brief 替换目标位置元素为指定元素
   *
   * @pre 1 <= position <= getLength()
   * @param position 目标位置
   * @param element 替换元素
   */
  virtual void setElementAt(int position, E&& element) = 0;
};
#endif  // DATASTRUCTURE_ALGORITHM_CPP_LIST_H
