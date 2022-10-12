#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack {
public:
	Stack();
	~Stack();
	void push(T data);
	void pop();
	T top();
	bool isEmpty();
	int size();
	void clear();
	void printStack();
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* topNode;
};