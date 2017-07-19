#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int ans=1;
		while(n){
			if(n&1) ans<<=1;
			n>>=1;
		}
		printf("%d\n",ans);
	}
}
