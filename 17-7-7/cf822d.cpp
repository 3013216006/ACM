#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long mod=1000000007ll;
int a[5000001];
long long dp[5000001];
int main(){
	int t,l,r;
	scanf("%d%d%d",&t,&l,&r);
	memset(a,0,sizeof(a));
	for(int i=2;i<=r;i++){
		if(a[i]==0){
			for(long long j=1ll*i*i;j<=r;j+=i)
				if(!a[j]) a[j]=i;
		}

	}
	for(int i=2;i<=r;i++){
		if(a[i]==0) dp[i]=1ll*i*(i-1)/2;
		else dp[i]=dp[i/a[i]]+dp[a[i]]*i/a[i];
	}
	long long tmp=1;
	long long ans=0;
	for(int i=l;i<=r;i++){
		dp[i]%=mod;
		ans+=tmp*dp[i]%mod;
		ans%=mod;
		tmp=(tmp*t)%mod;
	}
	printf("%lld\n",ans);
}
