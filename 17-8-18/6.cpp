#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf 0x7fffffff
using namespace std;
int vis[33][33],vis1[33],vis2[33][33];
int vis4[33][1<<15];
vector<int> v;
	int n,m,k,x,y;

int dfs(int x,int y){
	if(y==0&&vis4[x][0]!=-1) return vis4[x][y];
	int ret=0;
	if(y==0){
	for(int i=x+1;i<=n;i++)
		if(vis1[i]&&vis2[x][i]){
			 ret=max(ret,dfs(x,1)+1);
		}
	}
	else{
		for(int i=x+1;i<=n;i++)
			if(vis1[i]) ret=max(ret,dfs(x,0));
	}
	return vis4[x][y]=ret;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			vis[x][y]=1;
			vis[y][x]=1;
		}
		memset(vis1,0,sizeof(vis1));
		for(int i=0;i<k;i++){
			scanf("%d",&x);
			vis1[x]=1;
		}
		memset(vis2,0,sizeof(vis2));
		for(int i=1;i<=n;i++)
			if(!vis1[i]){
				v.clear();
				for(int j=1;j<=n;j++)
					if(vis1[j]&&vis[i][j]) v.push_back(j);
				for(int i=0;i<v.size();i++)
					for(int j=i+1;j<v.size();j++){
						vis2[v[i]][v[j]]=1;
						vis2[v[j]][v[i]]=1;
					}
			}
		int ans=0;
		memset(vis4,0,sizeof(vis4));
		for(int i=1;i<=n;i++)
			if(vis1[i])
			     ans=max(ans,dfs(i,0));
		cout << ans << endl;

	}
}
