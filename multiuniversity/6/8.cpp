#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;
set<int> S[1011];
set<int>::iterator it;
int dp[1111][1111],a[1111];
long long sum[1111];
long long mod=1000000007ll;
int main(){
	int T,n,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&s);
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			S[i].clear();
		}
		S[n].clear();
		S[0].insert(0);
		dp[0][0]=1;
		sort(a,a+n);
		for(int i=n-1;i>=0;i--){
			for(int j=n-i;j>=0;j--)
				for(it=S[j].begin();it!=S[j].end();it++){
					int x=*it,y=x+a[i];
					if(x+a[i]>s) break;
					S[j+1].insert(y);
				//	sum[j+1]+=dp[j][x];
				//	if(sum[j+1]>=mod)
				//	sum[j+1]-=mod;
					dp[j+1][y]+=dp[j][x];
					if(dp[j+1][y]>=mod)
					dp[j+1][y]-=mod;
				}
		}
		long long ans=0;
		for(int i=1;i<n;i++)
			for(it=S[i].begin();it!=S[i].end();it++)
				sum[i]+=dp[i][*it];
		for(int i=2;i<n;i++){
			long long x=n-i,y=i;
			if(x<2) continue;
			sum[i]%=mod;
			ans+=((long long)sum[i])*y%mod*(y-1)%mod*x%mod*(x-1)%mod;
			ans%=mod;
		}
		cout << ans << endl;
	}
}
