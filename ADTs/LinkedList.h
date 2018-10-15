//
// Created by straydragon on 18-10-13.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LINKEDLIST_H
#define DATASTRUCTURE_ALGORITHM_CPP_LINKEDLIST_H

#include "Node.h"
#include "exceptions/PreconditionFailedException.h"
#include "interfaces/List.h"

template <typename E>
class LinkedList : public List<E> {
 private:
  Node<E>* _elementsHeadPtr;
  int _length;
  /**
   * @brief 定位链表指定位置的节点
   *
   * @pre 1 <= position <= getLength()
   * @post 找到指定位置节点并返回Node<E>指针
   * @param position 指定位置
   * @return Node<E>* 返回指向指定位置Node<E>指针
   */
  Node<E>* _getNodeAt(int position) const;

 public:
  LinkedList();
  LinkedList(const LinkedList<E>& linkedList);
  virtual ~LinkedList();

  bool isEmpty() const override;

  int getLength() const override;

  bool insert(int newPosition, const E& element) override;

  bool remove(int position) override;

  void clear() override;

  /**
   * @throw PreconditionFailedException 若 position < 1 或者 position >
   * getLength()
   */
  E getElementAt(int position) noexcept(false) override;

  /**
   * @throw PreconditionFailedException 若 position < 1 或者 position >
   * getLength()
   */
  void setElementAt(int position, E&& element) noexcept(false) override;
};

#include "LinkedList.cpp"
#endif  // DATASTRUCTURE_ALGORITHM_CPP_LINKEDLIST_H
