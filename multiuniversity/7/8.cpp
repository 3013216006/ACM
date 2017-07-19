#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
long long dp1[21][21];
int a[22];
void getans(int x){
	int l=0,r=0;
	while(x){
		if(x&1){
			r++;
		}
		a[l++]=x%2;
		x/=2;
	}
	x=0;
	int y=0;
	int r1=l;
	l--;
	while(l>=0){
		if(a[l]==1) x++;
			else y++;
		l--;
		if(x+1==y) break;
	}
	if(l<0) dp1[r][r1]++;
}
long long p[22][22],dp[1001][22];
int main(){
	memset(dp1,0,sizeof(dp1));
	int l=1<<20;
	for(int i=1;i<l;i++)
		getans(i);
	dp1[0][1]=1;
	for(int i=0;i<=20;i++){
		p[i][0]=1;
		for(int j=1;j<=i;j++)
			p[i][j]=p[i][j-1]*(i-j+1);
	}
	int T,n,m,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&k,&n,&m);
		int sum=1;
		for(int i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		int l=min(n+1,m);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<m;i++){
			int tj=min(i+1,l);
			for(int j=tj;j>=0;j--)
				for(int q=0;q<=k;q++)
					if(dp[q][j])
					dp[min(q+a[i],k)][j+1]+=dp[q][j];
		}
		long long ans1=0,ans2=0;
		for(int i=0;i<=n;i++){
			int r=i*2+1;
			r=min(r,n+m);
			ans2+=dp1[i][r]*dp[k][r-i]*p[n+m-r][m-r+i]*p[r-i][r-i];
		}
		ans1=p[n+m][m];
		long long d=__gcd(ans1,ans2);
		ans1/=d;
		ans2/=d;
		cout << ans2 << "/" << ans1 << endl;
	}
}
