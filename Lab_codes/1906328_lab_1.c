#include<stdio.h>
#include<stdlib.h>
int b=0;//EXTERN VARIABLE
int testinput(){
/*THIS FUNCTION TESTS THE DATATYPE OF INPUT WHETHER IT IS INTEGER(CONSIDERED +VE ONLY) OR FLOAT OR STRING ARRAY*/
int i=0;
int sum=0;//TO CALCULATE INTEGER
int num=0;//NO. OF INTEGERS(0-9) IN INPUT
int point=0;//NO. OF DECIMALS(.) IN INPUT
int sym=0;//NO. OF RANDOM CHAR(a,A,b,B,$,% etc) IN INPUT
char c = '0';
c=getchar();
while(c!='\n')
{
	i=c-'0';//DIFFERENCE IN ASCII CODE GOES INTO i
	if (i>=0 && i<=9)//CHECK FOR INTEGERS(0-9) AND CONVERTING THE STRING TO INTEGER
	{
		sum=(sum*10)+i;
		num = num+1;
		c = getchar();
	}
	if (i==(-2))//CHECK FOR DECIMALS(.)
	{
		point = point+1;	
		c=getchar();
	}
	if (i>9||i<0)//CHECK FOR RANDOM CHAR
	{
		sym = sym+1;	
		c=getchar();
	}
	
}
b=sum;

if ((num>0)&&(point==0)&&(sym==0)){
	return 10;//WHEN INPUT IS PURELY INTEGERAL
}
if ((num>0)&&(point==1)&&(sym==1)){
	return 11;//WHEN INPUT IS FLOAT
}
if (sym>0){
	return 12;//WHEN INPUT CONTAINS RANDOM CHARS
}

}
//#########################################
int findsign(){   /*FINDS INPUT SIGN*/
char u = getchar();
int k= u-'0';
if ((k==(-1)||k==(-3)||k==(-5)||k==(-6))){
	return k;
}
else{
	printf("Error in operation input.");
	printf("\nbye!\n");
	exit(0);
}
}
//##########################################FOR THE FIRST 2 LINES AND DECLARATION OF VARIABLES.
int main(){
int z=0;// VARIABLE FOR TYPE OF FIRST INPUT
int n=0;//VARIABLE FOR FIRST NUMBER
int y=0;//VARIABLE FOR SIGN
int m;//VARIABLE FOR SECOND NUMBER
int p=0;// VARIABLE FOR TYPE OF SECOND INPUT
float q=0;//VARIABLE FOR FINAL ANSWER
printf("\tPrakhar's Calculator\n");
printf("\n -----------------------------------\n");
//###########################################FOR THE FIRST INPUT ENTRY AND INTERPRETATION.
	
printf("\nEnter the first number:");
z=testinput();
n=b;
if (z==10){;
}
else if (z==11){
	printf("User input should only be in integer.");
	printf("\nbye!\n");
	exit(0);	
}
else if (z==12){
	printf("Error in input.");
	printf("\nbye!\n");
	exit(0);
}
//###############################################FOR THE OPERATION ENTRY AND INTERPRETATION.
printf("\nEnter the operation from +,-,*,/:");
y=findsign();

//##################################################FOR THE SECOND INPUT ENTRY AND INTERPRETATION.
printf("\nEnter the second number:");

char r = getchar();
p=testinput();

m =b;

if (p==10){
	printf("\n");
	
}
else if (p==11){
	printf("User input should only be in integer.\n");
	printf("\nbye!\n");
	exit(0);
}
else if (p==12){
	printf("Error in input.\n");
	printf("\nbye!\n");
	exit(0);
}
//##############################################FOR CALCULATION PURPOSES.

if (y==(-5)){
	q=n+m+0.0;
	printf("Answer=%0.3f \n",q);
} 
else if (y==(-3)){
	q=n-m+0.0;
	printf("Answer=%0.3f \n",q);
} 
else if (y==(-6)){
	q=n*m+0.0;
	printf("Answer=%0.3f \n",q);
} 
else if (y==(-1)){
	if (!(m==(0))){
		q=(n+0.0)/m;
		printf("Answer=%0.3f \n",q);
	} 
	else{
		printf("0 division error \n");
	}
	}

printf("\nbye!\n");
}
