#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[2][100010];
int pan(int x,int y){
	if(x>=2){
		if(y>=2){
			x-=2; y-=2;
			int l1=strlen(s[x]);
			int l2=strlen(s[y]);
			int l=min(l1,l2);
			for(int i=1;i<=l;i++){
				if(s[x][l1-i]<s[y][l2-i]) return 1;
				if(s[x][l1-i]>s[y][l2-i]) return 0;
			}
			if(l1==l) return 1;
			return 0;
		}
		else{
			x-=2;
			int l1=strlen(s[x]);
			int l2=strlen(s[y]);
			int l=min(l1,l2);
			for(int i=1;i<=l;i++){
				if(s[x][l1-i]<s[y][i-1]) return 1;
				if(s[x][l1-i]>s[y][i-1]) return 0;
			}
			if(l1==l) return 1;
			return 0;
		}
	}
	else{
		if(y>=2){
			 y-=2;
			int l1=strlen(s[x]);
			int l2=strlen(s[y]);
			int l=min(l1,l2);
			for(int i=1;i<=l;i++){
				if(s[x][i-1]<s[y][l2-i]) return 1;
				if(s[x][i-1]>s[y][l2-i]) return 0;
			}
			if(l1==l) return 1;
			return 0;
		}
		else{
			int l1=strlen(s[x]);
			int l2=strlen(s[y]);
			int l=min(l1,l2);
			for(int i=0;i<l;i++){
				if(s[x][i]<s[y][i]) return 1;
				if(s[x][i]>s[y][i]) return 0;
			}
			if(l1==l) return 1;
			return 0;
		}
	}
}
long long dp[101000][2];
int v[100010];
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		scanf("%s",s[0]);
		dp[0][0]=0;
		dp[0][1]=v[0];
		for(int i=1;i<n;i++){
			scanf("%s",s[i%2]);
			dp[i][0]=-1;
			dp[i][1]=-1;
			int x=i%2,y=x^1;
			if(dp[i-1][0]!=-1&&pan(y,x)){
//				cout << "haha" << endl;
				if(dp[i-1][1]!=-1&&pan(y+2,x)){
					dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
				}
				else{
					dp[i][0]=dp[i-1][0];
				}
			}
			else{
				
				if((dp[i-1][1]!=-1)&&pan(y+2,x)){
					dp[i][0]=dp[i-1][1];
				}
			}
			if(dp[i-1][0]!=-1&&pan(y,x+2)){
				if(dp[i-1][1]!=-1&&pan(y+2,x+2)){
					dp[i][1]=min(dp[i-1][0],dp[i-1][1])+v[i];
				}
				else{
					dp[i][1]=dp[i-1][0]+v[i];
				}
			}
			else{
				if(dp[i-1][1]!=-1&&pan(y+2,x+2)){
					dp[i][1]=dp[i-1][1]+v[i];
				}
			}
		}
		long long ans=dp[n-1][0];
//		cout << dp[1][0] << " " << dp[1][1] << endl;
//		cout << dp[2][0] << " " << dp[2][1] << endl;
		if(ans==-1||(ans>dp[n-1][1]&&dp[n-1][1]!=-1)) ans=dp[n-1][1];
		printf("%lld\n",ans);
	}
}
