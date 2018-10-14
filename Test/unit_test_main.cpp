//
// Created by straydragon on 18-10-13.
//

#include <cassert>
#include <iostream>
#include <vector>

#include "../ADTs/ArrayList.h"
#include "../ADTs/LinkedList.cpp"
#include "../ADTs/exceptions/PreconditionFailedException.h"
#include "../ADTs/interfaces/List.h"
using namespace std;

template <typename E>
void ADTListTestMachine(List<E>* list) {
  cout << flush << "\ttest target implementation : " << typeid(*list).name();
  if (typeid(*list) == typeid(LinkedList<E>)) {
    LinkedList<E> linkedListCopy;
    list = new LinkedList<E>(linkedListCopy);
  }
  assert(list->getLength() == 0 && list->isEmpty());

  for (int i = 1; i <= 10; i++) assert(list->insert(i, i) == true);

  assert(list->getLength() == 10);

  for (int i = 1; i <= 10; i++) {
    assert(list->getElementAt(i) == i);
  }

  list->remove(2);

  vector<int> now1to3{1, 3, 4};
  for (int i = 1; i <= 3; i++) {
    assert(list->getElementAt(i) == now1to3[i - 1]);
    list->setElementAt(i, 5);
  }

  for (int i = 1; i <= 3; i++) {
    assert(list->getElementAt(i) == 5);
  }
  try {
    list->setElementAt(10, 1);
  } catch (...) {
  }

  try {
    list->getElementAt(list->getLength() + 1);
  } catch (...) {
  }

  list->clear();
  assert(list->getLength() == 0 && list->isEmpty());

  cout << "\t\t==OK==" << endl;
}

int main() {
  cout << "Hello! This is unit test main." << endl;

  auto* arrayList = new ArrayList<int>();
  ADTListTestMachine(arrayList);

  auto* linkedList = new LinkedList<int>();
  ADTListTestMachine(linkedList);

  cout << "\nCONGRATULATIONS! ALL TESTS PASSED SUCCESSFULLY " << endl;

  return 0;
}
