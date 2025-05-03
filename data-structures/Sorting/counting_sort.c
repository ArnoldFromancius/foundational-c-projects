//counting sort
#include<stdio.h>
#define MAX 10

int array[MAX]={5,7,2,4,5,5,7,1,2,9};

void sort(){
	int count[MAX]={},i=0;
	
	//compute values count 
	while(i<MAX){
		count[array[i]]=count[array[i]]+1;
		i++;
	}
	
	//output values to original array
	i=0;
	int j,k,l=0;
	while(i<MAX){
		j=count[i];
		k=0;
		while(k<j){
			array[l]=i;
			k++;
			l++;
		}
		i++;
	}
}

void disp(){
	int i=0;
	while(i<MAX){
		printf(" %d ",array[i]);
		i++;
	}
}

int main(){
	printf("\nBefore sorting: ");
	disp();
	sort();
	printf("\nAfter sorting: ");
	disp();
	return 0;	
}
