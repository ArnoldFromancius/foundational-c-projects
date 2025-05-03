/* TITLE: CIRCULAR ARRAY QUEUE.
   DESCRIPTION: IMPLEMENTATION OF A CIRCULAR QUEUE USING AN ARRAY.
   				OVERCOMES DRAWBACKS OF A LINEAR QUEUE WITHOUT USING
   				SHIFTING...
   	AUTHOR: ARNOLD FROMANCIUS.
   	DATE: 24/11/2019
*/

#include<stdio.h>
#define MAX 5

int queue[MAX];
int front=0, rear=-1;

int ins(int);
int del();
void display();
void peek();

int main(){
	int opt,x,y;
	
	do{
		printf("\nSelect option: \n");
		printf("1. Enqueue.\n");
		printf("2. Dequeue.\n");
		printf("3. Peek.\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		scanf("%d",&opt);
	
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					y=ins(x);
					if(y==-1){
						printf("\nQueue is full!!!\n");
					}
					else{
						printf("\nSuccess!!!\n");
					}
					break;
				
			case 2: y=del();
					if(y==-1){
						printf("\nQueue is empty!!!\n");
					}
					else{
						printf("\nSuccess!!! Value deleted: %d\n",y);
					}
					break;
					
			case 3: peek();
					break;
					
			case 4: display();
					break;
					
			case 5: break;
			
			default: printf("\nInvalid option!!!\n");
					 break;
		}
	}while(opt != 5);
	
	
}

int ins(int num){
	//check for overflow
	if(rear==MAX-1 && front==0){
		return -1;
	}
	
	//check if queue is initialised, if not init
	if(rear==-1){
		rear=0;
		queue[rear]=num;
		return 0;
	}
	//check if rear==Max but front != 0 (queue not completely full)
	else if(rear==MAX-1 && front!=0){
		rear=0;
		queue[rear]=num;
		return 0;
	}
	//check if rear can be incremented without overwritting data at front
	else if(rear<front){
		if(rear+1 != front){
			rear++;
			queue[rear]=num;
			return 0;
		}
		else{
			return -1;
		}
	}
	else{
		rear++;
		queue[rear]=num;
		return 0;
	}
}

int del(){
	int val;
	//check for underflow
	if(rear == -1){
		return -1;
	}
	
	//condition 1
	if(front<rear && rear<=MAX-1){
		val=queue[front];
		front++;
		return val;
	}
	//condition 2
	if(front>rear && front<MAX-1){
		val=queue[front];
		front++;
		return val;
	}
	//condition 3
	if(front>rear && front==MAX-1){
		val=queue[front];
		front=0;
		return val;
	}
	//condition 4
	if(front == rear){
		val=queue[front];
		front=0;
		rear=-1;
		return val;
	}
}

void display(){
	
	int trav;
	//check for underflow
	if(rear == -1){
		printf("\nQueue is empty!!!\n");
	}
	//condition 1
	else if(front<rear && rear<=MAX-1){
		trav=front;
		printf("\n");
		while(trav<=rear){
			printf("%d\t",queue[trav]);
			trav++;
		}
	}
	//condition 2
	else if(front>rear){
		trav=front;
		printf("\n");
		while(trav<=MAX-1){
			printf("%d\t",queue[trav]);
			trav++;
		}
		trav=0;
		while(trav<=rear){
			printf("%d\t",queue[trav]);
			trav++;
		}
	}
}

void peek(){
	//check for underflow
	if(rear== -1){
		printf("\nQueue is empty!!!\n");
	}
	else{
		printf("\nValue in front of queue: %d\n",queue[front]);
	}
}
