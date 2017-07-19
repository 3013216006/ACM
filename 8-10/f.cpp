#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[200],dp[110][210];
int abs(int x){
	if(x<0) return -x;
	return x;
}
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int l=0,r=100,ans=100;
		memset(dp,-1,sizeof(dp));
		while(l<=r){
			int mid=l+r>>1;
			dp[0][0]=mid;
			for(int i=0;i<n;i++)
				for(int j=0;j<=mid;j++)
					if(dp[i][j]==mid){
						dp[i+1][j+a[i]]=mid;
						dp[i+1][abs(j-a[i])]=mid;
					}
			int flag=0;
			for(int i=0;i<=mid;i++)
				if(dp[n][i]==mid) flag=1;
			if(flag) ans=mid,r=mid-1;
				else l=mid+1;
		}
		cout << ans << endl;

	}
}
