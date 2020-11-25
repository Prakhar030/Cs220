#include<stdio.h>
#include"List.h"
class Queue {
private:
	LinkedList lst;
public:
	Queue();
	void enqueue(int x);
	int dequeue();
	void print();
	
};
/////////////////////////////////////////////////
Queue::Queue() {}
///////////////////////////////////////////////
void Queue::enqueue(int x){
	lst.addback(x);
}
////////////////////////////////////////////////
int Queue::dequeue(){
	int x = lst[0];
	lst.removefront();
	return x;
}
///////////////////////////////////////////////////
void Queue::print(){
	printf("\n");
	lst.print();
}
/////////////////////////////////////////////////
int main(){
	class Queue q;
	q.enqueue(90);
	q.enqueue(30);
	printf("\n");
	q.print();
	printf("\nremoved:%d",q.dequeue());
	q.print();
}
