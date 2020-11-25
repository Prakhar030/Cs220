#include<stdio.h>
void subset(int arr[], int d[], int start, int end, int index, int r){
    int j, i;
    if (index == r) {
        for (j = 0; j < r; j++)
            printf("%d ", d[j]);
        printf("\n");
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++){
        d[index] = arr[i];
        subset(arr, d, i+1, end, index+1, r);
    }
}
void printsubset(int arr[], int k, int r){
    int d[r];
    subset(arr, d, 0, k, 0, r);
}
int main(){
int arr[20];
int j=0;
int k=0;
int i;
printf("ENTER INTEGERS(Seperated by commas):");
char c= getchar();
while (c!='\n'){
i=c-'0';
if (i!=-4){
j=(j*10)+i;
}
else{
arr[k]=j;
k=k+1;
j=0;
}
c=getchar();

}
arr[k]=j;
printf("Enter subset size:");
int r=getchar()-'0';
printsubset(arr,k,r);
}
