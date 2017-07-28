#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int cnt=0;
struct Node{
	int v,next;
}edge[200000];

int head[100010];
int size[100010];
long long ans;
void add(int x,int y){
	edge[cnt].v=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
	edge[cnt].v=x;
	edge[cnt].next=head[y];
	head[y]=cnt++;
}
int n;
void dfs(int x,int fa){
	size[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue;
		dfs(v,x);
		ans+=1ll*(n-size[v])*size[v];
		size[x]+=size[v];
	}
}

int main(){
	int x,y;
	memset(size,0,sizeof(size));
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	ans=0;
	dfs(1,0);
	printf("%lld\n",ans);
}
