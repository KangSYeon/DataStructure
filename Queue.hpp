#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Queue {
public:
	Queue(int size);
	~Queue();
	void enqueue(T data);
	void dequeue();
	T front();
	bool isEmpty();
	bool isFull();
	int size();
	void clear();
	void printQueue();
private:
	int front_p;
	int rear_p;
	int queue_size;
	T* queue;
};