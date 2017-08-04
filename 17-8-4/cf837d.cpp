#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[2][202][18*200+1];
int a[201],b[201],c[201],d[201];
int main(){
	long long x;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			cin >> x;
			while(x%5==0) x/=5,a[i]++;
			while(x%2==0) x/=2,b[i]++;
			c[i]=a[i],d[i]=b[i];
		}
		sort(c,c+n);
		sort(d,d+n);
		int l1=0,l2=0;
		for(int i=1;i<=m;i++){
			l1+=c[n-i];
			l2+=d[n-i];
		}
		int l=min(18*200,min(l1,l2));
		memset(dp,-1,sizeof(dp));
		dp[0][0][0]=0;
		dp[1][0][0]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<=l;k++){
					if(dp[i%2][j][k]==-1) continue;
					
					int s=i&1,t=s^1;
					dp[t][j][k]=max(dp[t][j][k],dp[s][j][k]);
					dp[t][j+1][min(k+a[i],l)]=max(dp[t][j+1][min(k+a[i],l)],dp[s][j][k]+b[i]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<2;i++){
			for(int k=ans+1;k<=l;k++){
				ans=max(ans,min(dp[i][m][k],k));
			}
		}
		cout << ans << endl;
	}
}
