//
// Created by straydragon on 18-12-18.
//
#include "gtest/gtest.h"

#include "../src/ADTs/ArrayStack.h"
#include "../src/ADTs/LinkedStack.h"
#include "../src/ADTs/interfaces/Stack.h"

template<typename E>
void StackInterfaceTestSuit(Stack<E>* stack) {
  if (typeid(*stack) == typeid(LinkedStack<E>)) {
    LinkedStack<E> linkedStackCopy;
    EXPECT_TRUE(linkedStackCopy.push(1));

    stack = new LinkedStack<E>(linkedStackCopy);  //深拷贝
    EXPECT_TRUE(stack->pop());
  }

  EXPECT_TRUE(stack->isEmpty());

  for (int i = 0; i < MAX_STACK_CAPACITY; i++) {
    EXPECT_TRUE(stack->push(i));
  }
  if (typeid(*stack) == typeid(ArrayStack<E>)) {
    EXPECT_TRUE(!stack->push(-1));
  }

  EXPECT_TRUE(stack->top() == MAX_STACK_CAPACITY - 1);

  for (int i = MAX_STACK_CAPACITY - 1; i >= 0; i--) {
    EXPECT_TRUE(stack->top() == i);
    EXPECT_TRUE(stack->pop());
  }
  EXPECT_TRUE(!stack->pop());
}

TEST(ADTs_Stack_Interface, impl_ArrayStack_int) { // NOLINT(cert-err58-cpp)
  auto* arrayStack = new ArrayStack<int>();
  StackInterfaceTestSuit(arrayStack);
  delete arrayStack;
}

TEST(ADTs_Stack_Interface, impl_LinkedStack_int) { // NOLINT(cert-err58-cpp)
  auto* linkedStack = new LinkedStack<int>();
  StackInterfaceTestSuit(linkedStack);
  delete linkedStack;
}

