#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[110];
long long gcd(long long x,long long y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int x,y,n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(a,-1,sizeof(a));
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		a[n+1]=0;
		a[0]=100;
		for(int i=1;i<=2;i++)
			if(a[i]==-1) a[i]=a[i-1];
		for(int i=n;i>2;i--)
			if(a[i]==-1) a[i]=a[i+1];
		long long sum1=a[1]+a[2];
		long long sum2=0;
		for(int i=1;i<=n;i++)
			sum2+=a[i];
		long long d=gcd(sum1,sum2);
		sum1/=d;
		sum2/=d;
		printf("%lld/%lld\n",sum1,sum2);
		
	}
}
