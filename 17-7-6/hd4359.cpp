#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int mod = 1000000007;
long long dp[362][362];
long long c[361][361];
long long sum[361][361];
int main(){
	int n=360;
	int cas=1;
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	memset(c,0,sizeof(c));
	dp[0][0]=1;
	sum[0][0]=1;
	for(int i=0;i<=n;i++)
		c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	for(int j=1;j<=n;j++){
		for(int i=0;i<j;i++)
			sum[i][j]=sum[i][j-1];
		if(j<10)
		for(int i=1<<j;i<=n;i++)
			sum[i][j]=sum[i][j-1];

		for(int i=j;i<=n;i++){
			if(j<10) if(i>(1<<j)+1) break;
			if(i==1) dp[i][j]=1;
			else{
				int l=i-1;
				if(j<10) l=min(l,1<< (j-1));
				for(int k=j-1;k<=l;k++){

					if(j<10 && i-k-1>(1<<(j-1))) continue;
					if(k+1!=i)
						dp[i][j]+=c[i][1]*c[i-2][k]%mod*dp[k][j-1]%mod*sum[i-k-1][j-1]%mod;
					else 
						dp[i][j]+=c[i][1]*dp[k][j-1]%mod;
					dp[i][j]+=c[i][1]*c[i-2][k-1]%mod*dp[k][j-1]%mod*sum[i-k-1][j-1]%mod;
					if(i-k-1>=j-1)
						dp[i][j]-=c[i][1]*c[i-2][k]%mod*dp[k][j-1]%mod*dp[i-k-1][j-1]%mod;
				}
			}
			dp[i][j]=(dp[i][j]%mod+mod)%mod;
			sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
		}
	}
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		printf("Case #%d: %lld\n",cas++,dp[x][y]);
//		cout << c[x][y] << endl;

	}

}
