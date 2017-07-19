#include <iostream>
#include <stdio.h>
using namespace std;
long long a[100010];

long long gcd(long long x,long long y){
	if(y==0) return x;
	return gcd(y,x%y);
}

int main(){
	int n,m;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long sum=0;
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			if(a[i]<0) a[i]=-a[i];
			sum+=a[i];
		}
		long long sum1=0;
		for(int i=0;i<n;i++){
			sum1+=a[i]*a[i];
		}
		
		long long ans=n*sum1-sum*sum;
		sum1=ans;
		if(sum1==0){
			puts("0/1");
			continue;
		}
		long long sum2=n;
		long long d=gcd(sum1,sum2);
		sum1/=d;
		sum2/=d;
		printf("%lld/%lld\n",sum1,sum2);
	}
}
