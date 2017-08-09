#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long dp[2010][1010];
int a[2010],b[2010],c[2010];

int abs(int x){
	if(x<0) return -x;
	else return x;
}

int main(){
	int n,k,p;
	while(~scanf("%d%d%d",&n,&k,&p)){
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=k;i++) scanf("%d",&b[i]);
		sort(b+1,b+1+k);
		for(int i=1;i<=k;i++) c[i]=abs(b[i]-p);
		memset(dp,0x3f3f3f3f,sizeof(dp));
		for(int i=0;i<=k;i++)
			dp[i][0]=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=min(n,i);j++){
				dp[i][j]=min(dp[i-1][j],max(dp[i-1][j-1],(long long)abs(a[j]-b[i])+c[i]));
			}
		}
		cout << dp[k][n] << endl;
	}
}
