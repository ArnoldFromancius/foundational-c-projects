#include<stdio.h>
#include<stdlib.h>

typedef struct stree{
	int data;
	struct stree* left;
	struct stree* right;
}node;

node* tree=NULL;

int ins(int val){
	//if tree is empty
	if(tree==NULL){
		tree=malloc(sizeof(node));
		tree->data=val;
		tree->left=tree->right=NULL;
		return 0;
	}
	
	node *newnode,*trav;
	newnode=malloc(sizeof(node));
	newnode->data=val;
	
	//linsert newnode
	trav=tree;
	while(1){
		if(val < trav->data){
			if(trav->left==NULL){
				trav->left=newnode;
				break;
			}
			trav=trav->left;
		}	
		else{
			if(trav->right==NULL){
				trav->right=newnode;
				break;
			}
			trav=trav->right;
		}
	}
	
	//splaying the tree
}

int del(){
	
}



int main(){
	ins(5);
	ins(2);
	ins(7);
	//printf("%d",tree->right->data);	
}

