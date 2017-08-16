#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		printf("1 1 0\n");
		for(int i=1;i<n;i++){
			for(int j=i+2;j<=n;j++){
				printf("%d %d %d\n",j,j,i);
				printf("%d %d %d\n",i,i,j);
			}
			printf("%d %d %d\n",i+1,i+1,i);
		}
		for(int i=n-1;i>=2;i--)
			printf("%d %d %d\n",i,i,i+1);
		printf("0 1 2\n");
	}
}
