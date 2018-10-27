//
// Created by straydragon on 18-10-16.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BASICRAWARRAYSORT_H
#define DATASTRUCTURE_ALGORITHM_CPP_BASICRAWARRAYSORT_H

#ifdef DEBUG
#include <iostream>
#include <cassert>
#endif

#include "../ADTs/LinkedQueue.h"

/**
 * @brief 命名空间::定义类型别名
 * 处理原生数组类型('[]')
 *
 */
namespace RawArray {
using ElementType = int;
/**
 * @brief 归并排序中全局变量,代表目标数组最大元素数量
 *
 */
const int MAX_SIZE = 10;
const int MIN_SIZE = 4;
/**
 * @brief 命名空间::排序方式
 * 排序默认为升序
 *
 */
namespace SortBy {
/**
 * @brief 选择排序
 *
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param size 元素数量
 */
void selectionSort(ElementType targetArray[], int size);
namespace HelperFunc {
/**
 * @brief selectionSort函数的辅助函数
 * 返回数组中找到的最大元素的下标
 * @pre size >= 1
 * @post 数组内部元素状态不变
 * @param targetArray 目标数组
 * @param size 目标数组大小
 * @return int 最大元素的下标
 */
int findIndexOfLargest(const ElementType targetArray[], int size);
}  // namespace HelperFunc

/**
 * @brief 冒泡排序
 *
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param size 元素数量
 */
void bubbleSort(ElementType targetArray[], int size);

/**
 * @brief 插入排序
 *
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param size 元素数量
 */
void insertionSort(ElementType targetArray[], int size);

/**
 * @brief 插入排序(重载版本)
 *
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param first 待排序起点
 * @param last 待排序终点
 */
void insertionSort(ElementType targetArray[], int first, int last);

/**
 * @brief 归并排序
 *
 * @post 升序排序完成,目标数组从first到last(数组长度-1)被排序
 * @param targetArray 目标数组
 * @param first 待排序数组(片段)起点
 * @param last 待排序数组(片段)终点(包含)
 */
void mergeSort(ElementType targetArray[], int first, int last);
namespace HelperFunc {
/**
 * @brief mergeSort的辅助函数
 *
 * 合并两个已经排好序的数组片段为一个排好序的数组<br>
 * 数组片段1:[first,mid]<br>
 * 数组片段2:[mid+1,last]<br>
 *
 * @param targetArray 目标数组
 * @param first 数组片段1起点
 * @param mid 数组片段1终点,mid+1为数组片段2起点
 * @param last 数组片段2终点
 */
void merge(ElementType targetArray[], int first, int mid, int last);
}  // namespace HelperFunc

/**
 * @brief 快速排序
 *
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param first 目标数组起点
 * @param last 目标数组终点
 */
void quickSort(ElementType targetArray[], int first, int last);
namespace HelperFunc {
/**
 * @brief quickSort的辅助函数
 *
 * 用于将目标数分成三份 :<br>    片段1 | 基准点(pivot) | 片段2 <br>
 * 返回基准点(数组下标值)
 * @param targetArray 目标数组
 * @param first 数组片段起点
 * @param last 数组片段终点
 * @return int 基准点(pivot)值(数组下标值)
 */
int partition(ElementType targetArray[], int first, int last);
}  // namespace HelperFunc
/**
 * @brief 基数排序
 *
 * @pre digits ==  数组最大元素的位数
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param size 元素数量
 * @param digits 元素位数
 */
void radixSort(ElementType targetArray[], int size, int digits);
namespace HelperFunc {
inline int powExcludePower0(int base, int power) {
  int sum = 1;
  for (int i = 0; i < power; ++i)
    sum *= base;
  return sum;
}
inline int countSpecificDigitOfNumber(int target, int digit) {
  if (digit == 1 || digit == 0) {
    return target % 10 / 1;
  } else {
    return target % (powExcludePower0(10, digit)) /
           (powExcludePower0(10, digit - 1));
  }
}
}  // namespace HelperFunc
/**
 * @brief 树排序
 * 基于二叉搜索树的实现
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param size 元素数量
 */
void treeSort(ElementType targetArray[], int size);

/**
 * @brief 堆排序
 * @post 升序排序完成,目标数组元素数量不变
 * @param targetArray 目标数组
 * @param size 元素数量
 */
void heapSort(ElementType targetArray[], int size);

namespace HelperFunc {
/**
* @brief heapSort的辅助函数
*
* 将半堆恢复成堆
* @param index 子堆的根位置
* @param targetArray 目标数组
* @param size 元素数量
*/
void heapRebuild(int index, ElementType targetArray[], int size);
}
}  // namespace SortBy
}  // namespace RawArray

#include "RawArraySort.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_BASICRAWARRAYSORT_H
