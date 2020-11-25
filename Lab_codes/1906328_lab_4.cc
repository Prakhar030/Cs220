#include<stdio.h>

class node {
private:
	int elem;//stores the values of nodes
	class node* next;//stores the address of next element of the list
friend class cir_list;//to use the private elements of the class in cir_list
};

class cir_list{
private:
	class node* start ;//points to one element in the list
	int length;//to calculate the length of list
public:	
	cir_list();//constructor
	~cir_list();//deconstructor
	void addelem(int toadd);//it adds an element to the list
	void print();//it prints the existing list(not asked in question)
	bool IsEmpty();//checks for emptiness of the list
	void removeelem();//removes an element from the list
	
};
cir_list::cir_list() {
	start = NULL;//when list is empty start points to nothing
	length=0;//and length of the list is 0.
	}
cir_list::~cir_list() {//deletes all the memory allocated to the node pointersby traversing through the list
	if (start==NULL){return;}
	class node* iter = start->next;
	
	class node* init = start;
	while(iter != init){
		
		class node* iterer = iter->next;
		delete iter;
		iter =iterer;
		}
	delete init;
	}
	
bool cir_list::IsEmpty() {
	if (length == 0){printf("\nIt is empty.\n");return true;}	
	else{printf("\nIt is not empty.\n");return false;}
	}
void cir_list::print() {
	if (length==0){return;}
	class node* iter = start->next;
	class node* init = start;
	printf("\n%d",init->elem);
	while(iter != init){
		printf("\n%d",iter->elem);
		iter =iter->next;
		}
	printf("\n");
}

void cir_list::addelem(int toadd) {
	
	if (start == NULL){//adding the first element requires different process
		class node* first = new node;//make a new node
		first->elem = toadd;//put the value of the first node into it
		first->next = first;//since there is only one element it points to itself
		
		start = first;//start points to this first element
		}
//as sir has mentioned in the video we need to add element such that time required to add an element is always constant hence my code adds next element after the start node everytime.I hope this explains the else code completely.
	
	else{
		class node* pred = start;
		class node* succ = start->next;
		
		class node* added = new node;
	
		added->elem = toadd;// puts the value in the node
		added->next = succ;//new node's next points to successor
		pred->next = added;//predeccessor node points the new node.
	}
	length = length+1;//increase length by one
}
//as sir has mentioned in the video we need to remove an element such that time required to remove it is always constant .hence my code removes next element after the start node everytime.I hope this explains the else code completely.
	

void cir_list::removeelem() {
	
	if (start == NULL){return;}//when there is nothing we can't remove anything
	
	
	else{
		class node* pred = start;
		
		
		class node* temp = pred->next->next;
		delete pred->next;
		pred->next=temp;
	}
	
	length = length-1;//length reduced b one.
}


int main(){
	class cir_list list1;
	//given inputs are arbitary.
	list1.addelem(123);
	list1.addelem(1234);
	list1.addelem(12345);
	list1.addelem(123465);
	list1.removeelem();
	list1.removeelem();
	list1.IsEmpty();
	list1.print();
}	
	
	
	
	
	
	
	
	
