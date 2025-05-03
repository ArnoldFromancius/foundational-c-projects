#include<stdio.h>
#include<stdlib.h>

int enque(int);
int deque();
void peek();
void display();

typedef struct structure{
	int data;
	struct structure * next;
}node;

node* list;

int main(){
	
	node* trav;
	int opt,rt,x;
	list=malloc(sizeof(node));
	list->data=0;
	list->next=NULL;
	
	do{
		printf("\nSelect Option: \n");
		printf(" 1. Enqueue \n");
		printf(" 2. Dequeue \n");
		printf(" 3. Peek \n");
		printf(" 4. Display \n");
		printf(" 5. Exit \n\n");
		scanf("%d",&opt);
		switch(opt){
			case 1: printf("... enter data... ");
					scanf("%d",&x);
					rt=enque(x);
					if(rt == 0){
						printf("\n Success!!!\n");
					}
					break;
			case 2: rt=deque();
					if(rt == -1){
						printf("Queue is empty!\n");
					}
					else{
						printf("\n Success!!!\n Deleted value: %d\n",rt);	
					}
					
					break;
			case 3: if(list->data == 0 && list->next == NULL){
						printf("Queue is empty!\n");
					}
					else{
						printf("\n value at front of queue: %d\n",list->data);
					}
					break;
			case 4: //printf("\n");
					display();
					break;
			case 5:  free(list);
					 return 0;
			default: printf("Invalid Option!\n");
					 break;
		}
	}while(opt != 5);
	
	return 0;
}

int enque(int val){
	
	node* newnode;
	node* trav;
	trav=malloc(sizeof(node));
	newnode=malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	trav=list;
	if(trav->data == 0){
		trav->data = val;
		return 0;
	}
	if(trav->next == NULL){
			trav->next = newnode;
			return 0;	
	}
	
	else{
	
		while(trav->next != NULL){
			trav=trav->next;
		
			if(trav->next == NULL){
				trav->next = newnode;
				return 0;
			}	
		}
	}	
				
	
	
}

int deque(){
	int rtval;
	if(list->next == NULL){
		if(list->data==0){
			return -1;
		}
		rtval=list->data;
		list->data=0;
		return rtval;
	}
	int val;
	node* tempnode;
	tempnode=malloc(sizeof(node));
	val=list->data;
	tempnode=list->next;
	
	free(list);
	list=tempnode;
	
	return val;
		
}


void display(){
		
		node* trav;
		trav=malloc(sizeof(node));
		trav=list;
	
	if(trav->next == NULL && trav->data == 0){
		printf("Queue is empty!\n");
	}
	else if(trav->next == NULL){
		printf("\t");
		printf("%d\t",trav->data);
	}
	else{	
		printf("\t");
		while(trav->next != NULL){
			printf("%d\t",trav->data);
			trav=trav->next;
			if(trav->next == NULL){
				printf("%d\n",trav->data);
			}
		}
	}
}


void peek(){
	node* trav;
	trav=malloc(sizeof(node));
	trav=list;
	
	printf("%d\n",trav->data);	
	
	
}
