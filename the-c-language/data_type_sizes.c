#include<stdio.h>
#include<limits.h>

int main(){
	//signed data types
	printf("signed char min: %d\n",SCHAR_MIN);
	printf("signed char max: %d\n",SCHAR_MAX);
	printf("signed short min: %d\n",SHRT_MIN);
	printf("signed short min: %d\n",SHRT_MAX);
	printf("signed int min: %d\n",INT_MIN);
	printf("signed int min: %d\n",INT_MAX);
	printf("signed long min: %ld\n",LONG_MIN);
	printf("signed long min: %ld\n",LONG_MAX);
	//unsigned data types
	printf("unsigned char max: %u\n",UCHAR_MAX);
	printf("unsigned short max: %u\n",USHRT_MAX);
	printf("unsigned int max: %u\n",UINT_MAX);
	printf("unsigned long max: %lu\n",ULONG_MAX);
}
