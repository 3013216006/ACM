#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long d[2010][2010];
long long mod=1000000007ll;

long long getpow(long long x,int k){
	long long ret=1;
	while(k){
		if(k&1) ret=ret*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ret;
}

void init(){
	memset(d,0,sizeof(d));
	d[0][0]=1;
	d[1][0]=1;
	d[1][1]=1;
	for(int i=2;i<=2000;i++){
		d[i][0]=1;
		for(int j=1;j<=i;j++){
			d[i][j]=d[i-1][j-1]+d[i-1][j];
			if(d[i][j]>=mod) d[i][j]-=mod;
		}
	}
}
long long dp[2010];
int main(){
//	time_t st=clock();
	init();
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		dp[1]=1;
		for(int i=2;i<=n;i++){
			dp[i]=getpow(i,n);
			for(int j=1;j<i;j++)
				dp[i]-=dp[j]*d[i][j]%mod;
			dp[i]=dp[i]%mod;
			while(dp[i]<0) dp[i]+=mod;
		}
		long long ans=0;
		for(int i=1;i<=m&&i<=n;i++)
			for(int j=1;i+j<=m&&j<=n;j++){
				ans=ans+dp[i]*dp[j]%mod*d[m][i]%mod*d[m-i][j]%mod;
			}
		ans%=mod;
		cout << ans << endl;
	}
//	time_t ed=clock();
//	cout << 1.0*(ed-st)/CLOCKS_PER_SEC << endl;
}
