#include<stdio.h>
#define CHARSET 128
#define BAR_WIDTH 35
int main(){
		
	int i,j,k,c,char_count[CHARSET]={[0 ... 127]=0};
	
	for((c=getchar());c!=EOF;(c=getchar()))
		char_count[c]++;
	
	printf("\n");
	j=BAR_WIDTH;
	while(j>=0){
		i=0;
		while(i<CHARSET){
			if(char_count[i]>=j){
				k=0;
				if(isprint(i))
					printf("\n%5d - %2c Total: %3d| ",i,i,char_count[i]);
				else{
					char temp=' ';
					printf("\n%5d - %2c Total: %3d| ",i,temp,char_count[i]);	
				}					
				while(k<j){
					printf("*");
					k++;
				}
				char_count[i]=-1;
			}
			i++;
		}
		j--;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	while(i<CHARSET){
		k=0;
		printf("\n%3d - %2c Total: %3d: ",i,i,char_count[i]);
		j=char_count[i];
		if(j>BAR_WIDTH){
			j=BAR_WIDTH;
			while(k<j){
				printf("*");
				k++;
			}
		}
		else{
			while(k<j){
				printf("*");
				k++;
			}
			while(k<BAR_WIDTH){
				printf(" ");
				k++;
			}
		}		
		i++;
	}
	*/	
	return 0;
}
