#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Node{
	int v,next;
}edge[10000];

int cnt;
int n,m;
int head[10000];
void add(int x,int y){
	edge[cnt].next=head[x];
	edge[cnt].v=y;
	head[x]=cnt++;
}
bool vis[10000];
int match[10000];
bool find(int x){
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(vis[i]) continue;
		int v=edge[i].v;
		vis[i]=1;
		if(!match[v]||find(match[v])){
			match[v]=x;
			return true;
		}
	}
	return false;
}

int work(){
	int ret=0;
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(find(i+1)) ret++;
	}
	return ret;
}

int main(){
	int x,y;
	while(scanf("%d%d",&n,&m)){
		memset(head,-1,sizeof(head));
		memset(match,0,sizeof(match));
		cnt=0;
		if(n==-1&&m==-1) break;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			if(x>n) swap(x,y);
			add(x,y);
		}
		int ans=work();
		if(ans==0){
			puts("No Solution!");
		}
		printf("%d\n",ans);
		for(int i=n;i<=m;i++)
			if(match[i])
				printf("%d %d\n",match[i],i);

	}
}
