//
// Created by straydragon on 18-10-19.
//

#include <iostream>
#include <memory>
#include "shared_ptr_test_use_safety_BinaryNode.h"

using namespace std;

int main() {
  shared_ptr<BinaryNode<int>> nodePtr;
  auto leftNode = make_shared<BinaryNode<int>>();
  nodePtr->setLeft(leftNode);
  return 0;
}
