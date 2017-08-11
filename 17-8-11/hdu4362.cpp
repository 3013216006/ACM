#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int x,y;
}a[55][1100];

bool cmp(Node a,Node b){
	return a.x<b.x;
}

long long dp[55][1100];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,n,x;
		scanf("%d%d%d",&m,&n,&x);
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j].x);
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j].y);
			}
		}
		memset(dp,0x3f3f,sizeof(dp));
		for(int i=0;i<m;i++)
			sort(a[i],a[i]+n,cmp);
		for(int i=0;i<n;i++)
			dp[0][i]=a[0][i].y+abs(a[0][i].x-x);
		for(int i=1;i<m;i++){
			int l=0,ans=-1;
			for(int j=0;j<n;j++){
				while(l<n&&a[i-1][l].x<=a[i][j].x){
					if(ans==-1) ans=l;
					else if(dp[i-1][ans]-a[i-1][ans].x>dp[i-1][l]-a[i-1][l].x) ans=l;
					l++;
				}
				if(ans!=-1)
				dp[i][j]=min(dp[i][j],dp[i-1][ans]+a[i][j].x-a[i-1][ans].x+a[i][j].y);
			}
			l=n-1,ans=-1;
			for(int j=n-1;j>=0;j--){
				while(l>=0&&a[i-1][l].x>=a[i][j].x){
					if(ans==-1) ans=l;
					else if(-a[i-1][ans].x+a[i-1][l].x+dp[i-1][l]<dp[i-1][ans]) ans=l;
					l--;
				}
				if(ans!=-1)
				dp[i][j]=min(dp[i][j],dp[i-1][ans]+a[i-1][ans].x-a[i][j].x+a[i][j].y);
			}
		}
		long long myans=dp[m-1][0];
		for(int i=0;i<n;i++)
			myans=min(myans,dp[m-1][i]);
		cout << myans << endl;

	}
}
