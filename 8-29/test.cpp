#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	printf("100 100 100");
	for(int i=0;i<100;i++)
		cout << 0 << " ";
		puts("");
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++)
			printf("%d ",1000000000-j);
		puts("");
	}
}
