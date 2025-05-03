//binary search
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

int search(int val){
	int beg=0,mid,end=curser;
	while(beg <= end){
		mid=(beg+end)/2;
		if(array[mid]==val){
			return mid+1;
		}
		else if(array[mid] < val){
			beg=mid+1;
		}
		else if(array[mid] > val){
			end=mid-1;
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
	
	printf(" value %d is at location %d",2,search(2));
}
