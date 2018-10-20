//
// Created by straydragon on 18-10-15.
//
#include "BinaryNodeTree.h"
#include <algorithm>
template <typename E>
int BinaryNodeTree<E>::_getHeightHelper(BinaryNode<E>* subTreePtr) const {
  if (subTreePtr == nullptr)
    return 0;
  else
    return 1 + std::max(_getHeightHelper(subTreePtr->getLeft()),
                        _getHeightHelper(subTreePtr->getRight()));
}

template <typename E>
int BinaryNodeTree<E>::_getNumberOfNodesHelper(
    BinaryNode<E>* subTreePtr) const {
  if (subTreePtr == nullptr)
    return 0;
  else {
    int sum = _getNumberOfNodesHelper(subTreePtr->getLeft());
    sum += _getNumberOfNodesHelper(subTreePtr->getRight());
    sum++;
    return sum;
    //之所以不写成
    // return _getNumberOfNodesHelper(subTreePtr->getLeft()) +
    //       _getNumberOfNodesHelper(subTreePtr->getRight()) +
    //       1;
    //因为表达式中多个相同函数求职顺序不确定(虽然这个用例无所谓),是UB
    //为了拒绝不好的C/C++编程习惯,所以多引入一个变量一条语句一个函数.
    //见 https://zh.cppreference.com/w/cpp/language/eval_order
  }
}

template <typename E>
void BinaryNodeTree<E>::_destroyTree(BinaryNode<E>* subTreePtr) {
  if (subTreePtr != nullptr) {
    _destroyTree(subTreePtr->getLeft());
    _destroyTree(subTreePtr->getRight());
    delete subTreePtr;
  }
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_balancedAdd(BinaryNode<E>* subTreePtr,
                                               BinaryNode<E>* newNodePtr) {
  if (subTreePtr == nullptr)
    return newNodePtr;
  else {
    BinaryNode<E>* leftPtr = subTreePtr->getLeft();
    BinaryNode<E>* rightPtr = subTreePtr->getRight();

    if (_getHeightHelper(leftPtr) > _getHeightHelper(rightPtr)) {
      rightPtr = _balancedAdd(rightPtr, newNodePtr);
      subTreePtr->setRight(rightPtr);
    } else {
      leftPtr = _balancedAdd(leftPtr, newNodePtr);
      subTreePtr->setLeft(leftPtr);
    }

    return subTreePtr;
  }
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_removeValue(BinaryNode<E>* subTreePtr,
                                               const E& target,
                                               bool& success) {
  return _moveValueUpTree(subTreePtr);
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_moveValueUpTree(BinaryNode<E>* subTreePtr) {
  BinaryNode<E>* willDelete = subTreePtr;
  BinaryNode<E>* left = nullptr;
  BinaryNode<E>* right = nullptr;
  while (not willDelete->isLeaf()) {
    left = willDelete->getLeft();
    right = willDelete->getRight();
    if (left && !right) {
      willDelete = willDelete->getLeft();
    } else if (!left && right) {
      willDelete = willDelete->getRight();
    } else {
      if (_getHeightHelper(left) >= _getHeightHelper(right)) {
        willDelete = willDelete->getLeft();
      } else {
        willDelete = willDelete->getRight();
      }
    }
  }
  subTreePtr->setElement(willDelete->getElement());
  delete willDelete;
  return subTreePtr;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_findNode(BinaryNode<E>* treePtr,
                                            const E& target,
                                            bool& success) {
  BinaryNode<E>* existedNode = nullptr;
  std::function<void(BinaryNode<E>*)> f = [&](BinaryNode<E>* bn) {
    if (bn->getElement() == target) {
      existedNode = bn;
    }
  };
  _preorderTraverseHelper(f, _rootPtr);
  return existedNode;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_copyTree(
    const BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    auto* newTreePtr = new BinaryNode<E>(treePtr->getElement());
    newTreePtr->setLeft(_copyTree(treePtr->getLeft()));
    newTreePtr->setRight(_copyTree(treePtr->getRight()));
  } else {
    return nullptr;
  }
}

template <typename E>
void BinaryNodeTree<E>::_preorderTraverseHelper(
    std::function<void(E&)> visit /* void (*visit)(E&)*/,
    BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    E rvalue = treePtr->getElement();
    visit(rvalue);
    _preorderTraverseHelper(visit, treePtr->getLeft());
    _preorderTraverseHelper(visit, treePtr->getRight());
  }
}
template <typename E>
void BinaryNodeTree<E>::_preorderTraverseHelper(
    std::function<void(BinaryNode<E>*)> visit /*void (*visit)(BinaryTree<E>*)*/,
    BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    visit(treePtr);
    _preorderTraverseHelper(visit, treePtr->getLeft());
    _preorderTraverseHelper(visit, treePtr->getRight());
  }
}

template <typename E>
void BinaryNodeTree<E>::_inorderTraverseHelper(void (*visit)(E&),
                                               BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    _inorderTraverseHelper(visit, treePtr->getLeft());
    E rvalue = treePtr->getElement();
    visit(rvalue);
    _inorderTraverseHelper(visit, treePtr->getRight());
  }
}

template <typename E>
void BinaryNodeTree<E>::_postorderTraverseHelper(void (*visit)(E&),
                                                 BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    _postorderTraverseHelper(visit, treePtr->getLeft());
    _postorderTraverseHelper(visit, treePtr->getRight());
    E rvalue = treePtr->getElement();
    visit(rvalue);
  }
}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree() : _rootPtr(nullptr) {}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree(const E& rootElement) {
  _rootPtr = new BinaryNode<E>(rootElement);
}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree(const E& rootElement,
                                  const BinaryNode<E>* leftTreePtr,
                                  const BinaryNode<E>* rightTreePtr) {
  _rootPtr = new BinaryNode<E>(rootElement, leftTreePtr, rightTreePtr);
}

template <typename E>
BinaryNodeTree<E>::BinaryNodeTree(const BinaryNodeTree<E>& binaryNodeTree) {
  _rootPtr = _copyTree(binaryNodeTree._rootPtr);
}

template <typename E>
BinaryNodeTree<E>& BinaryNodeTree<E>::operator=(
    const BinaryNodeTree<E>& binaryNodeTree) {
  if (this != &binaryNodeTree) {
    this->clear();
    this = _copyTree(binaryNodeTree._rootPtr);
  }
  return *this;
}

template <typename E>
BinaryNodeTree<E>::~BinaryNodeTree() {
  _destroyTree(_rootPtr);
}

template <typename E>
bool BinaryNodeTree<E>::isEmpty() const {
  return (_rootPtr == nullptr);
}

template <typename E>
int BinaryNodeTree<E>::getHeight() const {
  return _getHeightHelper(_rootPtr);
}

template <typename E>
int BinaryNodeTree<E>::getNumberOfNodes() const {
  return _getNumberOfNodesHelper(_rootPtr);
}

template <typename E>
E BinaryNodeTree<E>::getRootElement() const noexcept(false) {
  if (!isEmpty())
    return _rootPtr->getElement();
  else
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " getRootElement():树为空,无根节点\n");
}

template <typename E>
void BinaryNodeTree<E>::setRootElement(const E& element) {
  if (!isEmpty())
    _rootPtr->setElement(element);
  else
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " setRootElement():树为空,无根节点\n");
}

template <typename E>
bool BinaryNodeTree<E>::add(const E& element) {
  auto* newNodePtr = new BinaryNode<E>(element);
  _rootPtr = _balancedAdd(_rootPtr, newNodePtr);
  return true;
}

template <typename E>
bool BinaryNodeTree<E>::remove(const E& element) {
  bool wasFound = false;
  BinaryNode<E>* targetNode = _findNode(_rootPtr, element, wasFound);
  bool isRemoved = false;
  if (targetNode == nullptr)
    return isRemoved;
  else {
    _removeValue(targetNode, element, isRemoved);
  }
  return isRemoved;
}
template <typename E>
void BinaryNodeTree<E>::clear() {
  _destroyTree(_rootPtr);
}

template <typename E>
E BinaryNodeTree<E>::getElement(const E& element) const noexcept(false) {
  //    bool wasFound = false;
  //    auto* targetNode = _getElementHelper(element,wasFound);
  //    if (targetNode) {
  //      return element;
  //    } else {
  //      throw NotFoundException(std::string(typeid(this).name()) +
  //                              " getElement():指定元素并不存在于树中");
  //    }
  return element;
}

template <typename E>
bool BinaryNodeTree<E>::contains(const E& element) const {
  bool isExist = false;
  std::function<void(E&)> judgeTargetExist = [element, &isExist](E& e) {
    if (e == element)
      isExist = true;
  };

  _preorderTraverseHelper(judgeTargetExist, _rootPtr);
  return isExist;
}

template <typename E>
void BinaryNodeTree<E>::preorderTraverse(void (*visit)(E&)) const {
  _preorderTraverseHelper(visit, _rootPtr);
}

template <typename E>
void BinaryNodeTree<E>::inorderTraverse(void (*visit)(E&)) const {
  _inorderTraverseHelper(visit, _rootPtr);
}

template <typename E>
void BinaryNodeTree<E>::postorderTraverse(void (*visit)(E&)) const {
  _postorderTraverseHelper(visit, _rootPtr);
}
