# DataStructure-Algorithm-Cpp
A library of Data Structure And Algorithm implemented by C++

# UML Class Relation Diagram
![](https://s1.ax1x.com/2018/10/26/i6wGO1.png)

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
    - **`clang-format -style=Chromium`**
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