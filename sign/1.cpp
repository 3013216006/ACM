#include <iostream>
#include <stdio.h>
#include <time.h>

int main(int argc,char *argv[]){
	time_t t=time(0);
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%m/%d %X",localtime(&t));
	printf("%s ",argv[1]);
	puts(tmp);
}
