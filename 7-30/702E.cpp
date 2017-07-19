#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long dp[100100][36][3];
int f[100100],w[100100];
int main(){
	int n;
	long long m;
	while(~scanf("%d%lld",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
		}
		for(int i=0;i<n;i++)
			scanf("%d",&w[i]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			dp[i][0][0]=f[i];
			dp[i][0][1]=w[i];
			dp[i][0][2]=w[i];
		}
		for(int i=1;i<=35;i++){
			for(int j=0;j<n;j++){
				int fa=dp[j][i-1][0];
				dp[j][i][0]=dp[fa][i-1][0];
				dp[j][i][1]=dp[j][i-1][1]+dp[fa][i-1][1];
				dp[j][i][2]=min(dp[j][i-1][2],dp[fa][i-1][2]);
			}
		}
		for(int i=0;i<n;i++){
			long long x=m;
			int fa=i;
			long long ans1=0,ans2=dp[i][0][2];
			for(int j=35;j>=0;j--){
				long long y=1ll<<j;
				if(x>=y){
					ans1+=dp[fa][j][1];
					ans2=min(ans2,dp[fa][j][2]);
					fa=dp[fa][j][0];
					x-=y;
				}
			}
			printf("%lld %lld\n",ans1,ans2);
		}
	}
}
