#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1001];
struct Node{
	int l,x;
}a[1001];
int tmp[2001];
int main(){
	int T,cas=1,n,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=0;i<n;i++){
			int l=-1;
			memset(tmp,0,sizeof(tmp));
			for(int j=0;j<n;j++){
				scanf("%d",&x);
				if(x){
					dp[j]++;
					tmp[j+dp[j]-1]=j;
					ans+=(j-l);
					l=max(tmp[j],l);
				}
				else dp[j]=0,l=j;
				cout << ans << endl;
			}
			
		}
		printf("Case %d:%d\n",cas++,ans);
	}
}
