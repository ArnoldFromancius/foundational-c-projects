//lookup table
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXDEF 25
#define MAXTXT 100
#define HASHSIZE 10

typedef struct nd{
	char def[MAXDEF];	//name of definition
	char txt[MAXTXT];	//replacement text
	struct nd *next; //next val in sequence
}node;

node *table[HASHSIZE];	//lookup table

void init_table(node *table[]){
	//initialises lookup table:: sets all vals to null
	int i=0;
	while(i<HASHSIZE){
		table[i]=NULL;
		i++;
	}
}

int hash(char *txt){
	unsigned hashval=0;
	int i=0;
	while((*(txt+i))!='\0'){
		hashval=*(txt+i) + 31 +  hashval;
		i++;
	}
	return hashval%HASHSIZE;
}

void upload(char *def, char *txt){
	//inserts a new entry into table
	unsigned hashval;
	hashval=hash(def);
	
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	strcpy(newnode->txt,txt);
	strcpy(newnode->def,def);
	newnode->next=NULL;
	
	if(table[hashval]==NULL){
		table[hashval]=newnode;
		return;
	}
	else{
		node *tmp,*place_holder;
		tmp=table[hashval];
		while(tmp!=NULL){
			place_holder=tmp;
			tmp=tmp->next;
		}	
		place_holder->next=newnode;
		return;
	}	
}

void view_table(node *table[]){
	int i=0;
	node *tmp;
	
	while(i<HASHSIZE){
		if(table[i]==NULL){
			printf("loc: %d: -- \t\t --\n\n",i+1);
			i++;
		}
		else{
			tmp=table[i];
			printf("loc: %d:",i+1);
			while(tmp!=NULL){
				printf(" def: %s\t txt: %s\n\n",tmp->def,tmp->txt);
				tmp=tmp->next;
			}
			i++;
		}
	}
}

int main(){
	init_table(table);
	upload("HASHS999","1000");
	upload("TwA","9999");
	upload("eW","5876");
	upload("MAXCHAR","0000");
	view_table(table);
}
