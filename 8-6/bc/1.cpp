#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int x,y;
		long long sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			sum+=x;
		}
		long long z;
		for(int i=0;i<m;i++){
			scanf("%lld",&z);
			if(z<=sum) printf("0");
				else printf("1");
		}
		puts("");
	}
	
}
