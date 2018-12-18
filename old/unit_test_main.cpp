//
// Created by straydragon on 18-10-13.
//

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
#include "../src/ADTs/exceptions/PreconditionFailedException.h"

#include "../src/ADTs/ArrayList.h"
#include "../src/ADTs/LinkedList.h"
#include "../src/ADTs/interfaces/List.h"

template<typename E>
void ADTListTestMachine(List<E>* list) {
  cout << flush << "\ttest target implementation : " << typeid(*list).name();
  if (typeid(*list) == typeid(LinkedList<E>)) {
    LinkedList<E> linkedListCopy;
    list = new LinkedList<E>(linkedListCopy);  // 浅拷贝
  }
  assert(list->getLength() == 0 && list->isEmpty());

  for (int i = 1; i <= 10; i++)
    assert(list->insert(i, i));

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

#include "../src/ADTs/ArrayStack.h"
#include "../src/ADTs/LinkedStack.h"
#include "../src/ADTs/interfaces/Stack.h"

template<typename E>
void ADTStackTestMachine(Stack<E>* stack) {
  cout << flush << "\ttest target implementation : " << typeid(*stack).name();

  if (typeid(*stack) == typeid(LinkedStack<E>)) {
    LinkedStack<E> linkedStackCopy;
    assert(linkedStackCopy.push(1));

    stack = new LinkedStack<E>(linkedStackCopy);  //深拷贝
    assert(stack->pop());
  }

  assert(stack->isEmpty());

  for (int i = 0; i < MAX_STACK_CAPACITY; i++) {
    assert(stack->push(i));
  }
  if (typeid(*stack) == typeid(ArrayStack<E>)) {
    assert(!stack->push(-1));
  }

  assert(stack->top() == MAX_STACK_CAPACITY - 1);

  for (int i = MAX_STACK_CAPACITY - 1; i >= 0; i--) {
    assert(stack->top() == i);
    assert(stack->pop());
  }
  assert(!stack->pop());

  cout << "\t\t==OK==" << endl;
}

#include "../src/ADTs/ArrayQueue.h"
#include "../src/ADTs/LinkedQueue.h"
#include "../src/ADTs/ListQueue.h"
#include "../src/ADTs/interfaces/Queue.h"

template<typename E>
void ADTQueueTestMachine(Queue<E>* queue) {
  cout << flush << "\ttest target implementation : " << typeid(*queue).name();
  // if (typeid(*queue) == typeid(LinkedQueue<E>)) {
  //   LinkedQueue<E> linkedQueue;
  //   linkedQueue.enqueue(1);
  //   queue = new LinkedQueue<E>(linkedQueue);
  //   assert(queue->dequeue());
  // }  // FIXME:LinkedQueue<E>拷贝构造函数有点问题,见定义处注释

  assert(queue->isEmpty());

  for (int i = 0; i < MAX_QUEUE_CAPACITY; i++) {
    assert(queue->enqueue(i));
  }

  if (typeid(*queue) == typeid(ArrayQueue<E>)) {
    assert(!queue->enqueue(-1));
  }

  for (int i = 0; i < MAX_QUEUE_CAPACITY; i++) {
    assert(queue->front() == i);
    assert(queue->dequeue());
  }
  assert(!queue->dequeue());

  cout << "\t\t==OK==" << endl;
}

#include "../src/ADTs/BinaryNodeTree.h"
#include "../src/ADTs/BinarySearchTree.h"
#include "../src/ADTs/interfaces/BinaryTree.h"

template<typename E>
void ADTBinaryTreeTestMachine(BinaryTree<E>* binaryTree) {
  cout << flush
       << "\ttest target implementation : " << typeid(*binaryTree).name();
  int nodeValue[] = {41, 20, 65, 50, 91, 72, 99, 11, 29, 32};
  assert(binaryTree->isEmpty());
  assert(binaryTree->getHeight() == 0);

  for (int i = 0; i < 10; i++) {
    assert(binaryTree->add(nodeValue[i]));
    assert(binaryTree->getNumberOfNodes() == (i + 1));
  }
  assert(binaryTree->getHeight() == 4);
  assert(binaryTree->getRootElement() == nodeValue[0]);

  // 这里根节点的值需要满足一些条件(二叉搜索树性质)
  binaryTree->setRootElement(50);
  assert(binaryTree->getRootElement() == 50);

  if (typeid(*binaryTree) == typeid(BinarySearchTree<E>)) {
    while (!binaryTree->isEmpty()) {
      assert(binaryTree->remove(binaryTree->getRootElement()));
    }
    assert(binaryTree->isEmpty());
  }

  binaryTree->clear();
  assert(binaryTree->isEmpty());
  cout << "\t==OK==" << endl;
}

#include "../src/ADTs/ArrayHeap.h"
#include "../src/ADTs/interfaces/Heap.h"

template<typename E, typename Comp = std::greater<E>>
void ADTHeapTestMachine(Heap<E>* heap) {
  cout << flush << "\ttest target implementation : " << typeid(*heap).name();
#ifdef DEBUG
  auto downCastClass = [](Heap<E>* h) -> ArrayHeap<E>* {
    return dynamic_cast<ArrayHeap<E, Comp>*>(h);
  };

  cout << "\n" << downCastClass(heap) << endl;
#endif
  assert(not heap->isEmpty());
  assert(heap->getNumberOfElements() == 6);
  assert(heap->getHeight() == 3);
  // while (!heap->isEmpty())
  //   assert(heap->remove());

  heap->clear();

  assert(heap->isEmpty());
  assert(heap->add(7));
  assert(heap->add(3));
  assert(heap->add(5));
  assert(heap->add(2));
  assert(heap->add(11));

  int previous = heap->top();
  assert(heap->remove());
  int current = heap->top();
  while (true) {
    if (typeid(*heap) == typeid(ArrayHeap<E, std::greater<E>>)) {
      assert(previous > current);
    } else {
      assert(previous < current);
    }
    previous = current;
    assert(heap->remove());
    if (heap->isEmpty())
      break;
    else
      current = heap->top();
  }
  heap->clear();
  assert(heap->isEmpty());

  cout << "\t==OK==" << endl;
}

int main() {
  cout << "Hello! Unit Tests Main() ...\n" << endl;

  auto* arrayList = new ArrayList<int>();
  ADTListTestMachine(arrayList);

  auto* linkedList = new LinkedList<int>();
  ADTListTestMachine(linkedList);

  auto* arrayStack = new ArrayStack<int>();
  ADTStackTestMachine(arrayStack);

  auto* linkedStack = new LinkedStack<int>();
  ADTStackTestMachine(linkedStack);

  auto* arrayQueue = new ArrayQueue<int>();
  ADTQueueTestMachine(arrayQueue);

  auto* linkedQueue = new LinkedQueue<int>();
  ADTQueueTestMachine(linkedQueue);

  auto* listQueue = new ListQueue<int>();
  ADTQueueTestMachine(listQueue);

  auto* binaryNodeTree = new BinaryNodeTree<int>();
  ADTBinaryTreeTestMachine(binaryNodeTree);

  auto* binarySearchTree = new BinarySearchTree<int>();
  ADTBinaryTreeTestMachine(binarySearchTree);

  auto* maxHeap = new ArrayHeap<int>({6, 3, 5, 9, 2, 10});  //最大堆
  ADTHeapTestMachine(maxHeap);

  auto* minHeap = new ArrayHeap<int, less<int>>({6, 3, 5, 9, 2, 10});  //最小堆
  ADTHeapTestMachine(minHeap);

  cout << "\nCONGRATULATIONS! ALL TEST CASES PASSED SUCCESSFULLY " << endl;
  return 0;
}
