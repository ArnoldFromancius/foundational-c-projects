//chained hash table
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct node{
	int data;
	struct node* next;
}node;

node* htable[MAX];

void ht_init(){
	int i=0;
	while(i<=MAX){
		htable[i]=NULL;
		i++;
	}
}

int hash(int val){
	int return_val;
	return_val=(val + 13) % MAX;
	return return_val;
}

int ins(int val){
	int hash_val;
	hash_val=hash(val);
	if(htable[hash_val] == NULL){
		htable[hash_val]=malloc(sizeof(node));
		htable[hash_val]->data=val;
		htable[hash_val]->next=NULL;
		return 0;
	}
	else{
		node *newnode,*temp=htable[hash_val];
		newnode=malloc(sizeof(node));
		newnode->data=val;
		newnode->next=NULL;
		while(temp->next != NULL){
			temp=temp->next;
		}		
		temp->next=newnode;
		return 0;
	}
	return 1;
}

int del(int val){
	int hash_val;
	hash_val=hash(val);
	if(htable[hash_val] == NULL){
		return -1;
	}
	node *tmp,*trav=htable[hash_val];
	//if element at front of list
	int flag=0;
	if(trav->data == val){
		if(trav->next == NULL){
			flag=1;
		}
		tmp=trav;
		htable[hash_val]=trav->next;
		free(tmp);
		if(flag==1){
			htable[hash_val]=NULL;
		}
		return 0;
	}
	//otherwise
	int count=0;
	while(trav != NULL){
		tmp=trav;
		trav=trav->next;
		if(trav->data == val){
			tmp->next=trav->next;
			free(trav);
			return 0;
		}
		count++;
	}
	return -1;
}

int search(int val){
	int hash_val;
	hash_val=hash(val);
	node *trav=htable[hash_val];
	while(trav != NULL){
		if(trav->data == val){
			return hash_val;
		}
		trav=trav->next;
	}
	return -1;
}

void disp(){
	node* trav;
	int i=0;
	printf("\n*** debug ***\n");
	printf(" displaying values in hash table...\n");
	while(i <= MAX){
		trav=htable[i];
		if(trav != NULL){
			printf(" *loc=%d values:\n",i);
			do{
				printf("\t * %d\n",trav->data);
				trav=trav->next;	
			}
			while(trav != NULL);
		}	
		i++;
	}
	
}
int main(){
	int x,y,opt,ch;
	//initalize htable
	ht_init();
	do{
		printf("\n_HASH TABLE(Chained)_\n");
		printf(" 1. insert.\n");
		printf(" 2. delete \n");
		printf(" 3. search.\n");
		printf(" 4, display. \n");
		printf(" 5. exit. \n");
		ch=getchar();
		printf("%d# \n",ch);
		//check if user entered a no.
		if(!isdigit(ch)){
			//printf("invalid input!!!\n");
			//wbreak;
		}
		opt=ch-'0';
		
		switch(opt){
			case 1:	printf("...enter data.. ");
					scanf("%d",&x);
					y=ins(x);
					if(y==0){
						printf("\nSuccess!!!\n");
					}
					else{
						printf("\nError!!!\n");
					}
					break;
					
			case 2:	printf("...enter data.. ");
					scanf("%d",&x);
					y=del(x);
					if(y==0){
						printf("\nSuccess!!!\n");
					}
					else{
						printf("\nError: element not in table\n");
					}
					break;
					
			case 3: printf("...enter data.. ");
					scanf("%d",&x);
					y=search(x);
					if(y==-1){
						printf("\nElement not in table\n");
					}
					else{
						printf("\nElement located at index %d\n",y);
					}
					break;
					
			case 4: disp();
					break;
					
			case 5: break;
			
			default: printf("\ninvalid option!!!\n");
					 break;

		}
	}while(opt!=5);
	
}
