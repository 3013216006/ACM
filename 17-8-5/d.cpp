#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[77],b[77],c[140*70];


long long getans(long long h,long long h1,long long s){
		long long tmp=abs(h-h1);
		return tmp*s;
}

long long getans2(long long h,long long h1,long long s){
	if(h>h1) return 0;
	else return (h1-h)*s;
}

long long dp[71][71][140*71];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int l=0;
		c[l++]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i],&b[i]);
			for(int j=0;j<n;j++){
				if(a[i]-j>0)
				c[l++]=a[i]-j;
				c[l++]=a[i]+j;
			}
		}
		sort(c,c+l);
		l=unique(c,c+l)-c;
		memset(dp,0x3f3f3f3f,sizeof(dp));
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				long long mnnow=dp[0][1][0];
				for(int k=0;k<l;k++){
					dp[i][j][k]=min(dp[i-1][j][k]+getans2(c[k],a[i],b[i]),mnnow+getans(c[k],a[i],b[i])),
					mnnow=min(mnnow,dp[i-1][j-1][k]);
				}
			}
		}
		long long ans=dp[0][1][0];
		for(int x=m;x<=n;x++)
		for(int i=0;i<l;i++)
			ans=min(ans,dp[n][x][i]);
		cout << ans << endl;
	}
	
}
