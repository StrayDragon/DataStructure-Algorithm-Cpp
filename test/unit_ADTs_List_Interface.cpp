//
// Created by straydragon on 18-12-18.
//
#include "gtest/gtest.h"

#include "../src/ADTs/ArrayList.h"
#include "../src/ADTs/LinkedList.h"
#include "../src/ADTs/interfaces/List.h"

template<typename E>
void ListInterfaceTestSuit(List<E>* list) {
  //FIXME:这里对于ArrayList 有点问题
//  if (typeid(*list) == typeid(LinkedList<E>)) {
//    LinkedList<E> linkedListCopy;
//    list = new LinkedList<E>(linkedListCopy);  // 浅拷贝
//  }
  list->clear();

  EXPECT_EQ(list->getLength(), 0);
  EXPECT_TRUE(list->isEmpty());

  for (int i = 1; i <= 10; i++)
    EXPECT_TRUE(list->insert(i, i));

  EXPECT_TRUE(list->getLength() == 10);

  for (int i = 1; i <= 10; i++) {
    EXPECT_TRUE(list->getElementAt(i) == i);
  }

  list->remove(2);

  std::vector<int> now1to3{1, 3, 4};
  for (int i = 1; i <= 3; i++) {
    EXPECT_TRUE(list->getElementAt(i) == now1to3[i - 1]);
    list->setElementAt(i, 5);
  }

  for (int i = 1; i <= 3; i++) {
    EXPECT_TRUE(list->getElementAt(i) == 5);
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
  EXPECT_TRUE(list->getLength() == 0 && list->isEmpty());

}

TEST(ADTs_List_Interface, impl_ArrayList_int) { // NOLINT(cert-err58-cpp)
  auto* arrayList = new ArrayList<int>();
  ListInterfaceTestSuit(arrayList);
  delete arrayList;
}

TEST(ADTs_List_Interface, impl_LinkedList_int) { // NOLINT(cert-err58-cpp)
  auto* linkedList = new LinkedList<int>();
  ListInterfaceTestSuit(linkedList);
  delete linkedList;
}

