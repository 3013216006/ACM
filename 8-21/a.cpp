#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[210][210];
int a[210];
int main(){
	int n,m,T,cas=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a[0]=0;a[n+1]=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			dp[i][i]=a[i-1]+a[i+1];
		for(int l=1;l<n;l++)
			for(int i=1;i+l<=n;i++){
				dp[i][i+l]=min(dp[i+1][i+l],dp[i][i+l-1]);
				for(int j=i+1;j<i+l;j++)
					dp[i][i+l]=min(dp[i][i+l],dp[i][j-1]+dp[j+1][i+l]);
				dp[i][i+l]+=(a[i-1]+a[i+l+1]);
			}
	//	for(int i=1;i<=n;i++){
	//		for(int j=1;j<=n;j++) printf("%6lld",dp[i][j]);
	//		puts("");
	//		}
		printf("Case #%d: %lld\n",cas++,dp[1][n]+sum);
	}
}
