#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[2000],vis[20000];
int main(){
	int n=1000;
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=0;j<i;j++)
			vis[dp[j]]=1;
		for(int j=1;j<=i/3;j++)
			for(int k=1;k<=(i-j)/2;k++)
				vis[dp[j]^dp[k]^dp[i-j-k]]=1;
		dp[i]=0;
		while(vis[dp[i]]) dp[i]++;
	}
	for(int i=0;i<=100;i++)
		cout << i << " " << dp[i] << " " << dp[i]-i<< endl;

}
