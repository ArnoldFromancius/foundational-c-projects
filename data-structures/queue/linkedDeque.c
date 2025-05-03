/*TITLE: DEQUE-LINKED LIST IMPLEMENTATION.
  DESCRIPTION: A LINKED LIST IMPLEMENTATION OF A DEQUE(DOUBLE ENDED QUEUE).
  AUTHOR: ARNOLD FROMANCIUS.
  DATE: 07/12/19.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;
node* queue;

int insF(int);
int insR(int);
int delF();
int delR();
void disp();
void peek();

int main(){
	queue=NULL;
	int x,y,z,opt;
	
	do{
 		printf("\nSelect option:\n");
 		printf("1. Insert at front.\n");
 		printf("2. Insert at rear.\n");
 		printf("3. Remove from front.\n");
 		printf("4. Remove from rear.\n");
 		printf("5. Peek.\n");
 		printf("6. Display queue.\n");
 		printf("7. Exit\n");
 		scanf("%d",&opt);
 		
 		switch(opt){
 			case 1: printf("\n...enter data... ");
 					scanf("%d",&x);
 					insF(x);
 					printf("\nSuccess!!!\n");
					break;
					
					 
			case 2: printf("\n...enter data... ");
 					scanf("%d",&x);
 					insR(x);
 					printf("\nSuccess!!!\n");
					break;
										 
			case 3: z=delF();
					if(z==-1){
						printf("\nQueue is empty!!!\n");
						break;
					}
					else{
						printf("\nSuccess!!! data deleted: %d\n",z);
						break;
					}
					
			case 4: z=delR();
					if(z==-1){
						printf("\nQueue is empty!!!\n");
						break;
					}
					else{
						printf("\nSuccess!!! data deleted: %d\n",z);
						break;
					}
					
			case 5: peek();
					break;
					
			case 6: disp();
					break;
					
			case 7: break;
		 }
	 }while(opt != 7);
	
	return 0;
}

void peek(){
	node* trav;
	trav=malloc(sizeof(node));
	trav=queue;
	//check if queue init
	if(queue==NULL){
		printf("\nQueue is empty!!!\n");
	}
	//if only one element in queue
	else if(trav->next == NULL){
		printf("\nOnly one value in queue: %d",trav->data);
	}
	//otherwise
	else{
		while(trav->next != NULL){
			trav=trav->next;
		}
		printf("\nValue at front of queue: %d\nValue at rear of queue: %d\n",queue->data,trav->data);
	}
}

void disp(){
	node* trav;
	trav=malloc(sizeof(node));
	trav=queue;
	
	//check if queue init
	if(queue==NULL){
		printf("\nQueue is empty!!!\n");
	}
	else{
		while(trav != NULL){
			printf("%d\t",trav->data);
			trav=trav->next;
		}
	}
}

int delF(){
	int val;
	//check if queue init
	if(queue==NULL){
		return -1;
	}
	val=queue->data;
	queue=queue->next;
	return val;
}

int delR(){
	
	node* trav;
	node* temp;
	temp=malloc(sizeof(node));
	trav=malloc(sizeof(node));
	trav=queue;
	int val;
	
	//check if queue init
	if(queue==NULL){
		return -1;
	}
	//if only one element in queue
	if(trav->next==NULL){
		queue=NULL;
		return val;
	}
	temp=trav;
	while(trav->next != NULL){
		temp=trav;
		trav=trav->next;
	}
	val=trav->data;
	temp->next=NULL;
	free(trav);
	return val;
}

int insF(int val){

	node* newnode;
	newnode=malloc(sizeof(node));
	
	//check if queue init
	if(queue==NULL){
		queue=malloc(sizeof(node));
		queue->data=val;
		queue->next=NULL;
		return 0;
	}
	
	//otherwise
	newnode->data=val;
	newnode->next=queue;
	queue=newnode;
	return 0;	
}

int insR(int val){
	node* newnode;
	node* trav;
	newnode=malloc(sizeof(node));
	trav=malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	
	//check if queue init
	if(queue == NULL){
		queue=malloc(sizeof(node));
		queue->data=val;
		queue->next=NULL;
		return 0;
	}
	trav=queue;
	//if only one element in queue
	if(trav->next==NULL){
		trav->next=newnode;
		return 0;
	}
	//otherwise
	while(trav->next != NULL){
		trav=trav->next;
	}
	trav->next=newnode;
	return 0;
}
