#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dep[300010],vis[300010];
int head[300010];
int fa[300010];
int a[300010];
int ans[300010];
int x,y;
vector<int> dp[300010];
vector<pair<int,int> > v[300010];
struct Node{
	int v,next;
}edge[600010];
int cnt;

void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].v=x;
	head[y]=cnt++;
}

void add2(int x,int y){
	fa[y]=x;
}

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void dfs(int x,int d){
	dep[x]=d;
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int V=edge[i].v;
		if(vis[V]) continue;
		dfs(V,d+1);
		add2(x,V);
	}
	for(int i=0;i<v[x].size();i++){
//		cout << v[x][i].first << " " << v[x][i].second << endl;
		if(vis[v[x][i].first]) ans[v[x][i].second]=dep[find(v[x][i].first)];
	}
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			v[i].clear();
			fa[i]=i;
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		for(int i=1;i<n;i++){
			v[a[i]].push_back(make_pair(a[i+1],i));
			v[a[i+1]].push_back(make_pair(a[i],i));
		}
		memset(vis,0,sizeof(vis));
		dfs(1,1);
//		for(int i=1;i<n;i++)
//			cout << ans[i] << endl;
		for(int i=0;i<=n;i++){
			dp[i].resize(m+1);
			for(int j=0;j<=m;j++){
				dp[i][j]=0x3f3f3f3f;
			}
		}
		for(int i=0;i<=n;i++)
			dp[i][0]=0;
		for(int k=1;k<=m;k++){
			for(int i=k;i<=n;i++){
				dp[i][k]=min(dp[i-1][k],dp[i-1][k-1]+dep[a[i]]);
				if(i>=2)
				dp[i][k]=min(dp[i][k],dp[i-2][k-1]+ans[i-1]);
//				cout << i << " " << k << " " << dp[i][k] << endl;
			}
		}
		cout << dp[n][m] << endl;
	}
}
