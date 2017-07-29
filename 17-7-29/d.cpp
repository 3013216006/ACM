#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int ans;
int now;
int vis[600];
struct Node{
	int v,next;
}edge[50000];
int head[1000];
int cnt;
void add(int x,int y){
	edge[cnt].v=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
	edge[cnt].v=x;
	edge[cnt].next=head[y];
	head[y]=cnt++;
}
int n,m;
void dfs(int x){
//	cout << x << endl;
	if(x==n+1){
		ans=min(ans,now);
		return ;
	}
	if(now>=ans) return;
	if(vis[x]){
		dfs(x+1);
		return;
	}
	vis[x]++;
	now++;
	dfs(x+1);
	vis[x]--;
	now--;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(!vis[v]) now++;
		vis[v]++;
	}
	dfs(x+1);
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		vis[v]--;
		if(!vis[v]) now--;
	}
}

int main(){
	int x,y;
	while(~scanf("%d%d",&n,&m)){
		memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		memset(vis,0,sizeof(vis));
		ans=30,now=0;
		dfs(1);
		cout << ans << endl;
	}
}
