//
// Created by straydragon on 18-10-13.
//

#include "ArrayList.h"

template <typename E>
ArrayList<E>::ArrayList() : _length(0), _maxCapacity(DEFAULT_CAPACITY) {}

template <typename E>
bool ArrayList<E>::isEmpty() const {
  return _length == 0;
}

template <typename E>
int ArrayList<E>::getLength() const {
  return _length;
}

template <typename E>
bool ArrayList<E>::insert(int newPosition, const E& element) {
  bool canInsert = (newPosition >= 1) && (newPosition <= _length + 1) &&
                   (_length < _maxCapacity);

  if (canInsert) {
    //移动 (_length - newPosition + 1) 次
    for (int i = _length; i >= newPosition; --i)
      _elements[i] = _elements[i - 1];

    _elements[newPosition - 1] = element;  //转换数组下标
    _length++;
  }

  return canInsert;
}

template <typename E>
bool ArrayList<E>::remove(int position) {
  bool canRemove = position >= 1 && position <= _length;

  if (canRemove) {
    //移动 (_length - position + 1) 次
    for (int i = position - 1; i < _length; i++)
      _elements[i] = _elements[i + 1];

    _length--;
  }

  return canRemove;
}

template <typename E>
void ArrayList<E>::clear() {
  _length = 0;
}

template <typename E>
E ArrayList<E>::getElementAt(int position) noexcept(false) {
  if ((1 <= position) && (position <= _length)) {
    return _elements[position - 1];
  } else {
    std::string msg = std::string(typeid(this).name()) +
                      " 目标位置(position = " + std::to_string(position);
    msg += ")不符合条件,检查是否在区间[1,getLength()]中!";
    throw PreconditionFailedException(msg);
  }
}

template <typename E>
void ArrayList<E>::setElementAt(int position, E&& element) noexcept(false) {
  if ((1 <= position) && (position <= _length)) {
    _elements[position - 1] = element;
  } else {
    std::string msg = std::string(typeid(this).name()) +
                      " 目标位置(position = " + std::to_string(position);
    msg += ")不符合条件,检查是否在区间[1,getLength()]中!";
    throw PreconditionFailedException(msg);
  }
}
