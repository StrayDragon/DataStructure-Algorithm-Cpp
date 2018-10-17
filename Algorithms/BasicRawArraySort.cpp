//
// Created by straydragon on 18-10-16.
//

#include "BasicRawArraySort.h"
#include <algorithm>

int RawArray::SortBy::HelperFunc::findIndexOfLargest(
    const RawArray::ElementType *targetArray, int size) {
  int guessBiggestIndex = 0;

  for (int cur = 1; cur < size; cur++) {
    if (targetArray[cur] > targetArray[guessBiggestIndex])
      guessBiggestIndex = cur;
  }
  return guessBiggestIndex;
}

void RawArray::SortBy::selectionSort(RawArray::ElementType *targetArray,
                                     int size) {
  int biggestIndex;
  for (int last = size - 1; last >= 1; last--) {
    biggestIndex = HelperFunc::findIndexOfLargest(targetArray, last + 1);
    std::swap(targetArray[biggestIndex], targetArray[last]);
  }
}

void RawArray::SortBy::bubbleSort(RawArray::ElementType *targetArray,
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

    for (int i = 0; i < n - pass; i++) {
      assert(targetArray[i] < targetArray[n - pass]);
    }

#endif
    pass++;
  }
}

void RawArray::SortBy::insertionSort(RawArray::ElementType *targetArray,
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

void RawArray::SortBy::insertionSort(ElementType targetArray[], int first,
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

void RawArray::SortBy::HelperFunc::merge(RawArray::ElementType *targetArray,
                                         int first, int mid, int last) {
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

  for (i = first; i <= last; i++) targetArray[i] = tmpArray[i];
}

void RawArray::SortBy::mergeSort(RawArray::ElementType *targetArray, int first,
                                 int last) {
  if (first < last) {
    int mid = first + (last - first) / 2;
    mergeSort(targetArray, first, mid);
    mergeSort(targetArray, mid + 1, last);
    HelperFunc::merge(targetArray, first, mid, last);
  }
}

int RawArray::SortBy::HelperFunc::partition(RawArray::ElementType *targetArray,
                                            int first, int last) {
  return (first + last) / 2;  // TODO:偷懒的分区算法
}

void RawArray::SortBy::quickSort(RawArray::ElementType *targetArray, int first,
                                 int last) {
  if (last - first + 1 < RawArray::MIN_SIZE) {
    RawArray::SortBy::insertionSort(targetArray, first, last);
  } else {
    int pivotIndex = HelperFunc::partition(targetArray, first, last);
    quickSort(targetArray, first, pivotIndex - 1);
    quickSort(targetArray, pivotIndex + 1, last);
  }
}

void RawArray::SortBy::radixSort(RawArray::ElementType *targetArray, int size,
                                 int d) {
  return;  // TODO:等待实现
}
