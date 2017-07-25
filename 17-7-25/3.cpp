#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int v,next;
}edge[400100];
int cnt;
long long size[200010],tsize[200010],sum[200010],tmp[200010];
int col[200010],head[200100],fa[200100];
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].v=x;
	head[y]=cnt++;
}
void dfs1(int x,int f){
	fa[x]=f;
	size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==f) continue;
		dfs1(v,x);
		size[x]+=size[v];
	}
	tsize[x]=size[x];
	return;
}
long long ans=0;
int n;
void dfs2(int x){
//	cout << x << ": " << size[x] << "*" << (n-size[x]-sum[col[x]]) << endl; 
	ans+=size[x]*(n-size[x]-sum[col[x]]);
	tmp[x]=sum[col[x]];
	sum[col[x]]=n-size[x]+1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa[x]) continue;
		sum[col[x]]=n-size[v];
		dfs2(v);
		tsize[x]-=size[v];
//		cout << x << "2: " << tsize[x] << "*" << size[v] << endl;
		ans+=tsize[x]*size[v];
	}
	sum[col[x]]=tmp[x]+size[x];
}

int main(){
	int x,y,cas=1;
	while(~scanf("%d",&n)){
		memset(head,-1,sizeof(head));
		cnt=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
			scanf("%d",&col[i]);
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		dfs1(1,0);
		ans=0;
		dfs2(1);
		printf("Case #%d: %lld\n",cas++,ans);
//		cout << ans << endl;
	}
}
