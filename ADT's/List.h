/////////////////////////////////////////////////////////////
class Node{
private:
	class Node* prev;
	int elem;
	class Node* next;
	
public:
	Node(int x,class Node* prv,class Node* nxt);
	Node(int x);
	Node();
friend class LinkedList;
};
////////////////////////////////////////////////////////////////////
class LinkedList{
private:
	class Node* head;
	class Node* tail;
	int length;
public:
	LinkedList();
	~LinkedList();
	
	int returnfront();
	void addfront(int x);
	void removefront();
	
	int returnback();
	void addback(int x);
	void removeback();
	
	bool search(int x);
	int element(int indx);
	int operator [] (int indx);
	void print();
	int len();
	void remove();
	void add(int x);
	bool isEmpty();
};
//////////////////////////////////////////////////////////////////////
