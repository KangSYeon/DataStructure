#include "Queue.hpp"

template<typename T>
Queue<T>::Queue(int size) {// constructor
	queue_size = std::max(1, size);
	front_p = 0;
	rear_p = -1;
	queue = new T[queue_size];
}

template<typename T>
Queue<T>::~Queue() {// destructor
	clear();
}

template<typename T>
void Queue<T>::enqueue(T data) {// enqueue
	//만약 full 이 아니라면(front == back이 아니라면)
	if (isFull()) {
		cout << "Queue is full" << endl;
	}
	else if (rear_p == queue_size - 1) {
		rear_p = 0;
		queue[rear_p] = data;
	}
	else {
		queue[++rear_p] = data;
	}
}

template<typename T>
void Queue<T>::dequeue() {// dequeue
	//empty가 아니라면(front > back이 아니라면)
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else if (front_p == queue_size - 1) {
		queue[front_p] = NULL;
		front_p = 0;
	}
	else {
		queue[front_p++] = NULL;
	}
}

template<typename T>
T Queue<T>::front() {// return front data
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	else {
		return queue[front_p];
	}
}

template<typename T>
bool Queue<T>::isEmpty() {// return 1 if empty
	return (queue[front_p] == NULL);
}

template<typename T>
bool Queue<T>::isFull() {// return 1 if full
	if (size() == queue_size) {
		return 1;
	}
	return 0;
}

template<typename T>
int Queue<T>::size() {// return size of the queue
	if (queue[front_p] == NULL || rear_p == -1) {
		return 0;
	}
	else if (rear_p > front_p) {
		return (rear_p - front_p + 1); 
	}
	else if (rear_p < front_p) {
		return queue_size - (front_p - rear_p) + 1;
	}
	else {
		return 1;
	}
}

template<typename T>
void Queue<T>::clear() {// clear the queue
	int count = size();
	while (count > 0) {
		dequeue();
		count--;
	}
}

template<typename T>
void Queue<T>::printQueue() {// print all elements in the queue
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	for (int i = 0; i < size(); i++) {
		if (front_p + i >= queue_size) {
			cout << queue[front_p + i - queue_size] << " ";
		}
		else {
			cout << queue[front_p + i] << " ";
		}
	}
}