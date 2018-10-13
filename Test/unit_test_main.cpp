//
// Created by straydragon on 18-10-13.
//

#include <cassert>
#include <iostream>
#include <vector>

#include "../ADTs/ArrayList.h"
#include "../ADTs/exceptions/PreconditionFailedException.h"
#include "../ADTs/interfaces/List.h"
using namespace std;

void testListMethod() {
  List<int>* list = new ArrayList<int>();

  assert(list->getLength() == 0 && list->isEmpty());

  for (int i = 1; i <= 10; i++) list->insert(i, i);

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

  // try {
  list->getElementAt(list->getLength()+1);
  // } catch (...) {
  // }

  list->clear();
  assert(list->getLength() == 0 && list->isEmpty());

  delete list;
}

int main() {
  cout << "Hello! This is unit test main" << endl;
  testListMethod();
  cout << "\nCONGRATULATIONS! ALL TESTS PASSED SUCCESSFULLY " << endl;

  return 0;
}
