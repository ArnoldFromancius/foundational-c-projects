//jump search
#include<stdio.h>
#include<math.h>
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

int search(int val){
	int upper=curser,lowwer=0,block=sqrt(curser);
	//find the range in which to perform linear search
	while(1){
		if(array[lowwer] < val){
			lowwer+=block;
		}
		else if(array[lowwer] > val){
			upper=lowwer-1;
			lowwer-=block;
			break;
		}
	}
	//perform linear search between the two limits
	int i;
	for(i=lowwer;i<=upper;i++){
		if(array[i]==val){
			return i+1;
		}
	}
	return -9999;
}

int main(){
	//inserting sorted data(ascending order)
	
	ins(1);
	ins(2);
	ins(3);
	ins(4);
	ins(5);
	ins(6);
	ins(7);
	ins(8);
	ins(9);
	ins(10);
	
	printf(" value %d is at location %d",6,search(6));
}
