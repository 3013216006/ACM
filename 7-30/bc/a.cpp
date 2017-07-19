#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[10010];
int main(){
	int n,m,T,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		int sum=0,flag=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			sum+=x;
			sum%=m;
			dp[sum]++;
			if(dp[sum]>=2||sum==0) flag=1;
		}
		if(flag) puts("YES");
			else puts("NO");
	}
}
