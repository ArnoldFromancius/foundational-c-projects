//shell sort
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
	
	//general shell sort routine 
	int temp,i,j,gap,k=0;
	gap=curser/2;
	while(gap > 0){
		i=0;
		j=gap;
		while(i<gap || j<curser){
			if(array[i]>array[j]){
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
				printf("\nPass# %d: ",k);
				display();
				k++;
			}
			
			i++;
			j++;
		}
		gap/=2;
	}
	
	//perform insertion sort on the almost sorted array
	int x,y;
	x=0;
	while(x<=curser){
		y=x;
		while(y<=curser){
			if(array[y]<array[x]){
				temp=array[y];
				array[y]=array[x];
				array[x]=temp;
				printf("\nPass# %d: ",k);
				display();
				k++;
			}
			y++;
		}
		x++;
	}
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

