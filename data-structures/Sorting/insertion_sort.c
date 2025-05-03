//insertion sort
#include<stdio.h>
#define MAX 30

int array[MAX],curser=-1;

int ins(int val){
	if(curser <= MAX){
		curser++;
		array[curser]=val;
		return 0;
	}
	return -1;
}

void display(){
	int cur=0;
	while(cur <= curser){
		printf(" %d ",array[cur]);
		cur++;
	}
	printf("\n");
}

void sort(){
	int i,temp,lowwer,upper=0,cur=0;
	printf("\n***debug info***\n");
	while(upper <= curser){
		lowwer=0;
		while(lowwer<=upper){
			if(array[upper] < array[lowwer]){
				temp=array[upper];
				array[upper]=array[lowwer];
				array[lowwer]=temp;
				printf("\n Pass #%d:",i);
				display();
				printf("\n");
			}
			i++;
			lowwer++;
		}
		upper++;
	}
	printf("\n***end of debug info***\n");
}


int main(){
	//inserting unsorted data
	ins(22);
	ins(45);
	ins(90);
	ins(34);
	ins(12);
	ins(30);
	ins(15);
	ins(122);
	ins(102);
	ins(59);
	ins(98);
	ins(110);
	ins(100);
	
	printf("\nBefore sorting: ");
	display();
	
	sort();
	
	printf("\nAfter sorting: ");
	display();
	return 0;
}
