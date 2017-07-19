#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	srand((int) time(0));
	cout << 100 << endl;
	for(int i=0;i<100;i++){
		int n=rand()%100;
		cout << n << endl;
		for(int j=0;j<n;j++)
			printf("%d ",rand()%100000000);
		puts("");
	}
}
