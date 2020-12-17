#include<stdio.h>
/*
AUTHOR -- PRAKHAR MATHUR
DATE -- 5 DECEMBER 2020
Discription-- It is the code for Tree Data Structure and implementation of its insertchild,search,relationreturner functions. 
classes used- Indiv,Childset,FamilyTree
*/
///////////////////////////////////////////////////////////////////////////
/*This class makes individual nodes for the tree data structure. Each node contains:-
1)upto 14 ancestors of the individual,
2)generation number of the individual,
3)pointer to next sibling individual,
4)data/name(int) of the individual,
5)pointer to its children set.*/
class Indiv{
private:
	int ancestor_list[14];
	int gen_no;
	int info;
	class Indiv* nextsibling;
	class Childset* childset;
public:
	Indiv(int inf,class Indiv* nextsibling,class Childset* childset);
	Indiv(int inf);
	void printIndiv();
	void ancestralcount(int parent_name,int parent_gen_no,int parent_ancestor_list[6]);
friend class Childset;
friend class FamilyTree;
};
///////////////////////////////////////////////////////////////////////////
//constructor of Indiv class
Indiv::Indiv(int inf,class Indiv* nextchild,class Childset* child){
	info=inf;
	nextsibling=nextchild;
	childset=child;
}
///////////////////////////////////////////////////////////////////////////
//constructor of Indiv class
Indiv::Indiv(int inf){
	info=inf;
	nextsibling=NULL;
	childset=NULL;
}
///////////////////////////////////////////////////////////////////////////
// For updation of ancestral roots of the individual.
//inputs: info/name of parents,their generation number,their ancestral list.
//outputs: NONE
void Indiv::ancestralcount(int parent_name,int parent_gen_no,int parent_ancestor_list[6]){
	gen_no=parent_gen_no+1;
	for (int j =0 ;j<gen_no-1;j++){
		ancestor_list[j]=parent_ancestor_list[j];
	}
	ancestor_list[gen_no-1]=parent_name;
	
}
///////////////////////////////////////////////////////////////////////////
//For printing of Individuals name/data/info.
void Indiv::printIndiv(){
	
	printf("\nThe node name is %d.\n",info);
}
///////////////////////////////////////////////////////////////////////////
/*This class makes children list for a particular individual . Each list contains:-
1)pointer to firstchild(first individual) in the set of childrens,(MADE PUBLIC FOR SELF USE)
*/
class Childset{

	
public:
	class Indiv* firstchild;
	class Indiv* searchchildinset(int x);
	class Indiv* addchildinset(int x);
	Childset(class Indiv* child);

friend class Familytree;
};
///////////////////////////////////////////////////////////////////////////
//constructor for childset
Childset::Childset(class Indiv* child){firstchild=child;}
///////////////////////////////////////////////////////////////////////////
//For adding children in the child set.
//inputs: info/name to be added
//outputs: pointer to the particular child that has been added.
class Indiv* Childset::addchildinset(int x){
	
	class Indiv* pointer = new Indiv(x);
	class Indiv* iter=firstchild;
	while (iter->nextsibling != NULL){
		iter=iter->nextsibling;
		}
	iter->nextsibling=pointer;
	return iter->nextsibling;
}
///////////////////////////////////////////////////////////////////////////
//for searching children in a particular child set.
//inputs: info/name to be searched
//outputs: pointer to the particular child that has been searched.
class Indiv* Childset::searchchildinset(int x){
	
	class Indiv* iter = firstchild;
	if (iter->info == x){return iter;}
	while ((iter->nextsibling != NULL) or (iter->childset != NULL)){
		if (iter->info == x){return iter;}
		if (iter->childset!=NULL){
			class Childset* chi=iter->childset;
			if (chi->searchchildinset(x) != NULL){return chi->searchchildinset(x);}
			
			}
		if (iter->nextsibling!=NULL){iter=iter->nextsibling;}
		else{return NULL;}
		}
	if((iter->nextsibling == NULL) and (iter->childset == NULL)){
		if (iter->info == x){return iter;}
	}
	return NULL;
}
///////////////////////////////////////////////////////////////////////////
/*This class makes individual nodes for the tree data structure. Each node contains:-
1)list of members in the tree,
2)numbers of members in the tree,
3)pointer to first individual of the tree(root),
4)pointer to child sets present in the tree.*/
class FamilyTree{
private:
	int member[200];
	int n=0;
	class Indiv* root;
	class Childset* genration;
public:
	FamilyTree(class Indiv* patriach);
	~FamilyTree();
	class Indiv* search(int x);
	void insertchild(int parentname,int childname);
	void counter(int name);
	void relationreturner(int person_one,int person_two);
};
///////////////////////////////////////////////////////////////////////////
//constructor for the family tree.
FamilyTree::FamilyTree(class Indiv* patriach){
	root = patriach;
	root->gen_no=0;
	genration = new Childset(root);
	member[0]=root->info;
	}
///////////////////////////////////////////////////////////////////////////
//distructor for the family tree.
FamilyTree::~FamilyTree(){
	
	for (int i = 0; i<=n;i++){
		class Indiv* deleter=search(member[n-i]);
		
		delete deleter;
		
	}
}
///////////////////////////////////////////////////////////////////////////
//For searching individual in the tree.
//inputs: info/name to be searched
//outputs: pointer to the particular child that has been searched.
class Indiv* FamilyTree::search(int x){
	//printf("\nopopo\n");
	class Indiv* second= genration->searchchildinset(x);
	
	return second;
	
}
///////////////////////////////////////////////////////////////////////////
//for counting and listing members added to the tree.
////inputs: info/name 
//output: NONE
void FamilyTree::counter(int name){
	n=n+1;
	member[n]=name;
}
///////////////////////////////////////////////////////////////////////////
//for adding child to the tree
//input: parent name of the individual to be added and individuals information.
//output:NONE
void FamilyTree::insertchild(int parentname,int childname){
	counter(childname);
	class Indiv* parent = genration->searchchildinset(parentname);
	
	
	if (parent->childset == NULL){
		class Indiv* newchild=new Indiv(childname);
		class Childset* siblings= new Childset(newchild);
		parent->childset=siblings;
		newchild->ancestralcount(parent->info,parent->gen_no,parent->ancestor_list);
		
	}
	else{
		class Childset* siblings= parent->childset;
		class Indiv* newchild=siblings->addchildinset(childname);
		newchild->ancestralcount(parent->info,parent->gen_no,parent->ancestor_list);
		
	}
}
///////////////////////////////////////////////////////////////////////////
//For printing relation of the two person that are inputed.
//intputs: 1st and 2nd persons name,
//output:Their relation printed.
void FamilyTree::relationreturner(int person_one,int person_two){
	class Indiv* p_one=search(person_one);
	class Indiv* p_two=search(person_two);
	int a=p_one->gen_no;
	int b=p_two->gen_no;
	int comman_ancestor;
	
	
	
	
	if ((a)>(b)){
		comman_ancestor=p_one->ancestor_list[0];
		for (int y=0;y<b;y++){
			
			if (p_one->ancestor_list[y]==p_two->ancestor_list[y]){
				comman_ancestor=p_one->ancestor_list[y];
			}
		}
		if (p_one->ancestor_list[b]==p_two->info){
				comman_ancestor=p_one->ancestor_list[b];
			}
		
	}
	else{
		comman_ancestor=p_two->ancestor_list[0];
		for (int y=0;y<a;y++){
			if (p_one->ancestor_list[y]==p_two->ancestor_list[y]){
				comman_ancestor=p_one->ancestor_list[y];
			}
		}
		if (p_one->info==p_two->ancestor_list[a]){
				comman_ancestor=p_two->ancestor_list[a];
			}
	}
	class Indiv* comman=search(comman_ancestor);
	int c=comman->gen_no;
	int d=a-c;
	int e=b-c;
	
	if (((d==0)and(e==1))){printf("%d is the parent of %d\n",person_one,person_two);return;}
	if (((d==1)and(e==0))){printf("%d is the child of %d\n",person_one,person_two);return;}
	if (((d==0)and(e==2))){printf("%d is the grand-parent of %d\n",person_one,person_two);return;}
	if (((d==2)and(e==0))){printf("%d is the grand-child of %d\n",person_one,person_two);return;}
	if (((d==0)and(e==3))){printf("%d is the Great-grand-parent of %d\n",person_one,person_two);return;}
	if (((d==3)and(e==0))){printf("%d is the Great-grand-child of %d\n",person_one,person_two);return;}
	if (((d==0)and(e>3))){printf("%d is the %d-Great-grand-parent of %d\n",person_one,e-2,person_two);return;}
	if (((d>3)and(e==0))){printf("%d is the %d-Great-grand-child of %d\n",person_one,d-2,person_two);return;}
	if (d==e){
		if (d==1){
			printf("%d is the sibling of %d\n",person_one,person_two);
			return;
		}
		else{printf("%d is the %d-cousin of %d\n",person_one,e-1,person_two);return;}
	}
	if ((d==1)and (e==2)){printf("%d is the uncle/aunt of %d\n",person_one,person_two);return;}
	if ((d==2)and (e==1)){printf("%d is the nephew/neice of %d\n",person_one,person_two);return;}
	
	if ((d==1)and (e==3)){printf("%d is the grand-uncle/aunt of %d\n",person_one,person_two);return;}
	if ((d==3)and (e==1)){printf("%d is the grand-nephew/neice of %d\n",person_one,person_two);return;}
	
	if ((d==1)and (e>3)){printf("%d is the %d-great-grand-uncle/aunt of %d\n",person_one,e-3,person_two);return;}
	if ((d>3)and (e==1)){printf("%d is the %d-great-grand-nephew/neice of %d\n",person_one,d-3,person_two);return;}
	if ((d>=2)and (e>1)){
		if (e>d){
			printf("%d is the %d cousin,%d removed of %d\n",person_one,d-1,e-2,person_two);
			return;
			}
		else{
			printf("%d is the %d cousin,%d removed of %d\n",person_one,d-3,e,person_two);
			}
	}
	
	}
///////////////////////////////////////////////////////////////////////////
int main(){
	//Makes a Tree and uses it functionality.
	
	class Indiv* first = new Indiv(90);
	
	class FamilyTree* ft = new FamilyTree(first);
	
		
	ft->insertchild(90,70);
	ft->insertchild(90,60);
	ft->insertchild(90,50);
	ft->insertchild(90,20);
	ft->insertchild(70,40);
	ft->insertchild(70,30);
	ft->insertchild(60,100);
	ft->insertchild(50,10);
	ft->insertchild(50,0);
	ft->insertchild(0,200);
	ft->insertchild(200,150);
	ft->insertchild(200,160);
	ft->insertchild(100,120);
	ft->insertchild(100,110);
	ft->insertchild(100,190);
	ft->insertchild(190,780);
	ft->insertchild(780,340);
	ft->insertchild(340,230);
	ft->insertchild(230,690);
	ft->insertchild(230,890);
	ft->insertchild(890,990);
	class Indiv* w=ft->search(990);
	if (w!= NULL){printf("Node Found!!\n");w->printIndiv();}
	else{printf("Node not found!!\n");}
	
	class Indiv* x=ft->search(40);
	if (x!= NULL){printf("Node Found!!\n");x->printIndiv();}
	else{printf("not found\n");}
	class Indiv* y=ft->search(20);
	if (y!= NULL){printf("Node Found!!\n");y->printIndiv();}
	else{printf("not found\n");}
	class Indiv* r=ft->search(2330);
	if (r!= NULL){printf("Node Found!!\n");r->printIndiv();}
	else{printf("Node not found!!\n");}
	ft->relationreturner(60,100);
	ft->relationreturner(100,60);
	ft->relationreturner(90,30);
	ft->relationreturner(30,90);
	ft->relationreturner(90,60);
	ft->relationreturner(90,100);
	ft->relationreturner(90,190);
	ft->relationreturner(90,780);
	ft->relationreturner(90,340);
	ft->relationreturner(90,230);
	ft->relationreturner(90,890);
	ft->relationreturner(90,990);
	ft->relationreturner(100,70);
	ft->relationreturner(70,100);
	ft->relationreturner(70,190);
	ft->relationreturner(70,780);
	ft->relationreturner(70,340);
	ft->relationreturner(70,230);
	ft->relationreturner(70,890);
	ft->relationreturner(70,990);
	ft->relationreturner(40,150);
	ft->relationreturner(340,120);
	ft->relationreturner(230,120);
	ft->relationreturner(690,120);
	ft->relationreturner(150,100);
	ft->relationreturner(100,200);
	ft->~FamilyTree();
}
	


