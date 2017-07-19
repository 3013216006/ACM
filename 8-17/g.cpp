#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long dp[100010][300];
long long sum[300];
int a[100010];
char s[10];
int myget(char c){
	if(c<='9') return c-'0';
		else return c-'A'+10;
}

int myscan(){
	scanf("%s",s);
	return myget(s[0])*16+myget(s[1]);
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			a[i]=myscan();
		}
			memset(dp,0,sizeof(dp));
			dp[0][0]=a[0];
			int m=n;
			for(int i=1;i<n;i++){
				dp[i][0]=dp[i-1][0]+(i^a[i]);
				for(int j=1;j<=min(i,260);j++){
					dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]+((i-j)^a[i]));
				}
			}
			long long ans=0;
			for(int i=0;i<=min(n,260);i++){
				ans=max(ans,dp[n-1][i]);
			}
			cout << ans << endl;
	}
}
