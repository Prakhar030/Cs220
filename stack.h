#include "List.h"
class Stack{
private:
	LinkedList lst;
public:
	Stack();
	void push(int x);
	char top();
	bool isEmpty();
	int pop();
	void print();
};
