/*
TITLE: QUEUE EMPLEMENTATION USING ARRAY VERSION
DESCRIPTION: USES SHIFT OPERATION TO OVERCOME THE 
			 MAJOR DRAWBACK OF LINEAR ARRAY QUEUE
			 (SEE PREVIOUS VERSION).  
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
		trav=front;
		
		while(trav<rear){
			queue[trav]=queue[trav+1];
			trav++;	
		}
		rear--;
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
		printf("\n    -- Queue Max Capacity :: 10 --\n");
		printf("    -- Queue_Used_Space :: %d\n",rear+1);
		printf("    -- Queue-free_Space :: %d\n\n",MAX-rear-1);
		printf("______________________________________\n");
		while(i<=rear){
			printf("%d",queue[i]);
			if(i+1 != MAX){
				printf(" ->\t");
			}
			i++;
			
			if(i>4){
				printf("\n\n");
				break;
			}
		}
		
		while(i<=rear){
			printf("%d",queue[i]);
			if(i+1 != MAX){
				printf(" ->\t");
			}
			i++;
		}
		printf("\n______________________________________\n");
		
		
		
		
	}
}
