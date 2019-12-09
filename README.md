# DataStructure-Algorithm-Cpp
A library of Data Structure And Algorithm implemented by C++


# About Project
## Try to use it!
- You can open it in **Clion**, and install the [google-test](https://github.com/google/googletest) src in the `lib` directory (_**Dependence**_):
```bash
git clone https://github.com/Straydragonl/DataStructure-Algorithm-Cpp.git \
cd DataStructure-Algorithm-Cpp \
mkdir lib \
cd lib \
git clone https://github.com/google/googletest.git
# Use Clion open the project (DataStructure-Algorithm-Cpp)
```

- or install manually by terminal:
```bash
git clone https://github.com/Straydragonl/DataStructure-Algorithm-Cpp.git \
cd DataStructure-Algorithm-Cpp \
mkdir lib \
cd lib \
git clone https://github.com/google/googletest.git
cd .. \
cmake . \
make
```

## UML Class Relation Diagram
![](https://s1.ax1x.com/2018/10/26/i6wGO1.png)

## Chief Structure
```bash
src
├── ADTs
│   ├── exceptions
│   ├── interfaces
│   │   ├── BinaryTree.h
│   │   ├── Dictionary.h
│   │   ├── Graph.h
│   │   ├── Heap.h
│   │   ├── List.h
│   │   ├── Queue.h
│   │   └── Stack.h
│   ├── AdjacencyMatrixGraph.cpp
│   ├── AdjacencyMatrixGraph.h
│   ├── ArrayHeap.cpp
│   ├── ArrayHeap.h
│   ├── ArrayList.cpp
│   ├── ArrayList.h
│   ├── ArrayQueue.cpp
│   ├── ArrayQueue.h
│   ├── ArrayStack.cpp
│   ├── ArrayStack.h
│   ├── BinaryNode.h
│   ├── BinaryNodeTree.cpp
│   ├── BinaryNodeTree.h
│   ├── BinarySearchTree.cpp
│   ├── BinarySearchTree.h
│   ├── LinkedList.cpp
│   ├── LinkedList.h
│   ├── LinkedQueue.cpp
│   ├── LinkedQueue.h
│   ├── LinkedStack.cpp
│   ├── LinkedStack.h
│   ├── ListQueue.cpp
│   ├── ListQueue.h
│   ├── Node.h
│   └── TreeNode.h
├── Algorithms
│   ├── RawArraySort.cpp
│   └── RawArraySort.h
└── Experiments
```
# TODO
## Code
### ADTs
- [x] **List** and implementations : 
    - [x] **ArrayList**
    - [x] **LinkedList** 
- [x] **Stack** and implementations :
    - [x] **ArrayList**
    - [x] **LinkedList**
- [x] **Queue** and implementations :
    - [x] **ArrayQueue**
    - [x] **LinkedQueue**
    - [x] **ListQueue**
- [x] **BinaryTree** and implementations : 
    - [x] **BinaryNodeTree**
    - [x] **BinarySearchTree**
- [ ] **Heap** and implementations : 
    - [x] **ArrayHeap** 
    - [ ] ...
- [ ] **Dictionary** and implementations : 
    - [ ] ...
- [ ] **Graph** and implementations : 
    - [ ] ...
    
### Algorithms
- Basic on raw type `[]` sort algorithms:
    - [x] **selectionSort**
    - [x] **bubbleSort**
    - [x] **insertionSort**
    - [x] **mergeSort**
    - [x] **quickSort**
    - [x] **radixSort**
    - [x] **heapSort**
    - [x] **treeSort** (Base on _BinarySearchTree_)
    
## Style
- Code Specification
  - [x] Identifier(Class:private,public,method...)
    - **Java Style** but private/protected members have prefix '**_**'
  - [x] Indent and auto format style...
    - Look up `.clang-format`
  - [x] C++ version
    - **C++11**
  - [x] Target compiler:
    - **G++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0**
  - [x] Target Platform
    - **Linux**
    
- Design principle
- ......

## Bugs:
- [ ] **[1]** Weird Segmentation Fault [See report issue](https://github.com/Straydragonl/DataStructure-Algorithm-Cpp/issues/1)
  - When: Test the LinkedQueue<E> copy constructor When `new` a Node\<E\> 
      - Error1: Segmentation Fault (G++)
      - Error2: Not expect result (Clang++)

# :+1: Good Learning Reference:
- :octocat: kdn251/interviews [中文](https://github.com/kdn251/interviews?utm_source=gold_browser_extension#data-structures) **|** [English](https://github.com/kdn251/interviews/blob/master/README-zh-cn.md#%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84)
