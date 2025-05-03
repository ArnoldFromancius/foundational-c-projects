//Tree sort
#include<stdio.h>
#include<stdlib.h>
#define MAX 30

//create tree and its functions
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* tree=NULL;

int t_ins(int val){
	//inserts a value into the tree
	if(tree==NULL){
		tree=malloc(sizeof(node));
		tree->data=val;
		tree->left=tree->right=NULL;
		return 0;
	}
	else{
		node *newnode,*trav=tree;
		newnode=malloc(sizeof(node));
		newnode->data=val;
		newnode->left=newnode->right=NULL;
		while(1){
			if(val < trav->data){
				if(trav->left == NULL){
					trav->left=newnode;
					return 0;
				}
				else{
					trav=trav->left;
				}
			}
			else{
				if(trav->right == NULL){
					trav->right=newnode;
					return 0;
				}
				else{
					trav=trav->right;
				}
			}
		}
	}
	return -1;
}

int t_shred(node* root){
	//delets the tree
	if(root==NULL){
		return 0;
	}
	t_shred(root->left);
	t_shred(root->right);
	free(root);
	root=NULL;
}

//creating the list(array)
int array[MAX],curser=-1;

int ins(int val){
	curser++;
	array[curser]=val;
	return 0;
}
//function populates tree with array elements
void presort_1(){
	int trav=0;
	while(trav <= curser){
		t_ins(array[trav]);
		trav++;
	}
}

//function rearranges items in array to sort
int rp;
void repack(val){
	rp++;
	array[rp]=val;
}

//function inserts sorted elements back to array
void presort_2(node* root){
	if(root != NULL){
		presort_2(root->left);
		repack(root->data);
		presort_2(root->right);
	}
}

//main sort function serves as hub
void sort(){
	presort_1();
	rp=-1;
	presort_2(tree);
	t_shred(tree);
}

//
void display(){
	int trav=0;
	while(trav <= curser){
		printf(" %d ",array[trav]);
		trav++;
	}
}

int main(){
	ins(5);
	ins(2);
	ins(7);
	ins(10);
	ins(49);
	ins(3);
	ins(11);
	ins(19);
	ins(2);
	ins(23);
	printf("\nBefore: ");
	display();
	sort();	
	printf("\n\nAfter: ");
	display(tree);
}
