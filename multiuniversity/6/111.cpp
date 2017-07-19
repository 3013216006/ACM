#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
int dp[20][20];
int main(){
	memset(dp,0,sizeof(dp));
	int n=10;
	for(int i=1;i<=10;i++)
		dp[0][i]=1;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++){
		//	dp[i][j]=dp[i-1][j];
			int x=1;
			for(int k=0;k<=i;k++){
				if(k) x=x*(i-k+1)/k;
				dp[i][j]+=x*dp[k][j-1];
			}
		}
	for(int i=0;i<=10;i++){
		for(int j=0;j<=10;j++)
			printf("%8d",dp[i][j]);
			puts("");
	}
}
