//
// Created by straydragon on 18-10-15.
//

#include "ListQueue.h"

template<typename E>
ListQueue<E>::ListQueue() {

}

template<typename E>
ListQueue<E>::ListQueue(const ListQueue &listQueue) {

}

template<typename E>
ListQueue<E>::~ListQueue() {

}

template<typename E>
bool ListQueue<E>::isEmpty() const {
	return false;
}

template<typename E>
bool ListQueue<E>::enqueue(const E &element) {
	return false;
}

template<typename E>
bool ListQueue<E>::dequeue() {
	return false;
}

template<typename E>
E ListQueue<E>::front() const noexcept(false){
	return E();
}
