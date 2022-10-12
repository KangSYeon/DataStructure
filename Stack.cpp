#include "Stack.hpp"

template<typename T>
Stack<T>::Stack() {// constructor
	topNode = NULL;
}

template<typename T>
Stack<T>::~Stack() {// destructor
	clear();
}

template<typename T>
void Stack<T>::push(T data) {// push

	Node* node = new Node();
	node->data = data;
	node->next = topNode;
	topNode = node;
}

template<typename T>
void Stack<T>::pop() {// pop

	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	else {
		Node* node = topNode;
		topNode = node->next;
		delete node;
	}

}

template<typename T>
T Stack<T>::top() {// return top data
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	return topNode->data;
}

template<typename T>
bool Stack<T>::isEmpty() {// return 1 if empty
	if (size() == 0) {
		return 1;
	}
	return 0;
}

template<typename T>
int Stack<T>::size() {// return size of the stack
	int count = 0;
	Node* ptr = topNode;
	while (ptr != NULL) {
		count++;
		ptr = ptr->next;
	}
	return count;
}

template<typename T>
void Stack<T>::clear() {// clear the stack
	int count = size();
	while (count > 0) {
		pop();
		count--;
	}
}

template<typename T>
void Stack<T>::printStack() {// print all elements in the stack

	Node* ptr = topNode;

	if (ptr == NULL) {
		cout << "Stack is empty";
	}

	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}