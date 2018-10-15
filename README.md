# DataStructure-Algorithm-Cpp
A library of Data Structure And Algorithm implemented by C++

# TODO
## Code
- [x] ADT List and implementations ( ArrayList , LinkedList )
- [x] ADT Stack and implementations ( ArrayList , LinkedList )
- [ ] ADT Queue and implementations ( ArrayQueue , LinkedQueue , ListQueue )

## Style
- Code Specification
  - [x] Identifier(Class:private,public,method...)
    - **Java Style** but private members have prefix '**_**'
  - [x] Indent and auto format style...
    - **`clang-format`** : **Google**
  - [x] C++ version
    - **C++11**
  - [ ] Target compiler:
    - **G++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0**
  - [ ] Target Platform
    - Linux
- Design principle
- ......

## Bugs:
- [ ] [Weird Segmentation Fault]
  - When: Test the LinkedQueue<E> copy constructor When `new` a Node<E> 
  - Error1: Segmentation Fault (G++)
  - Error2: Not expect result (Clang++)
    - [See report issue](https://github.com/Straydragonl/DataStructure-Algorithm-Cpp/issues/1)