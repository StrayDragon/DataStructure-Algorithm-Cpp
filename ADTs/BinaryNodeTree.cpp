//
// Created by straydragon on 18-10-15.
//
// TODO:等待实现BinaryNodeTree 2/2
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
void BinaryNodeTree<E>::_destoryTree(BinaryNode<E>* subTreePtr) {
  if (subTreePtr != nullptr) {
    _destoryTree(subTreePtr->getLeft());
    _destoryTree(subTreePtr->getRight());
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

// TODO:前置方法2
template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_removeValue(BinaryNode<E>* subTreePtr,
                                               const E& target,
                                               bool& success) {
  return nullptr;
}

// TODO:前置方法3
template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_moveValueUpTree(BinaryNode<E>* subTreePtr) {
  return nullptr;
}

template <typename E>
BinaryNode<E>* BinaryNodeTree<E>::_findNode(BinaryNode<E>* treePtr,
                                            const E& target,
                                            bool& success) {
  BinaryNode<E>* ExistedNode = nullptr;
  auto findTargetExist = [&](BinaryNode<E>* curTreeNode, E& e) {
    if (e == target) {
      ExistedNode = curTreeNode;
      success = true;
    }
  };
  _findNodeHelper(findTargetExist, treePtr);
  return ExistedNode;
}

template <typename E>
void BinaryNodeTree<E>::_findNodeHelper(void (*visit)(BinaryNode<E>*, E&),
                                        BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    E rvalue = treePtr->getElement();
    visit(treePtr, rvalue);
    _findNodeHelper(visit, treePtr);
    _findNodeHelper();
  }
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
void BinaryNodeTree<E>::_preorderTraverseHelper(void (*visit)(E&),
                                                BinaryNode<E>* treePtr) const {
  if (treePtr != nullptr) {
    E rvalue = treePtr->getElement();
    visit(rvalue);
    _preorderTraverseHelper(treePtr->getLeft());
    _preorderTraverseHelper(treePtr->getRight());
  }
}

template <typename E>
void BinaryNodeTree<E>::_inorderTraverseHelper(void (*visit)(E&),
                                               BinaryNode<E>* treePtr) const {
  _inorderTraverseHelper(treePtr->getLeft());
  E rvalue = treePtr->getElement();
  visit(rvalue);
  _inorderTraverseHelper(treePtr->getRight());
}

template <typename E>
void BinaryNodeTree<E>::_postorderTraverseHelper(void (*visit)(E&),
                                                 BinaryNode<E>* treePtr) const {
  _postorderTraverseHelper(treePtr->getLeft());
  _postorderTraverseHelper(treePtr->getRight());
  E rvalue = treePtr->getElement();
  visit(rvalue);
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
  _destoryTree(_rootPtr);
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
  // TODO: 前置方法1之后要实现的
  BinaryNode<E>* targetNode = _findNode(_rootPtr, element, true);
  if (targetNode == nullptr)
    return false;
  else {
    if (targetNode->isLeaf()) {  //没儿子
      auto* willDelete = targetNode;
      delete willDelete;
      targetNode = nullptr;
    } else if (targetNode->getLeft() != nullptr &&
               targetNode->getRight() != nullptr) {  //有两个儿子
      BinaryNode<E>* willDelete = nullptr;
      auto childSelector = [&]() {
        if (_getHeightHelper(targetNode->getLeft()) >=
            _getHeightHelper(targetNode->getRight())) {
          // FIXME:我要干啥来着?我是谁?我在哪?困 =_=
        }
        // while (targetNode->getLeft())
      };
    } else {  //有左或右一个儿子
    }
    return true;
  }
}

template <typename E>
void BinaryNodeTree<E>::clear() {
  _destoryTree(_rootPtr);
}

template <typename E>
E BinaryNodeTree<E>::getElement(const E& element) const noexcept(false) {
  bool wasFound = false;
  auto* targetNode = _findNode(_rootPtr, element, wasFound);
  if (targetNode) {
    return element;
  } else {
    throw NotFoundException(std::string(typeid(this).name()) +
                            " getElement():指定元素 " + element +
                            "并不存在于树中");
  }
}

template <typename E>
bool BinaryNodeTree<E>::contains(const E& element) const {
  bool isExist = false;
  auto judgeTargetExist = [&](E& e) {
    if (e == target)
      isExist = true;
  };

  preorderTraverse(judgeTargetExist);
  return isExist;
}

template <typename E>
void BinaryNodeTree<E>::preorderTraverse(void (*visit)(E&)) const {
  _preorderTraverseHelper(visit, _rootPtr);
}

template <typename E>
void BinaryNodeTree<E>::inorderTraverse(void (*visit)(E&)) const {
  inorderTraverse(visit, _rootPtr);
}

template <typename E>
void BinaryNodeTree<E>::postorderTraverse(void (*visit)(E&)) const {
  postorderTraverse(visit, _rootPtr);
}
