#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int vis[1000],ans[1000];
int a[1000];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(vis,0,sizeof(vis));
		memset(ans,-1,sizeof(ans));
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		int flag=1;
		for(int i=0;i<m-1;i++){
			int k=(a[i+1]+n-a[i]);
			if(k>n) k-=n;
			if(ans[a[i]]!=-1){
				if(ans[a[i]]==k) continue;
				else{
					flag=0;
					break;
				}
			}
			if(vis[k]){
				flag=0;
				break;
			}
			ans[a[i]]=k;
			vis[k]=1;
		}
		int l=1;
		if(flag){
		for(int i=1;i<=n;i++)
			if(ans[i]==-1){
				while(vis[l]) l++;
				if(i>1) printf(" ");
				printf("%d",l++);
			}
			else{
				if(i>1) printf(" ");
				printf("%d",ans[i]);
			}
			puts("");
		}
		else puts("-1");
	}
}
