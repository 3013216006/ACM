#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Node{
	int num,next;
}edge[400010];
int head[200100],mark[200100],siz[200100];
long long sum[200100];
int cnt;
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].num=y;
	head[x]=cnt++;
	edge[cnt].next=head[y];
	edge[cnt].num=x;
	head[y]=cnt++;
}

void dfs(int x,int f){
	siz[x]=mark[x];
	sum[x]=0;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f) continue;
		dfs(v,x);
		siz[x]+=siz[v];
		sum[x]+=siz[v]+sum[v];
	}
}
long long ans;
void dfs1(int x,int f,int s,int d){
	int tmp=-1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].num;
		if(v==f) continue;
		if((siz[v])*2-d>siz[x]) tmp=v;  
	}
	if(tmp==-1)return;
	ans-=(siz[tmp]-(siz[x]-siz[tmp])-d);
	dfs1(tmp,x,siz[tmp]*2-s,siz[x]-siz[tmp]+d);
}

int main(){
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		memset(mark,0,sizeof(mark));
		m=m<<1;
		for(int i=0;i<m;i++){
			scanf("%d",&x);
			mark[x]=1;
		};
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		dfs(1,0);
		ans=sum[1];
		dfs1(1,0,m,0);
		cout << ans << endl;
	}
}
