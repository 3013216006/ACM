#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
long long dp[14][5000];
int a[100];
long long mod=100000000ll;
int pan(int x){
	if(x&(x>>1)) return 0;
	return 1;
}
int x,s[5000],cnt;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int M=1<<m;
		cnt=0;
		for(int i=0;i<M;i++){
			if(pan(i)) s[cnt++]=i;
		}
		for(int i=0;i<n;i++){
			a[i]=0;
			for(int j=0;j<m;j++){
				a[i]=a[i]<<1;
				scanf("%d",&x);
				a[i]+=x;
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<cnt;i++)
			if((a[0]&s[i])==s[i]) dp[0][i]=1; 
		for(int i=1;i<n;i++)
			for(int j=0;j<cnt;j++){
				if((a[i]&s[j])==s[j]){
					for(int k=0;k<cnt;k++)
						if((s[k]&s[j])==0){
							dp[i][j]+=dp[i-1][k];
							dp[i][j]%=mod;
						}
				}
			}
		long long ans=0;
		for(int i=0;i<cnt;i++)
			if((s[i]&a[n-1])==s[i]){
				ans+=dp[n-1][i];
				ans%=mod;
			}
		printf("%lld\n",ans);
	}
}
