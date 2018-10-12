#include "ArrayBag.h"
#include <cstddef>

template <typename E>
ArrayBag<E>::ArrayBag() : _size(0), _capacity(DEFAULT_CAPACITY) {}

template <typename E>
int ArrayBag<E>::getCurrentSize() const {
  return 0;
}

template <typename E>
bool ArrayBag<E>::isEmpty() const {
  return false;
}

template <typename E>
bool ArrayBag<E>::add(const E& e) {
  return false;
}

template <typename E>
bool ArrayBag<E>::remove(const E& e) {
  return false;
}

template <typename E>
void ArrayBag<E>::clear() {}

template <typename E>
int ArrayBag<E>::getFrequencyOf(const E& e) const {
  return 0;
}

template <typename E>
bool ArrayBag<E>::contains(const E& e) const {
  return false;
}

template <typename E>
std::vector<E> ArrayBag<E>::toSTLVector() const {
  return std::vector<E>();
}

template<typename E>
int ArrayBag<E>::_getIndexOf(const E &target) const {
  return 0;
}
