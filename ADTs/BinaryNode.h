//
// Created by straydragon on 18-10-14.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_BINARYNODE_H
#define DATASTRUCTURE_ALGORITHM_CPP_BINARYNODE_H

template <typename E>
class BinaryNode{
private:
	E _element;
	BinaryNode<E>* _left;
	BinaryNode<E>* _right;

public:
		BinaryNode():_left(nullptr),_right(nullptr){}

		BinaryNode(E _element) : _element(_element) ,_left(nullptr),_right(nullptr){}

		BinaryNode(E _element, BinaryNode<E> *_left, BinaryNode<E> *_right) : _element(_element), _left(_left),
		                                                                      _right(_right) {}
		bool isLeaf() const;

		E getElement() const;

		void setElement(E _element);

		BinaryNode<E> *getLeft() const;

		void setLeft(BinaryNode<E> *_left);

		BinaryNode<E> *getRight() const;

		void setRight(BinaryNode<E> *_right);
};

template<typename E>
bool BinaryNode<E>::isLeaf() const {
	return false;
}

template<typename E>
E BinaryNode<E>::getElement() const {
	return nullptr;
}

template<typename E>
void BinaryNode<E>::setElement(E _element) {

}

template<typename E>
void BinaryNode<E>::setLeft(BinaryNode<E> *_left) {

}

template<typename E>
BinaryNode<E> *BinaryNode<E>::getLeft() const {
	return nullptr;
}

template<typename E>
BinaryNode<E> *BinaryNode<E>::getRight() const {
	return nullptr;
}

template<typename E>
void BinaryNode<E>::setRight(BinaryNode<E> *_right) {

}


#endif //DATASTRUCTURE_ALGORITHM_CPP_BINARYNODE_H
