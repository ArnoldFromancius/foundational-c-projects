#include<stdio.h>
#define IN 1
#define OUT 0

main(int argc, char *argv[]){
	
	//processing arguments
	if(argc!=2){
		printf("Error: invalid arguments!!!\n ");
		printf("Usage: wc <filename>\n");
		return 1;
	}	
	//open file to wc
	FILE *fp;
	fp=fopen(argv[1],"r");
	
	int c,state;
	long wc,lc,cc;
	wc=lc=cc=0;
	state=OUT;
	fscanf(fp,"%s");
	while((c=getch(fp)) != EOF){
		++cc;
		
		if(c=='\n'){
			++lc;
		}
		
		if(c==' ' || c=='\n'){
			state=OUT;
		}
		else if(state==OUT){
				++wc;
				state=IN;
		}		
	}
	fclose(fp);
	printf("\n\nchar count: %d",cc);
	printf("\nword count: %d",wc);
	printf("\nline count: %d",lc);
}
