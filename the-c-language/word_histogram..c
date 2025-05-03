#include<stdio.h>
#include<stdlib.h>
#define MAXWORD 25

struct node{
	char *word;
	int count;
	struct node* left;
	struct node* right;
};
struct node *tree=NULL;
	
void copy(char *to, char *from){
	int i=0;
	while((to[i]=from[i])!='\0')
		i++;
	to[i]='\0';
}

int addword(char *word){
	struct node *tmp,*nd;
	struct node *newnode;
	
	//if tree not init
	if (tree==NULL){
		tree=malloc(sizeof(struct node));
		tree->count=1;
		tree->left=NULL;
		tree->right=NULL;
		copy(tree->word,word);
		return 0;
	}
	//locate approprate node in tree
	tmp=tree;
	int res;
	while(tmp!=NULL){
		res=strcmp(tmp->word,word);
		nd=tmp;
		if(res==0){
			tmp->count+=1;
			return 0;
		}
		else if(res>0){
			tmp=tmp->left;
		}
		else if(res<0){
			tmp=tmp->right;
		}
	}
	
	//create the newnode
	newnode=malloc(sizeof(struct node));
	newnode->count=1;
	copy(newnode->word,word);
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(strcmp(nd->word,word)<0){
		nd->right=newnode;
		return 0;
	}
	else if(strcmp(nd->word,word)>0){
		nd->left=newnode;
		return 0;
	}
	return -1;
}   
                  
void disp(struct node *trav){
	if(trav==NULL)
		return;
	printf("\ncount: %d word: %5s\n",trav->count,trav->word);
	disp(trav->left);
	disp(trav->right);
}

int getword(char line[], int lim){
	int i=0,c;
	c=getchar();
	if(c==EOF)
		return -1;
	do{
		line[i++]=c;
		c=getchar();
	}while(c!=' ' && c!='\n' && i<lim);
	line[i]='\0';
	return i;
}

main(){
	
	char word[MAXWORD];
	int i=9999,c;
	printf("Enter text(ctrl-z to continue):\n");
	while(i>0){
		i=getword(word,MAXWORD);
		if(i<0)	//to avoid counting EOF
			break;
		addword(word);
	}
	printf("\n");
	disp(tree);
}
