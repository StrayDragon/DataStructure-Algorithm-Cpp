//
// Created by straydragon on 18-12-19.
//

#include <gtest/gtest.h>

#include "../src/Algorithms/RawArraySort.h"

TEST(RawArray_Sort, selectionSort) {  // NOLINT(cert-err58-cpp)
  int test_case[] = {1, 3, 2, 5, 6, 7, 8, 9, 19, 23};
  size_t len = sizeof(test_case) / sizeof(int);
  std::vector<int> comparison(std::begin(test_case), std::end(test_case));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::selectionSort(test_case, static_cast<int>(len));
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(test_case[i], comparison[i]);
  }
}

TEST(RawArray_Sort, bubbleSort) {  // NOLINT(cert-err58-cpp)
  int test_case[] = {1, 3, 2, 5, 6, 7, 8, 9, 19, 23};
  size_t len = sizeof(test_case) / sizeof(int);
  std::vector<int> comparison(std::begin(test_case), std::end(test_case));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::bubbleSort(test_case, static_cast<int>(len));
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(test_case[i], comparison[i]);
  }
}

TEST(RawArray_Sort, heapSort) {  // NOLINT(cert-err58-cpp)
  int test_case[] = {1, 3, 2, 5, 6, 7, 8, 9, 19, 23};
  size_t len = sizeof(test_case) / sizeof(int);
  std::vector<int> comparison(std::begin(test_case), std::end(test_case));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::heapSort(test_case, static_cast<int>(len));
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(test_case[i], comparison[i]);
  }
}

TEST(RawArray_Sort, mergeSort) {  // NOLINT(cert-err58-cpp)
  int test_case[] = {1, 3, 2, 5, 6, 7, 8, 9, 19, 23};
  int len = sizeof(test_case) / sizeof(int);
  std::vector<int> comparison(std::begin(test_case), std::end(test_case));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::mergeSort(test_case, 0,
                              sizeof(test_case) / sizeof(int) - 1);
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(test_case[i], comparison[i]);
  }
}

TEST(RawArray_Sort, quickSort) {  // NOLINT(cert-err58-cpp)
  int arr[] = {1, 3, 2, 5, 6, 7, 8, 9, 19, 23};
  int len = sizeof(arr) / sizeof(int);
  std::vector<int> comparison(std::begin(arr), std::end(arr));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::quickSort(arr, 0, len - 1);
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(arr[i], comparison[i]);
  }
}

TEST(RawArray_Sort, radixSort) {  // NOLINT(cert-err58-cpp)
  int test_case[] = {1, 3, 2, 5, 6, 7, 8, 9};
  size_t len = sizeof(test_case) / sizeof(int);
  std::vector<int> comparison(std::begin(test_case), std::end(test_case));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::radixSort(test_case, static_cast<int>(len), 1);
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(test_case[i], comparison[i]);
  }
}

TEST(RawArray_Sort, treeSort) {  // NOLINT(cert-err58-cpp)
  int test_case[] = {1, 3, 2, 5, 6, 7, 8, 9, 19, 23};
  size_t len = sizeof(test_case) / sizeof(int);
  std::vector<int> comparison(std::begin(test_case), std::end(test_case));
  std::sort(comparison.begin(), comparison.end());
  RawArray::SortBy::treeSort(test_case, static_cast<int>(len));
  for (size_t i = 0; i < len; i++) {
    ASSERT_EQ(test_case[i], comparison[i]);
  }
}