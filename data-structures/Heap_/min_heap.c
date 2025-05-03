//Min heap
#include<stdio.h>
#define MAX 30

int heap[MAX],curser=0;

int ins(int val){
	curser++;
	heap[curser]=val;
	
	//heapification
	int pos=curser,par,temp;
	while(1){
		par=pos/2;
		if(heap[par] <= heap[pos] || pos <= 1){
			return 0;
		}
		temp=heap[par];
		heap[par]=heap[pos];
		heap[pos]=temp;
		pos=par;
	}
}

int withdraw(){
	int ret_val=heap[1];
	heap[1]=heap[curser];
	curser--;
	
	//heapification
	int pos=1,left,right,temp;
	while(1){
		left=(pos*2);
		right=(pos*2)+1;
		
		if(heap[pos]>heap[left] || heap[pos]>heap[right]){
			if(heap[left] < heap[right]){
				temp=heap[left];
				heap[left]=heap[pos];
				heap[pos]=temp;
				pos=left;
			}
			else{
				temp=heap[right];
				heap[right]=heap[pos];
				heap[pos]=temp;
				pos=right;
			}
		}
		else{
			return ret_val;
		}
	}
}
void disp(){
	int cur=1;
	printf("\n");
	while(cur<=curser){
		printf(" %d ",heap[cur]);
		cur++;
	}
	printf("\n");
}

int main(){
	ins(45);
	ins(35);
	ins(54);
	ins(27);
	ins(63);
	ins(72);
	ins(61);
	ins(18);
	int a,b,c,d,e,f,g,h;
	a=withdraw();
	b=withdraw();
	c=withdraw();
	d=withdraw();
	e=withdraw();
	f=withdraw();
	g=withdraw();
	h=withdraw();
	disp();
	printf("\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",a,b,c,d,e,f,g,h);
}
