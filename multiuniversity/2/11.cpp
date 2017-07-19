#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	int n,x,y,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int s=0;
		long long sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			s=s+x%2;
			sum=sum+x-x%2;
		}
		sum/=2;
		if(s==0) printf("%lld\n",sum*2ll);
		else{
			sum/=s;
			printf("%lld\n",sum*2ll+1ll);
		}
	}
}
