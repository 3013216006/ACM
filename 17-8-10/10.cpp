#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int son[552][2],siz[550],ty[550];
struct Node{
	int v,next;
}edge[500];
int head[550];
int tmax[550],tmax1[550];
int cnt;
int flag;
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
}
int dfs(int x){
	int ret=0;
	son[x][0]=son[x][1]=0;
	siz[x];
	tmax[x]=0;
	tmax1[x]=0;
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(flag) return 0;
		int v=edge[i].v;
		ret=max(ret,dfs(v));
		if(ty[v]){
			tmax1[x]=max(tmax1[x],siz[v]);
			son[x][1]++;
		}
		else{
			tmax[x]=max(tmax[x],siz[v]);
			son[x][0]++;
		}
	}
	if(son[x][1]>1) flag=1;
	else{
		if(son[x][1]){
			ty[x]=0;
			siz[x]=tmax1[x]+1;
		}
		else{
			ty[x]=1;
			siz[x]=tmax[x]+1;
		}
	}
	if(x==1&&son[x][1]==0) flag=1;
	return max(ret,(tmax[x]+tmax1[x]-1)/2);
}

int main(){
	int T;
	int x,k;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=2;i<=n;i++){
			scanf("%d",&x);
			add(x,i);
		}
		flag=0;
		int tp=dfs(1);
		if(flag||(n-2)/2>k) puts("Alice");
		else puts("Bob");
	}
}
