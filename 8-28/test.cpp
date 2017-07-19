#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[2100][2100][3];
char s1[2100],s2[2100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s1,s2);
		int l1=strlen(s1);
		int l2=strlen(s2);
		memset(dp,0,sizeof(dp));
		dp[0][0][1]=2;
		dp[0][0][2]=2;
		for(int i=1;i<=l2;i++){
			dp[0][i][1]=dp[0][i-1][1]+1;
			dp[0][i][0]=dp[0][i][1];
			dp[0][i][2]=dp[0][i][1]+2;
		}
		for(int i=1;i<=l1;i++){
			dp[i][0][0]=2;
			dp[i][0][1]=4;
			dp[i][0][2]=2; 
			for(int j=1;j<=l2;j++){
				if(s1[i-1]==s2[j-1])
					dp[i][j][0]=min(min(dp[i-1][j-1][0],dp[i-1][j-1][1]),dp[i-1][j-1][2]);
				dp[i][j][1]=min(min(dp[i][j-1][1]+1,dp[i][j-1][0]+3),dp[i][j-1][2]+3);
				dp[i][j][2]=min(min(dp[i-1][j][0],dp[i-1][j][1])+2,dp[i-1][j][2]);
				if(s1[i-1]!=s2[j-1])
				dp[i][j][0]=min(dp[i][j][1],dp[i][j][2]);
			}
		}
		printf("%d\n",min(dp[l1][l2][0],min(dp[l1][l2][1],dp[l1][l2][2])));
	}
}
