#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[600];
int vis[600],flag[600];
int  dfs(int x){
	if(flag[x]) return 0;
	flag[x]=1;
	for(int i=0;i<v[x].size();i++){
		int V=v[x][i];
		if(vis[V]){
			if(dfs(vis[V])){
				vis[V]=x;
				return 1;
			}
		}
		else {
			vis[V]=x;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n,m;
	int x,y;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ans=0;
		memset(vis,0,sizeof(flag));
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof(flag));
			if(dfs(i)) ans++;
		}
		cout << ans/2 << endl;
	}
}
