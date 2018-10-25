//
// Created by straydragon on 18-10-15.
//
#include "BinarySearchTree.h"

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_insertInOrder(BinaryNode<E>* subTreePtr,
                                                   BinaryNode<E>* newNodePtr) {
  if (subTreePtr == nullptr) {
    return newNodePtr;
  } else if (newNodePtr->getElement() < subTreePtr->getElement()) {
    auto* tmp = _insertInOrder(subTreePtr->getLeft(), newNodePtr);
    subTreePtr->setLeft(tmp);
  } else {
    auto* tmp = _insertInOrder(subTreePtr->getRight(), newNodePtr);
    subTreePtr->setRight(tmp);
  }
  return subTreePtr;
}

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_removeNode(BinaryNode<E>* subTreePtr,
                                                const E& target,
                                                bool& success) {
  if (subTreePtr == nullptr)  //目标不存在
    return nullptr;
  else if (target < subTreePtr->getElement())  //目标是不是在左面
    subTreePtr->setLeft(_removeNode(subTreePtr->getLeft(), target, success));
  else if (target > subTreePtr->getElement())  //目标是不是在右面
    subTreePtr->setRight(_removeNode(subTreePtr->getRight(), target, success));
  else if (subTreePtr->getLeft() && subTreePtr->getRight()) {  //有两个儿子
    BinaryNode<E>* properNode = subTreePtr->getRight();
    while (properNode->getLeft()) {
      properNode = properNode->getLeft();
    }
    BinaryNode<E>* tmp = properNode;
    subTreePtr->setElement(tmp->getElement());
    subTreePtr->setRight(
        _removeNode(subTreePtr->getRight(), subTreePtr->getElement(), success));
  } else {  //有一个儿子或没有儿子
    BinaryNode<E>* tmp = subTreePtr;
    if (subTreePtr->getLeft() == nullptr) {
      subTreePtr = subTreePtr->getRight();
    } else {
      subTreePtr = subTreePtr->getLeft();
    }
    delete tmp;
    success = true;
  }
  return subTreePtr;
}

template <typename E>
BinaryNode<E>* BinarySearchTree<E>::_findNode(BinaryNode<E>* treePtr,
                                              const E& target,
                                              bool& success) {
  if (treePtr == nullptr)
    return nullptr;  //没找到 QwQ
  else if (treePtr->getElement() == target) {
    success = true;
    return treePtr;  //找到了 ^_^
  } else if (treePtr->getElement() < target)
    return _findNode(treePtr->getRight(), target,
                     success);  //目标好像在左面 (-;
  else
    return _findNode(treePtr->getLeft(), target, success);  //目标好像在右面 ;-)
}

template <typename E>
BinarySearchTree<E>::BinarySearchTree() : _rootPtr(nullptr) {}

template <typename E>
BinarySearchTree<E>::BinarySearchTree(const E& rootElement) {
  _rootPtr = new BinaryNode<E>(rootElement);
}

template <typename E>
BinarySearchTree<E>::BinarySearchTree(
    const BinarySearchTree<E>& binarySearchTree) {
  _rootPtr = BinaryNodeTree<E>::_copyTree(binarySearchTree._rootPtr);
}

template <typename E>
BinarySearchTree<E>::~BinarySearchTree() {
  BinaryNodeTree<E>::_destroyTree(_rootPtr);
}

template <typename E>
BinarySearchTree<E>& BinarySearchTree<E>::operator=(
    const BinarySearchTree<E>& binarySearchTree) {
  if (this != &binarySearchTree) {
    this->clear();
    this = BinaryNodeTree<E>::_copyTree(binarySearchTree._rootPtr);
  }
  return *this;
}

template <typename E>
bool BinarySearchTree<E>::isEmpty() const {
  return (_rootPtr == nullptr);
}

template <typename E>
int BinarySearchTree<E>::getHeight() const {
  return BinaryNodeTree<E>::_getHeightHelper(_rootPtr);
}

template <typename E>
int BinarySearchTree<E>::getNumberOfNodes() const {
  return BinaryNodeTree<E>::_getNumberOfNodesHelper(_rootPtr);
}

template <typename E>
E BinarySearchTree<E>::getRootElement() const {
  if (!isEmpty())
    return _rootPtr->getElement();
  else
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " getRootElement():树为空,无根节点\n");
}

template <typename E>
void BinarySearchTree<E>::setRootElement(const E& element) {
  if (!isEmpty())
    _rootPtr->setElement(element);
  else
    throw PreconditionFailedException(std::string(typeid(this).name()) +
                                      " setRootElement():树为空,无根节点\n");
}

template <typename E>
bool BinarySearchTree<E>::add(const E& element) {
  auto* newNodePtr = new BinaryNode<E>(element);
  _rootPtr = _insertInOrder(_rootPtr, newNodePtr);
  return true;
}

template <typename E>
bool BinarySearchTree<E>::remove(const E& element) {
  bool removed = false;
  _rootPtr = _removeNode(_rootPtr, element, removed);
  return removed;
}

template <typename E>
void BinarySearchTree<E>::clear() {
  BinaryNodeTree<E>::_destroyTree(_rootPtr);
  _rootPtr = nullptr;
}

template <typename E>
E BinarySearchTree<E>::getElement(const E& element) const {
  return element;
}

template <typename E>
bool BinarySearchTree<E>::contains(const E& element) const {
  bool isExist = false;

  std::function<void(E&)> judgeTargetExist = [element, &isExist](E& e) {
    if (e == element)
      isExist = true;
  };

  BinaryNodeTree<E>::_preorderTraverseHelper(judgeTargetExist, _rootPtr);
  return isExist;
}

template <typename E>
void BinarySearchTree<E>::preorderTraverse(void (*visit)(E&)) const {
  BinaryNodeTree<E>::_preorderTraverseHelper(visit, _rootPtr);
}

template <typename E>
void BinarySearchTree<E>::inorderTraverse(void (*visit)(E&)) const {
  BinaryNodeTree<E>::_inorderTraverseHelper(visit, _rootPtr);
}

template <typename E>
void BinarySearchTree<E>::postorderTraverse(void (*visit)(E&)) const {
  BinaryNodeTree<E>::_postorderTraverseHelper(visit, _rootPtr);
}
