#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[2510];
int sum[5010][5010];

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=0;j<m;j++)
				if(s[j]=='1') sum[i][j+1]=1;
		}
		int l=max(n,m)*2;
		for(int i=1;i<=l;i++)
			for(int j=1;j<=l;j++)
				sum[i][j]+=sum[i][j-1];
		for(int j=1;j<=l;j++)
			for(int i=1;i<=l;i++)
				sum[i][j]+=sum[i-1][j];
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				printf("%d ",sum[i][j]);
//			}
//			puts("");
//		}
		int ans=l*l;
		l/=2;
		int xx,yy,p;
		n,m;
		for(int k=2;k<=l;k++){
			int tmp=0;
			int k2=k*k;
			for(int i=0;i<=n;i+=k)
				for(int j=0;j<=m;j+=k){
						xx=i+k;
						yy=j+k;
						p=sum[xx][yy]-sum[i][yy]-sum[xx][j]+sum[i][j];
						tmp+=min(p,k2-p);
				}
			ans=min(ans,tmp);
		}
		cout << ans << endl;
	}
}
