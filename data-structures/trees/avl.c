#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	int lheight;
	int rheight;
	int bf;
}node;

node* tree=NULL;





int findlh(node* root){
	if(root->left == NULL){
		return 0;
	}
	return 1+findlh(root->left);
}

int findrh(node* root){
	if(root->right == NULL){
		return 0;
	}
	return 1+findrh(root->right);
}

void refresh(node* root){
// this function calculates the height of eaxh indivaidual node
	if(root == NULL){
		return ;
	}
	root->lheight=findlh(root);
	root->rheight=findrh(root);
	root->bf=root->lheight - root->rheight;
	refresh(root->left);
	refresh(root->right);
		
}

node* analyse(node* root){
	 
	if(root == NULL){
		//printf(" NULL#\n");
		return NULL;
	}
	node *analysisl,*analysisr;
	analysisl=analyse(root->left);
	analysisr=analyse(root->right);
	if(root->bf < -1 || root->bf > 1){
		//printf(" data %d bf %d\n",root->data,root->bf);
		return root;
	}
	else if(analysisl != NULL){
		return analysisl;
	}
	else if(analysisr != NULL){
		return analysisr;
	}
	
	//else{
	//	printf(" NULL#\n");
	//	return ;
	//}
}


int ins(int val){
	if(tree==NULL){
		tree=malloc(sizeof(node));
		tree->data=val;
		tree->left=tree->right=NULL;
		tree->lheight=tree->rheight=0;
		return 0;
	}
	
	node* trav=tree;
	//setting up direction in case only one element is present in tree
	int direction=0;
	if(val > trav->data){
		direction=1;
	}
	//inserting newnode into tree
	node* newnode=malloc(sizeof(node));
	newnode->data=val;
	newnode->left=newnode->right=NULL;
	
	
	while(1){
		if(val < trav->data && trav->left != NULL){
			trav=trav->left;
			direction=0;
		}
		else if(val > trav->data && trav->right != NULL){
			trav=trav->right;
			direction=1;
		}
		else{
			if(direction == 0){
				trav->left=newnode;
				break;
			}
			else{
				trav->right=newnode;
				break;
			}
		}
	}
	//refreshing the balance factor of each individual node
	refresh(tree); 
	//analyse the tree(balance factors) for any violations.
	node* report=analyse(tree);
	/*
	if(report == NULL){ //tree is balanced
		return 0;
	}
	else{
		printf(" report %d",report->data);
	} */
	return ;
}

void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf(" %d ",root->data);
		inorder(root->right);
	}
	return;
}

int main(){
	ins(5);
	ins(7);
	ins(2);
	ins(8);
	ins(9);
	ins(1);
	
	node* report=analyse(tree);
	if(report==NULL){
		printf(" NULL ");
	}
	else{
		printf(" %d ", report->bf);
	}
	
	//printf(" %d ",tree->bf);
	//inorder(tree);
}
