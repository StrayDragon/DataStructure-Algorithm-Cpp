//
// Created by straydragon on 18-10-15.
//

#ifndef DATASTRUCTURE_ALGORITHM_CPP_LISTQUEUE_H
#define DATASTRUCTURE_ALGORITHM_CPP_LISTQUEUE_H

#include "exceptions/PreconditionFailedException.h"
#include "interfaces/Queue.h"
#include "LinkedList.h"

//P389
template <typename E>
class ListQueue  : public Queue<E>{
private:
		LinkedList<E>* _elementsPtr;

public:
		ListQueue();
		ListQueue(const ListQueue& listQueue);
		~ListQueue();

		bool isEmpty() const override ;

		bool enqueue(const E &element) override;

		bool dequeue() override ;

		E front() const noexcept(false) override ;
};

#include "ListQueue.cpp"
#endif //DATASTRUCTURE_ALGORITHM_CPP_LISTQUEUE_H
