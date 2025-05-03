#include<stdio.h>
#define MAX 35

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
	int low=0,hi=curser;
	while(low != hi){
		if(array[hi] == val){
			return hi+1;
		}
		else if(array[low] == val){
			return low+1;
		}
		else{
			low++;
			hi--;
		}
	}
	return -9999;
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

	printf(" location of %d is %d",30,search(30));
}
