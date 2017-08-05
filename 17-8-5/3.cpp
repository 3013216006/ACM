#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long dp[11][1001];
int a[100001],b[100001],k[1001],p[1001];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
	int mx=0,mx1=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			mx=max(mx,b[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&k[i],&p[i]);
			mx1=max(mx1,p[i]);
		}
		if(mx>=mx1){
			puts("-1");
			continue;
		}
		
		memset(dp,0x3f3f3f3f,sizeof(dp));

		for(int i=0;i<=10;i++){
			dp[i][0]=0;
			for(int j=0;j<m;j++){
				int l=p[j]-i;
				if(l<=0) continue;
				for(int k1=1;k1<=l;k1++)
					dp[i][k1]=min(dp[i][k1],1ll*k[j]);
					
				for(int k1=l;k1<=1000;k1++)
					dp[i][k1]=min(dp[i][k1],dp[i][k1-l]+k[j]);
			}
		}
		for(int i=0;i<=10;i++)
			for(int j=999;j>=1;j--)
				dp[i][j]=min(dp[i][j+1],dp[i][j]);
		long long ans=0;
		for(int i=0;i<n;i++){
			ans+=dp[b[i]][a[i]];
		}
		cout << ans << endl;
	}
}
