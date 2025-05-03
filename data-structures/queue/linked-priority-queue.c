#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	int priority;
	struct node* next;
}node;

node* queue;
int ins(int , int);
int del();
void disp();
void peek();
int main(){
	queue=NULL;
	int opt,x,y,z;
	
	do{
		printf("\nSelect option: \n");
		printf("1. Enque. \n");
		printf("2. Dequeue. \n");
		printf("3. Peek. \n");
		printf("4. Display. \n");
		printf("5. Exit. \n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					printf("...enter priority... ");
					scanf("%d",&y);
					z=ins(x,y);
					if(z==0){
						printf("\nSuccess!!!\n");
					}
					else{
						printf("\nError!!!\n");
					}
					break;
			
			case 2: z=del();
					if(z==0){
						printf("\nSuccess!!! element deleted: %d\n",z);
					}
					else if(z==-1){
						printf("\nQueue is empty!!!\n");
					}
					else{
						printf("\nError!!!\n");
					}
					break;
					
			case 3: peek();
					break;
					
			case 4: disp();
					break;
					
			case 5: break;
			
			default: printf("\nInvalid option!!!\n");
					 break;
		}
	}while(opt != 5);
	return 0;
}

int ins(int val, int prior){
	node* newnode;
	node* trav;
	trav=malloc(sizeof(node));
	trav=queue;
	newnode=malloc(sizeof(node));
	newnode->data=val;
	newnode->priority=prior;
	newnode->next=NULL;
	//checking if queue is initialised, if not init
	if(queue==NULL){
		queue=malloc(sizeof(node));
		queue->data=val;
		queue->priority=prior;
		queue->next=NULL;
		return 0;
	}
	//condition 1(if only one element is present in queue)
	if(queue->next == NULL){
		if(queue->priority > newnode->priority){
			newnode->next=queue;
			queue=newnode;
			return 0;
		}
		else{
			queue->next=newnode;
			return 0;
		}
	}
	//condition 2(if two or more elements present in queue)
	else{
		if(newnode->priority <= queue->priority){
			newnode->next=queue;
			queue=newnode;
			return 0;
		}
		while(trav->next != NULL){
			if(newnode->priority <= trav->next->priority){
				//check if prioities are same, if so process on FCFS basis
				if(newnode->priority == trav->next->priority){
					newnode->next=trav->next->next;
					trav->next->next=newnode;
					return 0;
				}
				//if not continue insertion
				else{
					newnode->next=trav->next;
					trav->next=newnode;
					return 0;
				}
			}
			trav=trav->next;
			if(trav->next == NULL){
				trav->next=newnode;
				return 0;	
			}
		}
	}
}

int del(){
	int retval;
	//checking for underflow
	if(queue == NULL){
		printf("Queue is empty!!!\n");
		return -1;
	}
	//if only on element in queue
	else if(queue->next==NULL){
		retval=queue->data;
		queue=NULL;
		return retval;
	}	
	else{
		retval=queue->data;
		queue=queue->next;
		return retval;
	}
}

void disp(){
	node* trav;
	trav=malloc(sizeof(node));
	trav=queue;
	//check for underflow
	if(queue == NULL){
		printf("Queue is empty!!!\n");
	}
	//condition 1(if only one element is present in queue
	else if(trav->next == NULL){
		printf("\n%d\n",trav->data);
	}
	//condtiion 2(if more than one element is present in queue
	else{
		printf("\n");
		do{
			printf("%d\t",trav->data);
			trav=trav->next;
			if(trav->next == NULL){
				printf("%d\t",trav->data);
				break;
			}
		}while(trav->next != NULL);
	}
	
}

void peek(){
	if(queue == NULL){
		printf("Queue is empty!!!\n");
	}
	else{
		printf("Value in front of queue is %d",queue->data);
	}
}



