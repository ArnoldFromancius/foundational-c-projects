/*	TITLE: BINARY SEARCH TREE.
	DESCRIPTION: AN IMPLEMENTATION OF A BINARY SEARCH TREE AND
				 ITS OPERATIONS.
	AUTHOR: ARNOLD FROMANCIUS.
	DATE: 18/12/2019.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	struct bst* left;
	struct bst* right;
}node;

node* tree;

int findtotalnodes(node* root){
	if(root==NULL){
		return 0;
	}
	return findtotalnodes(root->left)+findtotalnodes(root->right)+1;
}

node* getlargestnode(node* root){
	if(root==NULL || root->right == NULL){
		return root;
	}
	return getlargestnode(root->right);
}

node* getsmallestnode(node* root){
	if(root==NULL || root->left == NULL){
		return root;
	}
	return getsmallestnode(root->left);
}

int height(node* root){
	if(root==NULL){
		return 0;
	}
	
	int left,right;
	left=height(root->left);
	right=height(root->right);
	
	if(left>right){
		return left+1;
	}
	else{
		return right+1;
	}
}

node* ins(node* root, int x){
	//if root uninit
	if(root==NULL){
		root=malloc(sizeof(node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(x<root->data){
		root->left=ins(root->left,x);
	}
	else{
		root->right=ins(root->right,x);
	}
}

int delflag=0;
node* del(node* root, int x){
	//if tree empty
	if(root==NULL){
		return NULL;
	}
	
	//locate element to del
	if(x<root->data){
		root->left=del(root->left,x);
	}
	else if(x>root->data){
		root->right=del(root->right,x);
	}
	else{
		//if element is leaf node
		if(root->left==NULL && root->right==NULL){
			free(root);
			root=NULL;
			return root;
		}
		//if element has only one child node
		else if(root->left==NULL || root->right==NULL){
			free(root);
			if(root->left==NULL){
				root=root->right;
			}
			else{
				root=root->left;
			}
			return root;
		}
		//if element has both child nodes
		else{
			node* temp=getlargestnode(root->left);
			root->data=temp->data;
			root->left=del(root->left,temp->data);
			return root;
		}
	}
	delflag=1;
}

void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf(" %d ",root->data);
		inorder(root->right);
	}
}

void preorder(node* root){
	if(root != NULL){
		printf(" %d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->data);
	}
}

int main(){
	tree=NULL;
	int opt;
	
	do{
		printf("\nSelect option: \n");
		printf("1. Insert element.\n");
		printf("2. Delete element \n");
		printf("3. Inorder traversal.\n");
		printf("4. preorder traversal.\n");
		printf("5. postorder traversal.\n");
		printf("6. Total nodes.\n");
		printf("7. Smallest element.\n");
		printf("8. Largest element.\n");
		printf("9. Height of tree.\n");
		printf("10. Exit.\n");
		scanf("%d",&opt);
		
		int x;
		node* X;
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					tree=ins(tree,x);
					printf("\nsuccess!!!\n");
					break;
					
			case 2: if(tree==NULL){
						printf("\nTree is empty!!!\n");
						break;
					}
					printf("...enter data... ");
					scanf("%d",&x);
					delflag=0;
					tree=del(tree,x);
					if(delflag==0){
						printf("\nsuccess!!!\n");
					}
					else{
						printf("\nelement not present in tree!!!\n");
					}					
					break;
					
			case 3: inorder(tree);
					break;
					
			case 4: preorder(tree);
					break;
					
			case 5: postorder(tree);
					break;
					
			case 6: x=findtotalnodes(tree);
					printf("\nTotalNodes: %d\n",x);
					break;
					
			case 7: X=getsmallestnode(tree);
					if(tree==NULL){
						break;
					}
					else{
						printf("\nSmallest element: %d\n",X->data);
						break;
					}
						
					
			case 8: X=getlargestnode(tree);
					if(tree==NULL){
						break;
					}
					else{
						printf("\nLargest element: %d\n",X->data);
						break;
					}
					
			case 9: x=height(tree);
					printf("\nHeight: %d",x);
					break;
			
			case 10: break;
			
			default: printf("\nInvalid option!!!\n");
					 break;
		}
	}while(opt!=10);
}
