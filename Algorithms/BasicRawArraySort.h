//
// Created by straydragon on 18-10-16.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BASICRAWARRAYSORT_H
#define DATASTRUCTURE_ALGORITHM_CPP_BASICRAWARRAYSORT_H

namespace RawArray {
using ElementType = int;
extern const int MAX_SIZE;
namespace SortBy {
void selectionSort(ElementType targetArray[], int n);
namespace HelperFunc {
		int findIndexOfLargest(const ElementType targetArray[], int size);
}
void bubbleSort(ElementType targetArray[], int n);

void insertionSort(ElementType targetArray[],int n);

void mergeSort(ElementType targetArray[], int first, int last);
namespace HelperFunc {
void merge(ElementType targetArray[], int first, int mid, int last);
}
void quickSort(ElementType targetArray[], int first, int last);

void radixSort(ElementType targetArray[], int n, int d);
}
}

#endif  // DATASTRUCTURE_ALGORITHM_CPP_BASICRAWARRAYSORT_H
