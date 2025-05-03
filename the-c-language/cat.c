//need to rewrite, did not understand what cat does
#include<stdio.h>

void file_copy(FILE *f1, FILE *f2){
	int c;
	while((c=getc(f2))!=EOF){
		putc(c,f1);
	}
}


int main(int argc, char* argv[]){
	
	FILE *infile,*apfile;
	
	//if files are passed as cmd arguments
	if(argc>2){
		int i=2;
		infile=fopen(argv[1],"a");
		while(i<argc){
			apfile=fopen(argv[i],"r");
			file_copy(infile,apfile);
			fclose(apfile);
			i++;
		}
		return 0;
	}
	
	//get input file lines from keybord
	infile=fopen(argv[1],"a");
	printf("enter lines to copy to file. [ctrl-z] to continue:\n");
	file_copy(infile,stdin);
	return 0;
}
