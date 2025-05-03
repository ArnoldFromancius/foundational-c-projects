//selection sort on linked lists
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* list=NULL;

//list functions
int ins_front(int val){
	if(list==NULL){
		list=malloc(sizeof(node));
		list->data=val;
		list->left=list->right=NULL;
		return 0;
	}
	node* newnode;
	newnode=malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=list;
	list=newnode;
	return 0;
}

int ins_end(int val){
	if(list==NULL){
		list=malloc(sizeof(node));
		list->data=val;
		list->left=list->right=NULL;
		return 0;
	}
	node *trav,*newnode;
	newnode=malloc(sizeof(node));
	newnode->data=val;
	newnode->right=NULL;

	trav=list;
	while(trav->right != NULL){
		trav=trav->right;
	}
	trav->right=newnode;
	newnode->left=trav;
	return 0;
}

int ins_bf(int val, int bf){
	if(list==NULL){
		list=malloc(sizeof(node));
		list->data=val;
		list->left=list->right=NULL;
		return 0;
	}
	
	node *tmp,*trav,*newnode;
	newnode=malloc(sizeof(node));
	newnode->data=val;

	trav=list;
	while(trav->data != bf){
		tmp=trav;
		trav=trav->right;
	}
	tmp->right=newnode;
	newnode->left=tmp;
	trav->left=newnode;
	newnode->right=trav;
	return 0;
}

int ins_aft(int val, int aft){
	if(list==NULL){
		list=malloc(sizeof(node));
		list->data=val;
		list->left=list->right=NULL;
		return 0;
	}
	
	node *tmp,*trav,*newnode;
	newnode=malloc(sizeof(node));
	newnode->data=val;

	trav=list;
	while(trav->data != aft){
		trav=trav->right;
	}
	tmp=trav->right;
	tmp->left=newnode;
	newnode->right=tmp;
	trav->right=newnode;
	newnode->left=trav;
	return 0;
}

void disp(){
	node* trav;
	trav=list;
	while(trav != NULL){
		printf(" %d ",trav->data);
		trav=trav->right;
	}
}

void sort(){
	int temp,i=0,flag;
	node *trav,*tmp;
	trav=tmp=list;
	while(trav->right != NULL){
		tmp=trav->right;
		flag=0;
		while(tmp != NULL){
			if(trav->data > tmp->data){
				temp=tmp->data;
				tmp->data=trav->data;
				trav->data=temp;
			}
			flag=1;
			tmp=tmp->right;
		}
		if(flag==0){
			return;
		}
		trav=trav->right;
		printf("\n#debug: pass %d: ",i+1);
		disp();
		i++;
	}
}

int main(){
	ins_end(22);
	ins_end(45);
	ins_end(90);
	ins_end(34);
	ins_end(12);
	ins_end(30);
	ins_end(15);
	ins_end(122);
	ins_end(102);
	ins_end(59);
	ins_end(98);
	ins_end(110);
	ins_end(100);
	printf("Before sort: ");
	disp();
	printf("\n");
	sort();
	printf("\n\n");
	printf("After sort: ");
	disp();
}
