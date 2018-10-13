//
// Created by straydragon on 18-10-13.
//

#include "ArrayList.h"

template<typename E>
ArrayList<E>::ArrayList() {

}

template<typename E>
bool ArrayList<E>::isEmpty() const {
	return false;
}

template<typename E>
int ArrayList<E>::getLength() const {
	return 0;
}

template<typename E>
bool ArrayList<E>::insert(int newPosition, const E &element) {
	return false;
}

template<typename E>
bool ArrayList<E>::remove(int position) {
	return false;
}

template<typename E>
void ArrayList<E>::clear() {

}

template<typename E>
E ArrayList<E>::getElementAt(int position) {
	return nullptr;
}

template<typename E>
E ArrayList<E>::setElementAt(int position, E &element) throw(PreconditionFailedException) {//TODO:Exceptions headers implementation;
	return nullptr;
}
