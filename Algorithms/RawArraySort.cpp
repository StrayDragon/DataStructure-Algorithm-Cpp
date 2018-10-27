//
// Created by straydragon on 18-10-16.
//

#include "RawArraySort.h"
#include <algorithm>
#include <typeinfo>

int RawArray::SortBy::HelperFunc::findIndexOfLargest(
    const RawArray::ElementType* targetArray,
    int size) {
  int guessBiggestIndex = 0;

  for (int cur = 1; cur < size; cur++) {
    if (targetArray[cur] > targetArray[guessBiggestIndex])
      guessBiggestIndex = cur;
  }
  return guessBiggestIndex;
}

void RawArray::SortBy::selectionSort(RawArray::ElementType* targetArray,
                                     int size) {
  int biggestIndex;
  for (int last = size - 1; last >= 1; last--) {
    biggestIndex = HelperFunc::findIndexOfLargest(targetArray, last + 1);
    std::swap(targetArray[biggestIndex], targetArray[last]);
  }
}

void RawArray::SortBy::bubbleSort(RawArray::ElementType* targetArray,
                                  int size) {
  bool sorted = false;
  int pass = 1;
  while (!sorted && (pass < size)) {
    sorted = true;

    for (int nextI, i = 0; i < size - pass; i++) {
      nextI = i + 1;
      if (targetArray[i] > targetArray[nextI]) {
        std::swap(targetArray[i], targetArray[nextI]);
        sorted = false;
      }
    }
#ifdef DEBUG
    for (int i = 0; i < size - pass; i++) {
      assert(targetArray[i] < targetArray[size - pass]);
    }
#endif
    pass++;
  }
}

void RawArray::SortBy::insertionSort(RawArray::ElementType* targetArray,
                                     int size) {
  for (int unsorted = 0; unsorted < size; unsorted++) {
    ElementType nextElement = targetArray[unsorted];
    int cur = unsorted;

    while ((cur > 0) && targetArray[cur - 1] > nextElement) {
      targetArray[cur] = targetArray[cur - 1];
      cur--;
    }
    targetArray[cur] = nextElement;
  }
}

void RawArray::SortBy::insertionSort(ElementType targetArray[],
                                     int first,
                                     int last) {
  for (int unsorted = first; unsorted <= last; unsorted++) {
    ElementType nextElement = targetArray[unsorted];
    int cur = unsorted;

    while ((cur > 0) && targetArray[cur - 1] > nextElement) {
      targetArray[cur] = targetArray[cur - 1];
      cur--;
    }
    targetArray[cur] = nextElement;
  }
}

void RawArray::SortBy::HelperFunc::merge(RawArray::ElementType* targetArray,
                                         int first,
                                         int mid,
                                         int last) {
  ElementType tmpArray[RawArray::MAX_SIZE];

  int first1 = first;
  int last1 = mid;
  int first2 = mid + 1;
  int last2 = last;

  int i = first1;
  while ((first1 <= last1) && (first2 <= last2)) {
    if (targetArray[first1] <= targetArray[first2]) {
      tmpArray[i] = targetArray[first1];
      first1++;
    } else {
      tmpArray[i] = targetArray[first2];
      first2++;
    }
    i++;
  }

  while (first1 <= last1) {
    tmpArray[i] = targetArray[first1];
    first1++;
    i++;
  }

  while (first2 <= last2) {
    tmpArray[i] = targetArray[first2];
    first2++;
    i++;
  }

  for (i = first; i <= last; i++)
    targetArray[i] = tmpArray[i];
}

void RawArray::SortBy::mergeSort(RawArray::ElementType* targetArray,
                                 int first,
                                 int last) {
  if (first < last) {
    int mid = first + (last - first) / 2;
    mergeSort(targetArray, first, mid);
    mergeSort(targetArray, mid + 1, last);
    HelperFunc::merge(targetArray, first, mid, last);
  }
}

int RawArray::SortBy::HelperFunc::partition(RawArray::ElementType* targetArray,
                                            int first,
                                            int last) {
  // 把原数组的第一个元素 targetArray[first]
  // 中间元素             targetArray[(last - first) / 2]
  // 最后一个元素         targetArray[last]
  // 按元素大小排序,最后返回三元素排序后的中间位置元素下标
  int mid = (last - first) / 2;
  if (targetArray[first] > targetArray[mid]) {
    std::swap(targetArray[first], targetArray[mid]);
  }
#ifdef DEBUG
  std::cout << targetArray[first] << " " << targetArray[mid] << " "
            << targetArray[last] << std::endl;
#endif
  if (targetArray[mid] > targetArray[last]) {
    std::swap(targetArray[mid], targetArray[last]);
  }
#ifdef DEBUG
  std::cout << targetArray[first] << " " << targetArray[mid] << " "
            << targetArray[last] << std::endl;
#endif
  return mid;
}

void RawArray::SortBy::quickSort(RawArray::ElementType* targetArray,
                                 int first,
                                 int last) {
  if (last - first + 1 < RawArray::MIN_SIZE) {
    RawArray::SortBy::insertionSort(targetArray, first, last);
  } else {
    int pivotIndex = HelperFunc::partition(targetArray, first, last);
    quickSort(targetArray, first, pivotIndex - 1);
    quickSort(targetArray, pivotIndex + 1, last);
  }
}

void RawArray::SortBy::radixSort(RawArray::ElementType* targetArray,
                                 int size,
                                 int digits) {
  if (typeid(targetArray[0]) == typeid(int)) {
    //创建10个桶（队列）分别给每个数位（0到9）
    LinkedQueue<ElementType> queue[10];
    int nDigitValue;
    //遍历每个数位
    for (int n = 1; n <= digits; ++n) {
      for (int i = 0; i < size; ++i) {
        //遍历数列中的每个元素,指示下标(i)
        nDigitValue = HelperFunc::countSpecificDigitOfNumber(targetArray[i], n);
        //并将元素移至相应的桶中
        queue[nDigitValue].enqueue(targetArray[i]);
      }
      //在每个桶中，从最小的数位(j)开始
      for (int j = 0, k = 0; j < 10; ++j) {
        //当桶不是空的
        while (!((queue[j]).isEmpty())) {
          //将元素恢复至数列中,元素下标(k)
          targetArray[k] = queue[j].front();
          queue[j].dequeue();
          //将元素下标(k)递增1,到下一元素
          ++k;
        }
      }
    }
  } else {
    return;
  }
}

#include "../ADTs/BinarySearchTree.h"
void RawArray::SortBy::binarySearchTreeSort(RawArray::ElementType* targetArray,
                                            int size) {
  using namespace HelperFunc;
  BinarySearchTree<ElementType> bst;
  for (int i = 0; i < size; ++i) {
    bst.add(targetArray[i]);
  }
  int i = 0;
  bst.inorderTraverse([&](ElementType e) { targetArray[i++] = e; });
}

void RawArray::SortBy::heapSort(RawArray::ElementType* targetArray, int size) {
  for (int i = size / 2; i >= 0; i--) {
    HelperFunc::heapRebuild(i, targetArray, size);
  }

#ifdef DEBUG
  for (int j = 0; j < size; ++j)
    std::cout << targetArray[j] << " ";
  std::cout<< std::endl;
#endif

  std::swap(targetArray[0], targetArray[size - 1]);
  int heapSize = size - 1;
  while (heapSize > 1) {
    HelperFunc::heapRebuild(0, targetArray, heapSize);
    std::swap(targetArray[0], targetArray[heapSize - 1]);
    heapSize--;
  }
}

void RawArray::SortBy::HelperFunc::heapRebuild(
    int index,
    RawArray::ElementType* targetArray,
    int size) {
  int leftIndex = index * 2 + 1;
  if (leftIndex < size) {
    int rightIndex = index * 2 + 2;
    if (rightIndex < size) {
      if (targetArray[leftIndex] < targetArray[rightIndex])
        leftIndex = rightIndex;
    }
    if (targetArray[index] < targetArray[leftIndex]) {
      std::swap(targetArray[index], targetArray[leftIndex]);
      heapRebuild(leftIndex, targetArray, size);
    }
  }
}
