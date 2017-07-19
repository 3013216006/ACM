#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,a[50][50],b[50][50];
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n==0) break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&b[i][j]);
				ans+=(a[i][j]==b[i][j]);
			}
		int tmp=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				tmp+=(a[i][j]==b[n-j-1][i]);
		ans=max(tmp,ans);
		tmp=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				tmp+=(a[i][j]==b[n-i-1][n-j-1]);
			}
		ans=max(tmp,ans);
		tmp=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				tmp+=(a[i][j]==b[j][n-i-1]);		
			}
		ans=max(ans,tmp);
		printf("%d\n",ans);
	}
}
