#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[1010],b[1010];
long long dp[1010][1010];
long long mod=1000000007ll;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
	//		dp[i][0]=1;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
	//		dp[0][i]=1;
		}
	//	dp[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

				if(a[i]==b[j]) dp[i][j]+=(dp[i-1][j-1]+1);
				dp[i][j]=(dp[i][j]+mod)%mod;
			}
		cout << dp[n][m] << endl;
	}
}
