//
// Created by straydragon on 18-10-13.
//

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include "../ADTs/exceptions/PreconditionFailedException.h"

#include "../ADTs/ArrayList.h"
#include "../ADTs/LinkedList.h"
#include "../ADTs/interfaces/List.h"

template <typename E>
void ADTListTestMachine(List<E>* list) {
  cout << flush << "\ttest target implementation : " << typeid(*list).name();
  if (typeid(*list) == typeid(LinkedList<E>)) {
    LinkedList<E> linkedListCopy;
    list = new LinkedList<E>(linkedListCopy);  // TODO:浅拷贝
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

#include "../ADTs/ArrayStack.h"
#include "../ADTs/LinkedStack.h"
#include "../ADTs/interfaces/Stack.h"

template <typename E>
void ADTStackTestMachine(Stack<E>* stack) {
  cout << flush << "\ttest target implementation : " << typeid(*stack).name();

  if (typeid(*stack) == typeid(LinkedStack<E>)) {
    LinkedStack<E> linkedStackCopy;
    assert(linkedStackCopy.push(1) == true);

    stack = new LinkedStack<E>(linkedStackCopy);
    assert(stack->pop() == true);
  }

  assert(stack->isEmpty() == true);

  for (int i = 0; i < MAX_STACK_CAPACITY; i++) {
    assert(stack->push(i) == true);
  }
  if (typeid(*stack) == typeid(ArrayStack<E>)) {
    assert(stack->push(-1) == false);
  }

  assert(stack->top() == MAX_STACK_CAPACITY - 1);

  for (int i = 0; i < MAX_STACK_CAPACITY; i++) {
    assert(stack->pop() == true);
  }
  assert(stack->pop() == false);

  cout << "\t\t==OK==" << endl;
}

int main() {
  cout << "Hello! This is unit test main.\n" << endl;

  auto* arrayList = new ArrayList<int>();
  ADTListTestMachine(arrayList);

  auto* linkedList = new LinkedList<int>();
  ADTListTestMachine(linkedList);

  auto* arrayStack = new ArrayStack<int>();
  ADTStackTestMachine(arrayStack);

  auto* linkedStack = new LinkedStack<int>();
  ADTStackTestMachine(linkedStack);

  cout << "\nCONGRATULATIONS! ALL TESTS PASSED SUCCESSFULLY " << endl;
  return 0;
}
