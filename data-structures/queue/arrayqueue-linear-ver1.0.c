/*
TITLE: QUEUE EMPLEMENTATION USING ARRAY VERSION 1.0
DESCRIPTION: LINEAR QUEUE USING ARRAY, MAJOR 
			 DRAWBACK; ONCE QUEUE IS FULL, YOU CAN 
			 NOT INSERT MORE ELEMENTS EVEN AFTER 
			 FREEING SPACE VIA DELETION.
			 			 
AUTHOR: ARNOLD FROMANCIUS.
DATE: 23/11/2019.
*/ 

#include<stdio.h>
#define MAX 10

int queue[MAX];
int front= -1, rear= -1;

int insert(int);
void display();
void peek();
int del();

int main(){
	int opt,x,y;
	
	do{
		printf("\nSelect option: \n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					y=insert(x);
					if(y==-1){
						printf("\nQueue is full!!!\n");
					}
					else{
						printf("\nSuccess!!!\n");
					}
					break;
			
			case 2: y=del();
					if(y == -1){
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
		}
	}while(opt != 5);
	
	
	return 0;
}

int insert(int num){
	//check for overflow
	if(rear == MAX - 1){
		return -1;
	}
	
	//check if queue is initialised if not init
	if(front == -1 && rear == -1){
		front = rear = 0;
		queue[rear]=num;
		return 0;
	}
	else{
		rear++;
		queue[rear]=num;
		return 0;
	}
}

int del(){
	int val,trav;
	
	if(rear == -1){
		return -1;
	}
	
		val=queue[front];
		front++;
		
		return val;
}

void peek(){
	if(front == -1){
		printf("\nQueue is empty!!!\n");
	}
	else{
		printf("\nValue in front of queue: %d\n",queue[front]);
	}
}

void display(){
	int i=front;
	
	if(front==-1 && rear == -1){
		printf("\nQueue is empty!!!\n");
	}
	else{
		
		printf("\n");
		while(i<=rear){
			printf("%d\t",queue[i]);
			i++;
		}	
	}
}
