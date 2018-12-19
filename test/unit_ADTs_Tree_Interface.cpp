//
// Created by straydragon on 18-12-18.
//
#include "gtest/gtest.h"

#include "../src/ADTs/BinaryNodeTree.h"
#include "../src/ADTs/BinarySearchTree.h"
#include "../src/ADTs/interfaces/BinaryTree.h"

template<typename E>
void TreeInterfaceTestSuit(BinaryTree<E>* binaryTree) {
  int nodeValue[] = {41, 20, 65, 50, 91, 72, 99, 11, 29, 32};
  EXPECT_TRUE(binaryTree->isEmpty());
  EXPECT_TRUE(binaryTree->getHeight() == 0);

  for (int i = 0; i < 10; i++) {
    EXPECT_TRUE(binaryTree->add(nodeValue[i]));
    EXPECT_TRUE(binaryTree->getNumberOfNodes() == (i + 1));
  }
  EXPECT_TRUE(binaryTree->getHeight() == 4);
  EXPECT_TRUE(binaryTree->getRootElement() == nodeValue[0]);

  // 这里根节点的值需要满足一些条件(二叉搜索树性质)
  binaryTree->setRootElement(50);
  EXPECT_TRUE(binaryTree->getRootElement() == 50);

  if (typeid(*binaryTree) == typeid(BinarySearchTree<E>)) {
    while (!binaryTree->isEmpty()) {
      EXPECT_TRUE(binaryTree->remove(binaryTree->getRootElement()));
    }
    EXPECT_TRUE(binaryTree->isEmpty());
  }

  binaryTree->clear();
  EXPECT_TRUE(binaryTree->isEmpty());
}

TEST(ADTs_Tree_Interface, impl_BinaryNodeTree_int) { // NOLINT(cert-err58-cpp)
  auto* binaryNodeTree = new BinaryNodeTree<int>();
  TreeInterfaceTestSuit(binaryNodeTree);
  delete binaryNodeTree;
}

TEST(ADTs_Tree_Interface, impl_BinarySearchTree_int) { // NOLINT(cert-err58-cpp)
  auto* binarySearchTree = new BinarySearchTree<int>();
  TreeInterfaceTestSuit(binarySearchTree);
  delete binarySearchTree;
}

