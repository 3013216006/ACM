#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,x;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0;
		int sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x==1) sum++;
			ans^=x;
		}
		if(sum!=n){
			if(ans) puts("John");
			else puts("Brother");
		}
		else{
			if(ans) puts("Brother");
			else puts("John");
		}
	}
}
