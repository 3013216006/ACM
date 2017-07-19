#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	printf("300");
	for(int i=0;i<=255;i++){
		int x=i%16,y=i/16;
		if(y>9) printf("%c",'A'+y-10);
			else printf("%d",y);
		if(x>9) printf("%c",'A'+x-10);
			else printf("%d",x);
		cout << " " ;
	}
	for(int i=256;i<300;i++)
		cout << "00 ";
	puts("");
}
