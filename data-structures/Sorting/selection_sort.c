//Selection sort
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

int sort(){
	int pass=0,i=0,j,tmp;
	printf("\n***debug info***\n");
	while(i <= curser){
		j=i;
		while(j <= curser){
			if(array[j] < array[i]){
				tmp=array[j];
				array[j]=array[i];
				array[i]=tmp;
				
			}
			j++;
		}
		printf("\npass %d: ",pass);
				display();
				//printf("\n");
				pass++;
		i++;
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
