#ifndef _BAG_H
#define _BAG_H
#include <vector>
template <typename E>
class Bag {
 public:
  /**
   * @brief 获取包当前的大小
   *
   * @return int 所容纳元素数量
   */
  virtual int getCurrentSize() const = 0;
  /**
   * @brief 判断包是否为空
   *
   * @return true 包为空
   * @return false 包不为空
   */
  virtual bool isEmpty() const = 0;

  /**
   * @brief 向包中添加元素
   *
   * @param e 待添加的元素
   * @post 若成功,待添加元素会保存在包中,并且包内元素数量计数器会递增1
   * @return true 添加成功
   * @return false 添加失败
   */
  virtual bool add(const E& e) = 0;

  /**
   * @brief 删除某个存在于包中的元素
   *
   * @param e 待删除元素
   * @post 若成功,待删除元素会从包中移除,并且包内元素数量计数器会递减1
   * @return true 删除成功
   * @return false 删除失败
   */
  virtual bool remove(const E& e) = 0;

  /**
   * @brief 清除包内所有元素
   *
   * @post 包现在不拥有任何元素,并且包内元素数量计数器值变为0
   */
  virtual void clear() = 0;

  /**
   * @brief 获取指定元素在包中出现的次数
   *
   * @param e 待查询元素
   * @return int 指定元素出现在包中的次数
   */
  virtual int getFrequencyOf(const E& e) const = 0;

  /**
   * @brief 查找指定元素是否出现在包中
   *
   * @param e 待查找元素
   * @return true 包中有此元素
   * @return false 包中没有次元素
   */
  virtual bool contains(const E& e) const = 0;

  /**
   * @brief 将包中元素拷贝到标准库的vector容器
   *
   * @return std::vector<E> 包含所有包中元素的vector容器
   */
  virtual std::vector<E> toSTLVector() const = 0;
};

#endif
