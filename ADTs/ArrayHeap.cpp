//
// Created by straydragon on 18-10-25.
//

#include "ArrayHeap.h"

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::_getLeftChildIndex(int nodeIndex) const {
  return (2 * nodeIndex) + 1;
}

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::_getRightChildIndex(int nodeIndex) const {
  return _getLeftChildIndex(nodeIndex) + 1;
}

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::_getParentIndex(int nodeIndex) const {
  if (nodeIndex == 0)
    return 0;  // TODO:应该异常
  return ((nodeIndex - 1) / 2);
}

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::_isLeaf(int nodeIndex) const {
  return (_getLeftChildIndex(nodeIndex) > _countOfElements);
}

template <typename E, typename Compare>
void ArrayHeap<E, Compare>::_heapRebuild(int subTreeRootIndex) {
  if (!_isLeaf(subTreeRootIndex)) {
    int leftChildIndex = _getLeftChildIndex(subTreeRootIndex);

    //有右孩子没?
    int rightChildIndex = _getRightChildIndex(subTreeRootIndex);
    if (rightChildIndex < _countOfElements) {
      if (_comp(_elements[rightChildIndex], _elements[leftChildIndex]))
        leftChildIndex = rightChildIndex;
    }

    if (_comp(_elements[leftChildIndex], _elements[subTreeRootIndex])) {
      std::swap(_elements[leftChildIndex], _elements[subTreeRootIndex]);
      _heapRebuild(leftChildIndex);
    }
  }
}

template <typename E, typename Compare>
void ArrayHeap<E, Compare>::_heapCreate() {
  for (int i = _countOfElements / 2; i >= 0; --i) {
    _heapRebuild(i);
  }
}

template <typename E, typename Compare>
ArrayHeap<E, Compare>::ArrayHeap()
    : _countOfElements(0), _maxCapacity(DEFAULT_CAPACITY) {
  _elements = new E[DEFAULT_CAPACITY];
}

template <typename E, typename Compare>
ArrayHeap<E, Compare>::ArrayHeap(const E* elements, const int length)
    : _countOfElements(length), _maxCapacity(2 * length) {
  _elements = new E[2 * length];
  for (int i = 0; i < _countOfElements; ++i) {
    _elements[i] = elements[i];
  }
  _heapCreate();
}

template <typename E, typename Compare>
ArrayHeap<E, Compare>::ArrayHeap(std::initializer_list<E> elements)
    : _countOfElements(static_cast<int>(elements.size())),
      _maxCapacity(static_cast<int>(2 * elements.size())) {
  _elements = new E[2 * elements.size()];
  int i = 0;
  for (auto& e : elements)
    _elements[i++] = e;
  _heapCreate();
}

template <typename E, typename Compare>
ArrayHeap<E, Compare>::~ArrayHeap() {
  delete _elements;
}

template <typename E, typename Compare>
bool ArrayHeap<E, Compare>::isEmpty() const {
  return (_countOfElements == 0);
}

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::getNumberOfElements() const {
  return _countOfElements;
}

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::_getHeightHelper(int index) const {
  if (_isLeaf(index)) {  //注意与二叉树的同名实现有一点区别
    return 1;
  } else {
    return 1 + std::max(_getHeightHelper(_getLeftChildIndex(index)),
                        _getHeightHelper(_getRightChildIndex(index)));
  }
}

template <typename E, typename Compare>
int ArrayHeap<E, Compare>::getHeight() const {
  return _getHeightHelper(ROOT_INDEX);
}

template <typename E, typename Compare>
E ArrayHeap<E, Compare>::top() const noexcept(false) {
  if (isEmpty())
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " top():堆为空\n");
  return _elements[0];
}

template <typename E, typename Compare>
bool ArrayHeap<E, Compare>::add(const E& element) {
  _elements[_countOfElements] = element;
  int newIndex = _countOfElements;
  bool isPlacedInProperPosition = false;

  for (int parentIndex; (newIndex >= 0) && !isPlacedInProperPosition;) {
    parentIndex = _getParentIndex(newIndex);
    //  默认 _comp( lhs , rhs ):  lhs > rhs ? true : false;
    if (_comp(_elements[parentIndex], _elements[newIndex])) {
      isPlacedInProperPosition = true;
    } else {
      std::swap(_elements[parentIndex], _elements[newIndex]);
      newIndex = parentIndex;
    }
  }
  _countOfElements++;
  return true;
}

template <typename E, typename Compare>
bool ArrayHeap<E, Compare>::remove() {
  _elements[0] = _elements[_countOfElements - 1];
  _countOfElements--;
  _heapRebuild(0);
  return true;
}

template <typename E, typename Compare>
void ArrayHeap<E, Compare>::clear() {
  _countOfElements = 0;
}
