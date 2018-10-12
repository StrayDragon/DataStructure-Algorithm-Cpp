#ifndef ARRAYBAG_H
#define ARRAYBAG_H

#include "interface/Bag.h"

template<typename E>
class ArrayBag : public Bag<E> {
    static const int DEFAULT_CAPACITY = 6;

private:
    E _e[DEFAULT_CAPACITY];
    /**
     * @brief 包内元素数量计数器
     *
     */
    int _size;
    int _capacity;

    int _getIndexOf(const E &target) const;

public:
    ArrayBag();

    ~ArrayBag() = default;

    /**
     * @brief 获取包当前的大小
     *
     * @return int 所容纳元素数量
     */
    int getCurrentSize() const final;

    /**
     * @brief 判断包是否为空
     *
     * @return true 包为空
     * @return false 包不为空
     */
    bool isEmpty() const final;

    /**
     * @brief 向包中添加元素
     *
     * @param e 待添加的元素
     * @post 若成功,待添加元素会保存在包中,并且包内元素数量计数器会递增1
     * @return true 添加成功
     * @return false 添加失败
     */
    bool add(const E &e) final;

    /**
     * @brief 删除某个存在于包中的元素
     *
     * @param e 待删除元素
     * @post 若成功,待删除元素会从包中移除,并且包内元素数量计数器会递减1
     * @return true 删除成功
     * @return false 删除失败
     */
    bool remove(const E &e) final;

    /**
     * @brief 清除包内所有元素
     *
     * @post 包现在不拥有任何元素,并且包内元素数量计数器值变为0
     */
    void clear() final;

    /**
     * @brief 获取指定元素在包中出现的次数
     *
     * @param e 待查询元素
     * @return int 指定元素出现在包中的次数
     */
    int getFrequencyOf(const E &e) const final;

    /**
     * @brief 查找指定元素是否出现在包中
     *
     * @param e 待查找元素
     * @return true 包中有此元素
     * @return false 包中没有次元素
     */
    bool contains(const E &e) const final;

    /**
     * @brief 将包中元素拷贝到标准库的vector容器
     *
     * @return std::vector<E> 包含所有包中元素的vector容器
     */
    std::vector<E> toSTLVector() const final;
};

#include "ArrayBag.cpp"

#endif