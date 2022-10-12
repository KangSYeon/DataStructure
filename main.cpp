#include "Stack.cpp"
#include "Queue.cpp"

int main() {
	Stack<int> stack;
	for (int i = 0; i < 10; i++) {
		stack.push(i);
	}

	while (stack.size() != 3) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	stack.printStack();
	cout << "empty? " << stack.isEmpty() << endl;

	stack.clear();
	cout << "size: " << stack.size() << endl;

	stack.printStack();
	stack.pop();
	stack.top();

	Queue<char> queue(10);
	char hw[11] = { 'h','e','l','l','o','w','o','r','l','d', '!' };
	for (int i = 0; i < 10; i++) {
		queue.enqueue(hw[i]);
	}
	queue.printQueue();
	cout << "full? " << queue.isFull() << endl;

	while (queue.size() != 5) {
		cout << queue.front() << " ";
		queue.dequeue();
	}
	cout << endl;

	queue.printQueue();
	cout << endl;

	for (int i = 0; i < 6; i++) {
		queue.enqueue(hw[i]);
	}

	queue.printQueue();
	cout << endl;

	queue.dequeue();
	cout << "full? " << queue.isFull() << endl;
	queue.printQueue();
	cout << endl;

	queue.clear();
	queue.printQueue();
	cout << "empty? " << queue.isEmpty() << endl;

	queue.dequeue();
	queue.printQueue();
	queue.front();

	return 0;
}
