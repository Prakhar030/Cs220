#include<stdio.h>
#include<stdlib.h>
#include<string.h>

///////////////////////User Datatype for storing information of phone numbers.
struct Numberdetails{
	long long int phonenumber;
	char type[50];
};
//////////////////////////User Datatype Explaining entries in phone directory.
struct phone_direc{
	char name[50];
	int noofnumbers;
	struct Numberdetails *numberdetails;
};
/////////////////////////////////////////////////////funtion for taking input from user,
struct phone_direc readfromuser(){
	struct phone_direc Phone_direc;
	int noofnums=0;
	int i;
	printf("\nPlease enter the name of the contact: ");
	scanf("%[^\n]",Phone_direc.name);
	printf("\nPlease enter number of numbers you would be adding: ");
	scanf("%d",&noofnums);
	Phone_direc.numberdetails =(struct Numberdetails*)malloc(noofnums*(sizeof(struct phone_direc)+10));
	
	for (i=1;i<=noofnums;i++){
		printf("\nPlease enter phone number %d: ",i);
		scanf("%lld",&Phone_direc.numberdetails[i].phonenumber);
		}
	
	for (i=1;i<=noofnums;i++){
		printf("\nPlease enter Type of phone number %d: ",i);
		scanf(" %[^\n]",&Phone_direc.numberdetails[i].type[0]);
		
		}
	Phone_direc.noofnumbers=noofnums;
	return Phone_direc;
}
//////////////////////////////////////////////////////////////////////////function for clearing memory,
void clearMemory(struct phone_direc Phone_direc){
	free(Phone_direc.numberdetails);
}
//////////////////////////////////////////////////////////////////////function for printing the user info,
void printcontactinfo(struct phone_direc Phone_direc){
	printf("\nx-----------x------------x----------x----------x--------------x\n");
	printf("\nContact Name: %s,\nnumber of numbers=%d,\nMobile Numbers and their types are:\n",Phone_direc.name,Phone_direc.noofnumbers);
	for (int j=1;j<=Phone_direc.noofnumbers;j++){
		printf("%lld	%s\n",Phone_direc.numberdetails[j].phonenumber,&Phone_direc.numberdetails[j].type[0]);
	}
	printf("\nx-----------x------------x----------x----------x--------------x\n");
	
}
/////////////////////////////////////////////////////////////////////function for writing into file contact.txt
int writetofile(struct phone_direc Phone_direc){
	FILE* fp= fopen("contact.txt","a");
	if (fp== NULL) return 1;
	
	
	fprintf(fp,"%s\n %d\n",Phone_direc.name,Phone_direc.noofnumbers);
	for (int j=1;j<=Phone_direc.noofnumbers;j++){
		fprintf(fp,"%lld %s\n",Phone_direc.numberdetails[j].phonenumber,&Phone_direc.numberdetails[j].type[0]);
		
	}
	
	fclose(fp);
	
	return 0;
}
////////////////////////////////////////////////////////////////////function for writing into file contact2.txt
int writetofile2(struct phone_direc Phone_direc){
	FILE* fp= fopen("contact2.txt","a");
	if (fp== NULL) return 1;
	
	
	fprintf(fp,"%s\n %d\n",Phone_direc.name,Phone_direc.noofnumbers);
	for (int j=1;j<=Phone_direc.noofnumbers;j++){
		fprintf(fp,"%lld %s\n",Phone_direc.numberdetails[j].phonenumber,&Phone_direc.numberdetails[j].type[0]);
		
	}
	
	fclose(fp);
	
	
}
//////////////////////////////////////////////////////////////////function for reading from file
struct phone_direc* readfromfile(FILE *fp){
	struct phone_direc *Phone_direc = (struct phone_direc*)calloc(1,sizeof(struct phone_direc));
	
	if (fp==NULL) return NULL;
	fscanf(fp,"%[^\n] %d\n",Phone_direc->name,&Phone_direc->noofnumbers);
	Phone_direc->numberdetails =(struct Numberdetails*)calloc(Phone_direc->noofnumbers,(sizeof(struct Numberdetails)+10));
	for (int j=1;j<=Phone_direc->noofnumbers;j++){
		fscanf(fp,"%lld %[^\n]\n",&Phone_direc->numberdetails[j].phonenumber,&Phone_direc->numberdetails[j].type[0]);
	}
	
	return Phone_direc;
}
//////////////////////////////////////////////////////////////////function which is activated when user presses 'A'
void addtocontacts(){
	struct phone_direc Phone_direc =readfromuser();
	printf("The Following inoformation would be entered into our file....");
	printcontactinfo(Phone_direc);
	writetofile(Phone_direc);
	clearMemory(Phone_direc);
}
//////////////////////////////////////////////////////////////////function which is activated when user presses 'S'
void search_in_contacts(){
	int check=0;
	long int cursor;
	long int end;
	char namesearched[50];
	FILE* fp= fopen("contact.txt","r");
	fseek(fp,0,SEEK_END);
	end = ftell(fp);
	fseek(fp,0,SEEK_SET);
	cursor =  ftell(fp);
	printf("Please enter the name you want to search:");
	scanf(" %[^\n]",namesearched);
	while (check==0 && cursor != end){
		struct phone_direc *Phone_direc = readfromfile(fp);
		cursor =  ftell(fp);
		if (strcmp(namesearched,Phone_direc->name) == 0){
			check=1;
			printf("The Following inoformation was extracted from our file....");
			printcontactinfo(*Phone_direc);
			clearMemory(*Phone_direc);
			free(Phone_direc);
			}
		}
	if (check == 0){
		printf("Sorry!!! we couldn't find the provided name.\n");
	}
}
/////////////////////////////////////////////////////////////////function which is activated when user presses 'M'
void modify_in_file(){
	int check=0;
	char c;
	long int cursor;
	long int end;
	char m[1];
	char nametomodify[50];
	FILE* fp= fopen("contact.txt","r+");
	FILE* fp2= fopen("contact2.txt","r+");
	fseek(fp,0,SEEK_END);
	end = ftell(fp);
	fseek(fp,0,SEEK_SET);
	cursor =  ftell(fp);
	printf("Please enter the name you want to modify:");
	scanf(" %[^\n]",nametomodify);
	while (cursor != end){
		struct phone_direc *Phone_direc = readfromfile(fp);
		
		cursor =  ftell(fp);
		if (strcmp(nametomodify,Phone_direc->name) == 0){
			check=1;
			printf("The Following information about the specified contact was extracted from our file....");
			printcontactinfo(*Phone_direc);
			printf("Please enter the info you want to modify:-\na : name\nb : no. of phone numbers(Beware you would have to enter the numbers and their types again)\nc : only phone numbers\nd : only type associated with phone number\n");
			scanf(" %[^\n]",m);
			if (m[0] == 'a'){
				printf("\nPlease enter the new name of the contact: ");
				scanf(" %[^\n]",Phone_direc->name);
			}
			if (m[0] == 'b'){
				int noofnums=0;
				int i;
				printf("\nPlease enter the new number of numbers you would be adding: ");
				scanf("%d",&noofnums);
				Phone_direc->noofnumbers=noofnums;
				for (i=1;i<=Phone_direc->noofnumbers;i++){
					printf("\nPlease enter new phone number %d: ",i);
					scanf("%lld",&Phone_direc->numberdetails[i].phonenumber);
				}
				for (i=1;i<=Phone_direc->noofnumbers;i++){
					printf("\nPlease enter new Type of phone number %d: ",i);
					scanf(" %[^\n]",&Phone_direc->numberdetails[i].type[0]);
				}
				
			}
			
			if (m[0] == 'c'){
				int i;
				for (i=1;i<=Phone_direc->noofnumbers;i++){
					printf("\nPlease enter new phone number %d: ",i);
					scanf("%lld",&Phone_direc->numberdetails[i].phonenumber);
				}
			}
			if (m[0] == 'd'){
				int i;
				for (i=1;i<=Phone_direc->noofnumbers;i++){
				printf("\nPlease enter new Type of phone number %d: ",i);
				scanf(" %[^\n]",&Phone_direc->numberdetails[i].type[0]);
				}
			}
			printf("Following Information has been entered into our directory: \n");
			printcontactinfo(*Phone_direc);
			writetofile2(*Phone_direc);
			clearMemory(*Phone_direc);
			free(Phone_direc);
		}
		else {	
			writetofile2(*Phone_direc);
		}		
		}
	if (check!=1){
		printf("Sorry!!! we couldn't find the provided name.\n");
	}
	fclose(fp);
	FILE* fp1 = fopen("contact.txt","w");
	c = fgetc(fp2); 
    	while (c != EOF) 
    	{ 
        	fputc(c, fp1); 
        	c = fgetc(fp2); 
    	}
    	
    	fclose(fp2);
    	fclose(fp1);
    	fclose(fopen("contact2.txt","w"));
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
int main(){
printf("Welcome to Prakhar Mathur's directory!\n");
char command;
char d;
while (command!='Q'){
	
	printf("Please enter a command (S - for Search, A - to Add, M - for Modification, Q - to Quit) : ");
	scanf(" %[^\n]",&command);
	
	char d;
	scanf("%c",&d);
	
	
	if (command=='A'){addtocontacts();}
	if (command=='S'){search_in_contacts();}
	if (command=='M'){modify_in_file();}
	//if (command=='Q'){break;}
}
 
printf("Thank You for choosing us.\n");
}

