#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,cas=0;
	int x;
	while(~scanf("%d",&n)){
		cas++;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&x);
				printf("a[%d][%d][%d]=%d;\n",cas,i,j,x);
			}
		}
	}
}
