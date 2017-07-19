#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long dp[30][30][30];
int a[30];
long long n,m;
long long getans(long long xx){
	if(xx==0) return 0;
	int l=0;
	while(xx>0){
		a[l++]=xx%10;
		xx/=10;
	}
	memset(dp,0,sizeof(dp));
	int x=0,y=0;
	for(int i=0,r=0;i<l;i++,r++){
		for(int j=0;j<a[i];j++)
			if(j%2==1)
			dp[i][x][y+1]+=1;
			else dp[i][x+1][y]+=1;
			if(x==0&&y==0) dp[i][1][0]--,dp[i][0][0]++;
		if(i)
		for(int j=0;j<=r;j++)
			for(int k=0;k<=r-j;k++){
				if(dp[i-1][j][k]){
					if(j==0&&k==0) dp[i][j][k]+=1,dp[i][j+1][k]+=dp[i-1][j][k]*4;
					else{
						dp[i][j+1][k]+=dp[i-1][j][k]*5;
					}
					dp[i][j][k+1]+=dp[i-1][j][k]*5;
				}
			}
		if(a[i]%2) y++;else x++;
	}	
	long long ret=0;
	if(x%2==1&&y%2==0) ret++;
	for(int i=0;i<=l;i++)
		for(int j=0;j+i<=l;j++)
			if(i%2==1&&j%2==0)
				ret+=dp[l-1][i][j];
				cout << ret << endl;
	return ret;
		
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		cout << getans(m)-getans(n-1) << endl;
	}
}
