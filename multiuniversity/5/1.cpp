#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m;
int dp[2010][2010];
int main(){
	n=2000;
	memset(dp,0,sizeof(dp));
	//dp[1][1]=2;
	for(int i=1;i<=n;i++){
		dp[i][1]=dp[i-1][1]+i+1;
		//dp[0][i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
		{
			int x=i+1;
			int y=1;
			x/=2;
			while(y<=i) y<<=1;
			y>>=1;
			int t=y>>1;
		//	t=min(t,x);
			dp[i][j]=dp[x-1][j-1]+dp[i-x][j]+i+1;
			for(int k=max(1,x-5);k<=min(x+5,i);k++)
			dp[i][j]=min(dp[i][j],dp[k-1][j-1]+dp[i-k][j]+i+1);
		}
	while(~scanf("%d%d",&n,&m)){
		double ans=dp[n][m];
		ans/=(n+1);
		printf("%.6f\n",ans);
	}
}
