//printf function replica
#include<stdio.h>
#include<stdarg.h>

void print(char *s, ...){
	int i=0;
			
	va_list valist;
	va_start(valist,s);
	while(s[i]!='\0'){
		if(s[i]!='%'){
			putchar(s[i++]);
			continue;
		}
		i++;
		int int_tmp;
		char char_tmp;
		char *str_tmp;
		
		int j;
		switch(s[i]){
			case 'd':	int_tmp=va_arg(valist,int);
						int_tmp=int_tmp + '0';
						putchar(int_tmp);
						break;
						
			case 'c':	char_tmp=va_arg(valist,int);
						putchar(char_tmp);
						break;
			case 's':	str_tmp=va_arg(valist,char*);
						j=0;
						while(str_tmp[j]!='\0'){
							putchar(str_tmp[j]);
							j++;
						}
						break;
			default: return;
		}
		i++;
	}
}

main(){
	
	//sprintf(s2,s);
	char *a="hello";
	int x=4;
	print("loc %d: the txt: %s",x,a);
}
