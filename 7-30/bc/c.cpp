#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int pan(long long x){
	for(int i=2;i*i<=x;i++)
	if(x%i==0){
		x/=i;
		if(x%i==0) return 0;
	}
	return 1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long n;
		cin >> n;
		long long m=(long long) sqrt(n*1.0);
		long long ans=n;
		if(m>=2&&pan(m)) ans=n-m*m;
		for(int i=1;;i++){
			int flag=0;
			long long x=m+i;
			if(pan(x)) ans=min(ans,x*x-n),flag=1;
			if(flag)break;
			if(x*x-n>=ans) break;
		}
		m--;
		while(m>=2){
			if(pan(m)){
				ans=min(ans,n-m*m);
			}
			if(n-m*m>=ans) break;
			else m--;
		}
		printf("%lld\n",ans);
	}
}
